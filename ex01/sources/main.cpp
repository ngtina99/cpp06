/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:07:33 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/02 22:02:49 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main() {
    Data d1;
    d1.name = "Pedro";
    d1.num = 1;

    Data d2;
    d2.name = "Joao ";
    d2.num = 100;

    Serializer serializer;

    std::cout << "- Original Data Structures:\n";
    std::cout << "d1 Address: " << &d1 << " | Name: " << d1.name << " | Num: " << d1.num << std::endl;
    std::cout << "d2 Address: " << &d2 << " | Name: " << d2.name << " | Num: " << d2.num << std::endl;

    // Serialize
    uintptr_t raw1 = serializer.serialize(&d1);
    uintptr_t raw2 = serializer.serialize(&d2);

    std::cout << "\n- Serialized Values:\n";
    std::cout << "d1 Serialized: " << raw1 << std::endl;
    std::cout << "d2 Serialized: " << raw2 << std::endl;
	

    // Deserialize
    Data *deserialized1 = serializer.deserialize(raw1);
    Data *deserialized2 = serializer.deserialize(raw2);

    std::cout << "\n- Deserialized Data Structures:\n";
    std::cout << "Deserialized d1 Address: " << deserialized1 << " | Name: " << deserialized1->name << " | Num: " << deserialized1->num << std::endl;
    std::cout << "Deserialized d2 Address: " << deserialized2 << " | Name: " << deserialized2->name << " | Num: " << deserialized2->num << std::endl;

    // Address Check
    std::cout << "\n- Address Check: ";
    if (deserialized1 == &d1 && deserialized2 == &d2) {
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

    // Null Pointer Test
    Data *nullPtr = nullptr;
    uintptr_t rawNull = serializer.serialize(nullPtr);
    Data *deserializedNull = serializer.deserialize(rawNull);

    std::cout << "\n- Null Pointer Test:\n";
    std::cout << "Serialized Null: " << rawNull << std::endl;
    std::cout << "Deserialized Null: " << deserializedNull << std::endl;

    std::cout << "Null Pointer Check: ";
    if (deserializedNull == nullptr) {
        std::cout << MYGREEN << "PASSED" << MYEOF <<std::endl;
    } else {
        std::cout << MYRED << "FAILED" << MYEOF << std::endl;
    }
// Addresses remain the same after serialization & deserialization.
// Data integrity is maintained (values do not change).
// Different objects have different serialized values (proving serialization uniquely identifies them).
// Null pointer serialization works correctly (proves safety in edge cases).

	// Data ptr2;
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


	// Data	d;
	// Data	*deserialized;

	// d.num = 42;
	// d.name = "forty-two";

	// std::cout << "Original Data structure values:" << std::endl;
	// std::cout << "Data int value: " << d.num << std::endl;
	// std::cout << "Data string value: " << d.name << std::endl;
	// std::cout << "Original address: " << &d << std::endl;

	// Serializer a;

	// std::cout << "Serialization..." << std::endl;
	// uintptr_t raw = a.serialize(&d);
	// std::cout << "Raw Data: " << raw << std::endl << std::endl;

	// std::cout << "Deserialization..." << std::endl;
	// deserialized = a.deserialize(raw);
	// std::cout << "All the following values should be the same as before serialization/deserialization" << std::endl << std::endl;

	// std::cout << "Post-serialization / deserialization values:" << std::endl;
	// std::cout << "deserialized.i (int): " << deserialized->num << std::endl;
	// std::cout << "deserialized.val (string): " << deserialized->name << std::endl;
	// std::cout << "Final address: " << deserialized << std::endl;
}