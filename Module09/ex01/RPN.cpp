#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &input) {
	(void)input;
}

RPN&	RPN::operator=(const RPN &input) {
	(void)input;
	return (*this);
}

RPN::~RPN() {}

const char*	RPN::Error::what() const throw() {
	return ("Error");
}

int	RPN::calc(std::string const &input) {
	std::stack<int>	stack;

	for (size_t i = 0 ; i < input.length() ; i++) {
		if (i % 2) {
			if (input[i] == ' ')
				continue ;
			throw Error();
		}
		else if (std::isdigit(input[i])) {
			stack.push(input[i] - '0');
		}
		else if (input[i] == '+' || input[i] == '-'
			|| input[i] == '*' || input[i] == '/') {
			if (stack.size() < 2)
				throw Error();
			size_t	top = stack.top();
			stack.pop();
			if (input[i] == '+')
				stack.top() += top;
			else if (input[i] == '-')
				stack.top() -= top;
			else if (input[i] == '*')
				stack.top() *= top;
			else
			{
				if (top == 0)
					throw Error();
				stack.top() /= top;
			}
		}
		else
			throw Error();
	}
	if (stack.size() > 1)
		throw Error();
	return (stack.top());
}
