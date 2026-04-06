#pragma once

#ifndef __HARL_H__
# define __HARL_H__

# include <iostream>
# include <string>

class Harl
{
	public:
		void	complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

typedef struct	s_func
{
	std::string	type;
	void		(Harl::*cmd)(void);
}				t_func;

#endif
