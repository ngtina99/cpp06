/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:42:16 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 20:23:31 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h> 

#define MYEOF "\033[0m"
#define MYRED "\033[1;31m"
#define MYBLUE "\033[1;34m"
#define MYGREEN "\033[1;32m"
#define MYPURPLE "\033[1;35m"

#include "Data.hpp"

class	Serializer {

	private:

		Serializer();
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer &rhs);
		~Serializer();

	public:

		//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t	serialize(Data* ptr);
		//It takes an unsigned integer parameter and converts it to a pointer to Data.
		static Data*		deserialize(uintptr_t raw);
		
};

#endif
