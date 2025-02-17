/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:07:33 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 20:20:30 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main() {
	Data *d1 = new Data();
	d1->name = "Pedro";
	d1->num = 1;

	Data *d2 = new Data();
	d2->name = "Joao ";
	d2->num = 100;

	std::cout << "- Original Data Structures:\n";
	std::cout << "d1 Address: " << d1 << " | Name: " << d1->name << " | Num: " << d1->num << std::endl;
	std::cout << "d2 Address: " << d2 << " | Name: " << d2->name << " | Num: " << d2->num << std::endl;

	// Serialize
	uintptr_t raw1 = Serializer::serialize(d1);
	uintptr_t raw2 = Serializer::serialize(d2);

	std::cout << "\n- Serialized Values:\n";
	std::cout << "d1 Serialized: " << raw1 << std::endl;
	std::cout << "d2 Serialized: " << raw2 << std::endl;

	// Deserialize
	Data *deserialized1 = Serializer::deserialize(raw1);
	Data *deserialized2 = Serializer::deserialize(raw2);

	std::cout << "\n- Deserialized Data Structures:\n";
	std::cout << "Deserialized Address: " << deserialized1 << " | Name: " << deserialized1->name << " | Num: " << deserialized1->num << std::endl;
	std::cout << "Deserialized Address: " << deserialized2 << " | Name: " << deserialized2->name << " | Num: " << deserialized2->num << std::endl;

	// Address Check
	std::cout << "\n- Address Check: ";
	if (deserialized1 == d1 && deserialized2 == d2) {
		std::cout << MYGREEN << "PASSED" << MYEOF << std::endl;
	} else {
		std::cout << MYRED <<"FAILED" << MYEOF << std::endl;
	}
	
	// Data Integrity Check
	std::cout << "- Data Check: ";
	if (deserialized1->name == "Pedro" && deserialized1->num == 1 &&
		deserialized2->name == "Joao " && deserialized2->num == 100) {
		std::cout << MYGREEN << "PASSED" << MYEOF <<std::endl;
	} else {
		std::cout << MYRED <<"FAILED" << MYEOF << std::endl;
	}

	delete d1;
	delete d2;

	// Null Pointer Test
	Data *nullPtr = NULL;

	uintptr_t rawNull = Serializer::serialize(nullPtr);

	Data *deserializedNull = Serializer::deserialize(rawNull);

	std::cout << "\n- Null Pointer Test:\n";
	std::cout << "Serialized Null: " << rawNull << std::endl;
	std::cout << "Deserialized Null: " << deserializedNull << std::endl;

	std::cout << "Null Pointer Check: ";
	if (deserializedNull == nullPtr) {
		std::cout << MYGREEN << "PASSED" << MYEOF <<std::endl;
	} else {
		std::cout << MYRED << "FAILED" << MYEOF << std::endl;
	}
// Addresses remain the same after serialization & deserialization.
// Data integrity is maintained (values do not change).
// Different objects have different serialized values (proving serialization uniquely identifies them).
}