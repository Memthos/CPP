#include "Array.hpp"

int main() {
	// Test default constructor
	Array<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;

	// Test size constructor
	Array<int> arr(5);
	std::cout << "Size: " << arr.size() << std::endl;

	// Test element access
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 2;

	// Test copy
	Array<int> copy(arr);
	arr[0] = 100;
	std::cout << "arr[0]: " << arr[0] << std::endl;
	std::cout << "copy[0]: " << copy[0] << std::endl;  // Should be 0

	// Test bounds checking
	try {
		arr[100] = 42;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
