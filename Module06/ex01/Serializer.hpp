#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include <string>

typedef struct s_data {
	std::string	login;
	int			wallets;
	int			points;
}	Data;

class	Serializer {
	private:
		Serializer();
		Serializer(const Serializer &input);
		Serializer&	operator=(const Serializer &input);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
