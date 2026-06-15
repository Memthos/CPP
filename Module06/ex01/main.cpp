#include "Serializer.hpp"


int	main(void) {
	Data	mathis = {"mperrine", 145, 12};
	std::cout << "Original Mathis:" << std::endl;
	std::cout << "Address: " << &mathis << std::endl;
	std::cout << "Login: " << mathis.login << std::endl;
	std::cout << "Wallets: " << mathis.wallets << std::endl;
	std::cout << "Points: " << mathis.points << std::endl;

	std::cout << std::endl;

	Data	manolo = {"mcrenn", 105, 1};
	std::cout << "Original Manolo:" << std::endl;
	std::cout << "Address: " << &manolo << std::endl;
	std::cout << "Login: " << manolo.login << std::endl;
	std::cout << "Wallets: " << manolo.wallets << std::endl;
	std::cout << "Points: " << manolo.points << std::endl;

	std::cout << std::endl;

	uintptr_t	mathis_serialized = Serializer::serialize(&mathis);
	uintptr_t	manolo_serialized = Serializer::serialize(&manolo);

	std::cout << "Serialized Mathis:" << std::endl;
	std::cout << "Address: " << &mathis_serialized << std::endl;

	std::cout << std::endl;

	std::cout << "Serialized Manolo:" << std::endl;
	std::cout << "Address: " << &manolo_serialized << std::endl;

	std::cout << std::endl;

	Data	*mathis_deserialized = Serializer::deserialize(mathis_serialized);
	Data	*manolo_deserialized = Serializer::deserialize(manolo_serialized);

	std::cout << std::endl;

	std::cout << "Deserialized Mathis:" << std::endl;
	std::cout << "Address: " << &mathis_deserialized << std::endl;
	std::cout << "Login: " << mathis_deserialized->login << std::endl;
	std::cout << "Wallets: " << mathis_deserialized->wallets << std::endl;
	std::cout << "Points: " << mathis_deserialized->points << std::endl;

	std::cout << std::endl;

	std::cout << "Deserialized Manolo:" << std::endl;
	std::cout << "Address: " << &manolo_deserialized << std::endl;
	std::cout << "Login: " << manolo_deserialized->login << std::endl;
	std::cout << "Wallets: " << manolo_deserialized->wallets << std::endl;
	std::cout << "Points: " << manolo_deserialized->points << std::endl;
}
