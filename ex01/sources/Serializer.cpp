/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:42:11 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 20:23:42 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {
		std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer() {
		std::cout << "Serializer deconstructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy) {
		std::cout << "Serializer copy constructor called" << std::endl;
		*this = copy;
}

Serializer &Serializer::operator=(const Serializer &rhs) {
	std::cout << "Serializer copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

//it usually refers to a tool or process that converts data into a format that can be easily stored or transmitted

// Use serialize() on the address of the Data object and pass its return value to
//uintptr_t is typically used for storing pointers as integer values without losing any information.
uintptr_t	Serializer::serialize(Data* ptr) {
	return(reinterpret_cast<uintptr_t>(ptr));
}

// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer
Data*		Serializer::deserialize(uintptr_t raw) {
		return(reinterpret_cast<Data *>(raw));
}
