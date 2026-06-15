#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <exception>
# include "stddef.h"

template <typename T>
class	Array {
	private:
		T				*_data;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int nb);
		Array(const Array &input);
		Array&	operator=(const Array &input);
		~Array();
		const T&	operator[](const unsigned int index) const;
		T&	operator[](const unsigned int index);
		unsigned int	size() const;

		class	OutOfRange : public std::exception {
			public:
				const char*	what() const throw();
		};
};

# include "Array.tpp"

#endif
