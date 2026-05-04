#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <string>

class Harl
{
	public:
		void	complain(std::string level);
	private:
		void	other(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

typedef struct	s_func
{
	std::string	type;
	int			idx;
}				t_func;

#endif
