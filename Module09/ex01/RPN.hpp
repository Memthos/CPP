#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<int>	_stack;
		RPN();
		RPN(const RPN &input);
		RPN&	operator=(const RPN &input);
		~RPN();
	public:
		static int	calc(std::string const &input);


};
#endif
