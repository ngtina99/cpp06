/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:42:16 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/30 01:10:26 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <cstdint> //for the cast

typedef struct Data {
	std::string	name;
	size_t		num;
}				Data;

class	Serializer {

	public:
	
		Serializer();
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer &rhs);
		~Serializer();

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
		
};

#endif