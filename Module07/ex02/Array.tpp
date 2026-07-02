#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int nb) : _size(nb) {
	_data = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array &input) : _data(NULL), _size(0) {
	*this = input;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T> &input) {
	if (this != &input) {
		delete[] _data;
		_size = input._size;
		_data = new T[_size]();
		for (size_t i = 0; i < _size; i++) {
			_data[i] = input._data[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _data;
}

template <typename T>
const T	&Array<T>::operator[](const unsigned int index) const {
	if (index >= _size)
		throw OutOfRange();
	return (_data[index]);
}

template <typename T>
T	&Array<T>::operator[](const unsigned int index) {
	if (index >= _size)
		throw OutOfRange();
	return (_data[index]);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (_size);
}

template <typename T>
const char *Array<T>::OutOfRange::what() const throw()
{
	return "Index out of range";
}
