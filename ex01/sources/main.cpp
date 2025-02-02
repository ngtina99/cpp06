/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:07:33 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/02 22:01:56 by ngtina1999       ###   ########.fr       */
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
}