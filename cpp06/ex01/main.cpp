#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data data;
	data.id = 42;
	data.name = "Samet";

	Data *ptr = &data;
	uintptr_t raw = Serializer::serialize(ptr);
	Data *new_ptr = Serializer::deserialize(raw);

	std::cout << "ptr address     : " << ptr << std::endl;
	std::cout << "serialized value: " << raw << std::endl;
	std::cout << "new_ptr address : " << new_ptr << std::endl;
	std::cout << std::endl;

	if (ptr == new_ptr)
		std::cout << "OK: pointers are equal" << std::endl;
	else
		std::cout << "FAIL: pointers are different" << std::endl;

	std::cout << "id   : " << new_ptr->id << std::endl;
	std::cout << "name : " << new_ptr->name << std::endl;

	return (0);
}