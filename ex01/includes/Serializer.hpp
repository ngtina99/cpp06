/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:42:16 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/14 03:09:52 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <cstdint> //for the cast

#define MYEOF "\033[0m"
#define MYRED "\033[1;31m"
#define MYBLUE "\033[1;34m"
#define MYGREEN "\033[1;32m"
#define MYPURPLE "\033[1;35m"

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
