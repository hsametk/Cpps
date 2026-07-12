#include "Span.hpp"

int main(){
    std::cout << "=== Test 1: Basic functionality with 5 numbers ===" << std::endl;
    Span sp(5);
    sp.addNumber(5);
    sp.addNumber(10);
    sp.addNumber(20);
    sp.addNumber(25);
    sp.addNumber(55);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    std::cout << "\n=== Test 2: Exception when adding to full Span ===" << std::endl;
    try {
        sp.addNumber(100);
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Exception with empty Span ===" << std::endl;
    Span sp2(10);
    try {
        sp2.shortestSpan();
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Exception with only 1 element ===" << std::endl;
    Span sp3(10);
    sp3.addNumber(42);
    try {
        sp3.longestSpan();
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Using addNumbers() with vector iterators (100 numbers) ===" << std::endl;
    Span sp5(100);
    std::vector<int> vec5;
    for (int i = 0; i < 100; ++i) {
        vec5.push_back(i * 10);
    }
    sp5.addNumbers(vec5.begin(), vec5.end());
    std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp5.longestSpan() << std::endl;

    std::cout << "\n=== Test 6: Large scale test with 10,000 random numbers ===" << std::endl;
    srand(time(0));
    Span largeSp(10000);
    std::vector<int> largeVec;
    
    for (unsigned int i = 0; i < 10000; ++i) {
        largeVec.push_back(rand() % 100000);
    }
    largeSp.addNumbers(largeVec.begin(), largeVec.end());
    
    std::cout << "Added 10,000 random numbers" << std::endl;
    std::cout << "Shortest span: " << largeSp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSp.longestSpan() << std::endl;

    std::cout << "\n=== Test 7: Very large scale test with 50,000 numbers ===" << std::endl;
    Span veryLargeSp(50000);
    std::vector<int> veryLargeVec;
    
    for (unsigned int i = 0; i < 50000; ++i) {
        veryLargeVec.push_back(rand() % 1000000);
    }
    veryLargeSp.addNumbers(veryLargeVec.begin(), veryLargeVec.end());
    
    std::cout << "Added 50,000 random numbers" << std::endl;
    std::cout << "Shortest span: " << veryLargeSp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << veryLargeSp.longestSpan() << std::endl;

    std::cout << "\n=== Test 8: Using addNumbers() with list (different iterator type) ===" << std::endl;
    Span sp8(1000);
    std::list<int> listData;
    for (int i = 0; i < 1000; ++i) {
        listData.push_back(i * 2);
    }
    sp8.addNumbers(listData.begin(), listData.end());
    std::cout << "Shortest span: " << sp8.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp8.longestSpan() << std::endl;

    std::cout << "\n=== Test 9: Edge case with 2 numbers ===" << std::endl;
    Span sp9(2);
    sp9.addNumber(100);
    sp9.addNumber(105);
    std::cout << "Shortest span: " << sp9.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp9.longestSpan() << std::endl;

    std::cout << "\n=== Test 10: Negative numbers ===" << std::endl;
    Span sp10(6);
    int negArr[] = {-50, -20, 0, 10, 30, 100};
    std::vector<int> negVec(negArr, negArr + sizeof(negArr) / sizeof(negArr[0]));
    sp10.addNumbers(negVec.begin(), negVec.end());
    std::cout << "Shortest span: " << sp10.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp10.longestSpan() << std::endl;

    return 0;
}
