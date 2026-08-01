#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
private:
    size_t _n; // total element count of the current top-level call (used to size lookup tables)

    // ---------- std::vector implementation of Ford-Johnson (merge-insert sort) ----------
    // vals  : the values currently being sorted at this recursion level
    // ids   : parallel array, ids[i] is the ORIGINAL index (identity) of vals[i]
    //         identities never change, they just travel along so we can always
    //         find "which small value belongs to which large value" after the
    //         large group gets reordered by recursion.
    void vectorRecSort(std::vector<int> &vals, std::vector<int> &ids);
    std::vector<int> jacobsthalOrderVec(size_t pairCount) const;
    std::vector<int> vectorSort(const std::vector<int> &input);
    static size_t vecBinaryInsertPos(const std::vector<int> &vals, int value, size_t hi);
    static size_t vecIndexOfId(const std::vector<int> &ids, int identity);

    // ---------- std::deque implementation of Ford-Johnson (merge-insert sort) ----------
    // exact same algorithm as above, written again independently for std::deque,
    // as requested by the subject (no generic/templated shared function).
    void dequeRecSort(std::deque<int> &vals, std::deque<int> &ids);
    std::deque<int> jacobsthalOrderDeq(size_t pairCount) const;
    std::deque<int> dequeSort(const std::deque<int> &input);
    static size_t deqBinaryInsertPos(const std::deque<int> &vals, int value, size_t hi);
    static size_t deqIndexOfId(const std::deque<int> &ids, int identity);

    std::vector<int> parseArgs(int argc, char **argv) const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run(int argc, char **argv);
};

#endif
