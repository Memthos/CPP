#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		RPN();
		RPN(const RPN &input);
		RPN&	operator=(const RPN &input);
		~RPN();
	public:
		static int	calc(std::string const &input);
		class	Error : public std::exception {
			public:
				const char*	what() const throw();
		};
};
#endif
