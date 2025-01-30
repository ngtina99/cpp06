/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:07:33 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/30 01:15:33 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int	main() {
Data ptr2;
	// ptr2.name = "Michaela Mustermann";
	// ptr2.num = 42;

	// Data ptr;
	// ptr.name = "Max Mustermann";
	// ptr.num = 42;


	// std::cout << "Here is the original structs:" <<
	// 			"\n\taddress: " << &ptr <<
	// 			"\n\tname: " << ptr.name <<
	// 			"\n\tage: " << ptr.num <<
	// std::endl;
	// std::cout << "\taddress ptr2: " << &ptr2 <<
	// 			"\n\tname: " << ptr2.name <<
	// 			"\n\tage: " << ptr2.num <<
	// std::endl << std::endl;

	// Serializer a;

	// Data *reserialized_struct = a.deserialize(a.serialize(&ptr));

	// std::cout << "Here is the reserialized structs:" <<
	// 			"\n\taddress: " << reserialized_struct <<
	// 			"\n\tname: " << reserialized_struct->name <<
	// 			"\n\tage: " << reserialized_struct->num <<
	// std::endl;
	// std::cout << "\taddress ptr2: " << &ptr2 <<
	// 			"\n\tname: " << ptr2.name <<
	// 			"\n\tage: " << ptr2.num <<
	// std::endl << std::endl;

	// return (0);

Data	d;
	Data	*deserialized;

	d.num = 42;
	d.name = "Born2Code";

	std::cout << "Original Data structure values:" << std::endl;
	std::cout << "Data.i (int): " << d.num << std::endl;
	std::cout << "Data.val (string): " << d.name << std::endl;
	std::cout << "Original address: " << static_cast<void *>(&d) << std::endl << std::endl;

	Serializer a;

	std::cout << "Serialization..." << std::endl;
	uintptr_t raw = a.serialize(&d);
	std::cout << "Raw Data: " << raw << std::endl << std::endl;

	std::cout << "Deserialization..." << std::endl;
	deserialized = a.deserialize(raw);
	std::cout << "All the following values should be the same as before serialization/deserialization" << std::endl << std::endl;

	std::cout << "Post-serialization / deserialization values:" << std::endl;
	std::cout << "deserialized.i (int): " << deserialized->num << std::endl;
	std::cout << "deserialized.val (string): " << deserialized->name << std::endl;
	std::cout << "Final address: " << static_cast<void *>(deserialized) << std::endl;

	return (0);

}