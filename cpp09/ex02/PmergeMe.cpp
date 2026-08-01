#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <climits>
#include <string>
#include <sys/time.h>

// ---------------------------------------------------------------------------
// Orthodox Canonical Form
// ---------------------------------------------------------------------------

PmergeMe::PmergeMe() : _n(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _n(other._n) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
        _n = other._n;
    return *this;
}

PmergeMe::~PmergeMe() {}

// ---------------------------------------------------------------------------
// Argument parsing / validation
// ---------------------------------------------------------------------------

std::vector<int> PmergeMe::parseArgs(int argc, char **argv) const
{
    std::vector<int> result;

    for (int i = 1; i < argc; i++)
    {
        std::string token(argv[i]);
        if (token.empty())
            throw std::runtime_error("empty argument");

        size_t start = 0;
        if (token[0] == '+')
            start = 1;
        if (start == token.size())
            throw std::runtime_error("no digits");

        for (size_t j = start; j < token.size(); j++)
        {
            if (!std::isdigit(static_cast<unsigned char>(token[j])))
                throw std::runtime_error("not a digit"); // also rejects a leading '-'
        }

        errno = 0;
        char *end = 0;
        long value = std::strtol(token.c_str(), &end, 10); // wider than int so overflow is checked before narrowing
        if (errno == ERANGE || value > static_cast<long>(INT_MAX))
            throw std::runtime_error("out of range");

        result.push_back(static_cast<int>(value));
    }

    if (result.empty())
        throw std::runtime_error("no numbers given");

    return result;
}

// ---------------------------------------------------------------------------
// Jacobsthal insertion order
// ---------------------------------------------------------------------------
// Given "pairCount" pending elements a1..a_pairCount (a1 already placed for
// free), returns the 1-based indices of a2..a_pairCount in the order they
// must be inserted into the chain. This order comes from the Jacobsthal
// numbers (1, 3, 5, 11, 21, 43, ...), where J(k) = J(k-1) + 2*J(k-2).
// Within each block ]J(k-1), J(k)] the indices are visited in DESCENDING
// order. This ordering keeps every binary search as wide as possible for
// as long as possible, which is what minimizes the total comparison count.

std::vector<int> PmergeMe::jacobsthalOrderVec(size_t pairCount) const
{
    std::vector<int> order;
    if (pairCount < 2)
        return order; // only a1 exists, nothing left to insert

    std::vector<int> jac;
    jac.push_back(1);
    jac.push_back(3);
    while (jac[jac.size() - 1] < static_cast<int>(pairCount))
    {
        size_t s = jac.size();
        jac.push_back(jac[s - 1] + 2 * jac[s - 2]);
    }

    std::vector<bool> used(pairCount + 1, false);
    used[1] = true;

    int prevBound = 1;
    for (size_t k = 1; k < jac.size(); k++)
    {
        int bound = jac[k];
        if (bound > static_cast<int>(pairCount))
            bound = static_cast<int>(pairCount);

        for (int m = bound; m > prevBound; m--)
        {
            if (!used[m])
            {
                order.push_back(m);
                used[m] = true;
            }
        }
        prevBound = jac[k];
        if (jac[k] >= static_cast<int>(pairCount))
            break;
    }

    for (int m = 2; m <= static_cast<int>(pairCount); m++) // safety net
    {
        if (!used[m])
            order.push_back(m);
    }
    return order;
}

// ---------------------------------------------------------------------------
// std::vector recursive merge-insert (Ford-Johnson)
// ---------------------------------------------------------------------------

// Index of the first chain slot whose value is >= "value", searched only
// within [0, hi). Shared by both the pending-element and straggler inserts.
size_t PmergeMe::vecBinaryInsertPos(const std::vector<int> &vals, int value, size_t hi)
{
    size_t lo = 0;
    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (vals[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

// Position of "identity" inside the chain, used to bound the search for its
// still-pending small partner.
size_t PmergeMe::vecIndexOfId(const std::vector<int> &ids, int identity)
{
    for (size_t j = 0; j < ids.size(); j++)
    {
        if (ids[j] == identity)
            return j;
    }
    return ids.size();
}

void PmergeMe::vectorRecSort(std::vector<int> &vals, std::vector<int> &ids)
{
    size_t n = vals.size();

    // Base case: 0 or 1 element is trivially sorted.
    if (n <= 1)
        return;

    // Step 1: if the count is odd, set the last element aside as the
    // "straggler". It is not part of any pair, and gets inserted last.
    bool odd = (n % 2 != 0);
    int stragVal = 0, stragId = 0;
    if (odd)
    {
        stragVal = vals.back();
        stragId = ids.back();
        vals.pop_back();
        ids.pop_back();
        n--;
    }

    // Step 2: group the remaining elements into consecutive pairs.
    // The bigger of each pair goes into "larges" (they will form the main
    // chain), the smaller goes into "smalls" (pending, inserted later).
    size_t pairCount = n / 2;
    std::vector<int> larges(pairCount), largeIds(pairCount);
    std::vector<int> smalls(pairCount), smallIds(pairCount);

    // pairOfLarge[identity] = pair index that a given large element's
    // identity belongs to, so we can retrieve its attached small later.
    std::vector<int> pairOfLarge(_n, -1);

    for (size_t i = 0; i < pairCount; i++)
    {
        int v1 = vals[2 * i], id1 = ids[2 * i];
        int v2 = vals[2 * i + 1], id2 = ids[2 * i + 1];
        if (v1 > v2)
        {
            larges[i] = v1; largeIds[i] = id1;
            smalls[i] = v2; smallIds[i] = id2;
        }
        else
        {
            larges[i] = v2; largeIds[i] = id2;
            smalls[i] = v1; smallIds[i] = id1;
        }
        pairOfLarge[largeIds[i]] = static_cast<int>(i);
    }

    // Step 3: recursively sort the "larges" only. Identities travel with
    // them, so after this call we still know which small belongs to which.
    vectorRecSort(larges, largeIds);

    // Step 4: the recursively sorted larges become the starting main chain.
    std::vector<int> chainVals(larges);
    std::vector<int> chainIds(largeIds);

    // Step 5: insert, for free, the small attached to chain[0] at the very
    // front. No comparison is needed: it is smaller than its own partner,
    // and its partner is already the smallest value in the chain.
    int firstPairIdx = pairOfLarge[chainIds[0]];
    chainVals.insert(chainVals.begin(), smalls[firstPairIdx]);
    chainIds.insert(chainIds.begin(), smallIds[firstPairIdx]);

    // Step 6: compute the Jacobsthal insertion order for the remaining
    // pending elements (a2..a_pairCount).
    std::vector<int> order = jacobsthalOrderVec(pairCount);

    // Step 7: insert every remaining pending element, in that order. Each
    // element a_rank is only ever searched among chain positions BEFORE
    // its own large partner's current position (it is known to be smaller).
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t rank = static_cast<size_t>(order[k]) - 1; // order is 1-based
        int largeIdentity = largeIds[rank];
        int pairIdx = pairOfLarge[largeIdentity];
        int value = smalls[pairIdx];
        int identity = smallIds[pairIdx];

        size_t bound = vecIndexOfId(chainIds, largeIdentity);
        size_t lo = vecBinaryInsertPos(chainVals, value, bound);
        chainVals.insert(chainVals.begin() + lo, value);
        chainIds.insert(chainIds.begin() + lo, identity);
    }

    // Step 8: the straggler (if any) is binary-inserted last, searching
    // the whole chain since it has no partner to bound the search.
    if (odd)
    {
        size_t lo = vecBinaryInsertPos(chainVals, stragVal, chainVals.size());
        chainVals.insert(chainVals.begin() + lo, stragVal);
        chainIds.insert(chainIds.begin() + lo, stragId);
    }

    // Step 9: hand the fully sorted chain back to the caller.
    vals = chainVals;
    ids = chainIds;
}

std::vector<int> PmergeMe::vectorSort(const std::vector<int> &input)
{
    _n = input.size();
    std::vector<int> vals(input);
    std::vector<int> ids(_n);
    for (size_t i = 0; i < _n; i++)
        ids[i] = static_cast<int>(i);
    vectorRecSort(vals, ids);
    return vals;
}

// ---------------------------------------------------------------------------
// std::deque recursive merge-insert (Ford-Johnson)
// ---------------------------------------------------------------------------
// Identical logic to the std::vector version above, rewritten independently
// on top of std::deque, as required by the subject.

std::deque<int> PmergeMe::jacobsthalOrderDeq(size_t pairCount) const
{
    std::deque<int> order;
    if (pairCount < 2)
        return order;

    std::deque<int> jac;
    jac.push_back(1);
    jac.push_back(3);
    while (jac[jac.size() - 1] < static_cast<int>(pairCount))
    {
        size_t s = jac.size();
        jac.push_back(jac[s - 1] + 2 * jac[s - 2]);
    }

    std::deque<bool> used(pairCount + 1, false);
    used[1] = true;

    int prevBound = 1;
    for (size_t k = 1; k < jac.size(); k++)
    {
        int bound = jac[k];
        if (bound > static_cast<int>(pairCount))
            bound = static_cast<int>(pairCount);

        for (int m = bound; m > prevBound; m--)
        {
            if (!used[m])
            {
                order.push_back(m);
                used[m] = true;
            }
        }
        prevBound = jac[k];
        if (jac[k] >= static_cast<int>(pairCount))
            break;
    }

    for (int m = 2; m <= static_cast<int>(pairCount); m++)
    {
        if (!used[m])
            order.push_back(m);
    }
    return order;
}

size_t PmergeMe::deqBinaryInsertPos(const std::deque<int> &vals, int value, size_t hi)
{
    size_t lo = 0;
    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (vals[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

size_t PmergeMe::deqIndexOfId(const std::deque<int> &ids, int identity)
{
    for (size_t j = 0; j < ids.size(); j++)
    {
        if (ids[j] == identity)
            return j;
    }
    return ids.size();
}

void PmergeMe::dequeRecSort(std::deque<int> &vals, std::deque<int> &ids)
{
    size_t n = vals.size();

    if (n <= 1)
        return;

    bool odd = (n % 2 != 0);
    int stragVal = 0, stragId = 0;
    if (odd)
    {
        stragVal = vals.back();
        stragId = ids.back();
        vals.pop_back();
        ids.pop_back();
        n--;
    }

    size_t pairCount = n / 2;
    std::deque<int> larges(pairCount), largeIds(pairCount);
    std::deque<int> smalls(pairCount), smallIds(pairCount);
    std::deque<int> pairOfLarge(_n, -1);

    for (size_t i = 0; i < pairCount; i++)
    {
        int v1 = vals[2 * i], id1 = ids[2 * i];
        int v2 = vals[2 * i + 1], id2 = ids[2 * i + 1];
        if (v1 > v2)
        {
            larges[i] = v1; largeIds[i] = id1;
            smalls[i] = v2; smallIds[i] = id2;
        }
        else
        {
            larges[i] = v2; largeIds[i] = id2;
            smalls[i] = v1; smallIds[i] = id1;
        }
        pairOfLarge[largeIds[i]] = static_cast<int>(i);
    }

    dequeRecSort(larges, largeIds);

    std::deque<int> chainVals(larges);
    std::deque<int> chainIds(largeIds);

    int firstPairIdx = pairOfLarge[chainIds[0]];
    chainVals.insert(chainVals.begin(), smalls[firstPairIdx]);
    chainIds.insert(chainIds.begin(), smallIds[firstPairIdx]);

    std::deque<int> order = jacobsthalOrderDeq(pairCount);

    for (size_t k = 0; k < order.size(); k++)
    {
        size_t rank = static_cast<size_t>(order[k]) - 1;
        int largeIdentity = largeIds[rank];
        int pairIdx = pairOfLarge[largeIdentity];
        int value = smalls[pairIdx];
        int identity = smallIds[pairIdx];

        size_t bound = deqIndexOfId(chainIds, largeIdentity);
        size_t lo = deqBinaryInsertPos(chainVals, value, bound);
        chainVals.insert(chainVals.begin() + lo, value);
        chainIds.insert(chainIds.begin() + lo, identity);
    }

    if (odd)
    {
        size_t lo = deqBinaryInsertPos(chainVals, stragVal, chainVals.size());
        chainVals.insert(chainVals.begin() + lo, stragVal);
        chainIds.insert(chainIds.begin() + lo, stragId);
    }

    vals = chainVals;
    ids = chainIds;
}

std::deque<int> PmergeMe::dequeSort(const std::deque<int> &input)
{
    _n = input.size();
    std::deque<int> vals(input);
    std::deque<int> ids(_n);
    for (size_t i = 0; i < _n; i++)
        ids[i] = static_cast<int>(i);
    dequeRecSort(vals, ids);
    return vals;
}

// ---------------------------------------------------------------------------
// Orchestration: parse, sort with both containers, time, display
// ---------------------------------------------------------------------------

void PmergeMe::run(int argc, char **argv)
{
    // 1. Parse & validate every argument into a plain list of positive numbers.
    std::vector<int> input = parseArgs(argc, argv);

    // 2. Display the unsorted sequence.
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;

    // 3. Sort using std::vector, timing the full operation (data setup + sort).
    struct timeval t0, t1;
    gettimeofday(&t0, NULL);
    std::vector<int> vecInput(input.begin(), input.end());
    std::vector<int> vecSorted = vectorSort(vecInput);
    gettimeofday(&t1, NULL);
    double vecTime = (t1.tv_sec - t0.tv_sec) * 1000000.0 + (t1.tv_usec - t0.tv_usec);

    // 4. Sort using std::deque, timing the full operation the same way.
    gettimeofday(&t0, NULL);
    std::deque<int> deqInput(input.begin(), input.end());
    std::deque<int> deqSorted = dequeSort(deqInput);
    gettimeofday(&t1, NULL);
    double deqTime = (t1.tv_sec - t0.tv_sec) * 1000000.0 + (t1.tv_usec - t0.tv_usec);

    // 5. Display the sorted sequence (both containers produced the same result).
    std::cout << "After: ";
    for (size_t i = 0; i < vecSorted.size(); i++)
        std::cout << vecSorted[i] << " ";
    std::cout << std::endl;

    // 6. Display timings for each container.
    std::cout << "Time to process a range of " << input.size()
               << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << input.size()
               << " elements with std::deque : " << deqTime << " us" << std::endl;
}
