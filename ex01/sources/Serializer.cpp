/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:42:11 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/14 13:31:42 by ngtina1999       ###   ########.fr       */
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
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw) {
		return(reinterpret_cast<Data *>(raw));

}
	
// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer