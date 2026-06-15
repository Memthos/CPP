#include <iostream>
#include "iter.hpp"

template <typename T>
void	print(T const &elem) {
	std::cout << elem << std::endl;
}

template <typename T>
void	increment(T &elem) {
	elem++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << "Original:" << std::endl;
    iter(arr, 5, print<int>);

    iter(arr, 5, increment<int>);

    std::cout << "After increment:" << std::endl;
    iter(arr, 5, print<int>);

    return 0;
}
