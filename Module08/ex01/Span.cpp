# include "Span.hpp"

Span::Span(int N) : _size(N) {}

Span::Span(const Span &input) {
	*this = input;
}

Span&	Span::operator=(const Span &input) {
	if (this != &input) {
		this->_size = input._size;
		this->_container = input._container;
	}
	return (*this);
}

Span::~Span() {}

const char*	Span::NotEnoughNumbers::what() const throw() {
	return ("Span doesn't contain enough numbers");
}

const char*	Span::SpanIsFull::what() const throw() {
	return ("Span is already full");
}

void	Span::addNumber(int nb) {
	if (_container.size() == _size)
		throw SpanIsFull();
	_container.push_back(nb);
}

int	Span::shortestSpan(void) {
	if (_container.size() < 2)
		throw NotEnoughNumbers();

	std::vector<int>	sorted = _container;
	std::sort(sorted.begin(), sorted.end());
	
	int	minSpan = (sorted[1] - sorted[0]);
	for (size_t i = 2 ; i < sorted.size() ; i++) {
		if (sorted[i] - sorted[i - 1] < minSpan)
			minSpan = sorted[i] - sorted[i - 1];
	}
	return (minSpan);
}

int	Span::longestSpan(void) {
	if (_container.size() < 2)
		throw NotEnoughNumbers();
	
	int	min = *std::min_element(_container.begin(), _container.end());
	int	max = *std::max_element(_container.begin(), _container.end());

	return (max - min);
}
