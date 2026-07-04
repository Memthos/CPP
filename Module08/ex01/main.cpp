#include <iostream>
#include <cstdlib>
#include "Span.hpp"

int main() {
    // Basic test from subject
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;  // 2
    std::cout << "Longest: " << sp.longestSpan() << std::endl;    // 14

    // Test exceptions
    try {
        sp.addNumber(42);  // Should throw - full
    } catch (std::exception& e) {
        std::cout << "Full: " << e.what() << std::endl;
    }

    Span empty(5);
    try {
        empty.shortestSpan();  // Should throw - not enough
    } catch (std::exception& e) {
        std::cout << "Empty: " << e.what() << std::endl;
    }

    // Large test (10,000+ numbers)
    Span big(10000);
    std::vector<int> manyNumbers;
    for (int i = 0; i < 10000; i++) {
        manyNumbers.push_back(i);
    }
    big.addNumber(manyNumbers.begin(), manyNumbers.end());

    std::cout << "Big shortest: " << big.shortestSpan() << std::endl;  // 1
    std::cout << "Big longest: " << big.longestSpan() << std::endl;    // 9999

    return 0;
}
