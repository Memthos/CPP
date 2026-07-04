#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>

class Span {
	private:
		std::vector<int>	_container;
		unsigned int		_size;
	public:
		Span(int N);
		Span(const Span &input);
		Span&	operator=(const Span &input);
		~Span();
		void	addNumber(int nb);
		template <typename I>
		void	addNumber(I begin, I end) {
			while (begin != end) {
				addNumber(*begin);
				++begin;
			}
		}
		int		shortestSpan(void);
		int		longestSpan(void);
		class	SpanIsFull : public std::exception {
			public:
				const char*	what() const throw();
		};
		class	NotEnoughNumbers : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif
