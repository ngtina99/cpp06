/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:37:54 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/29 02:14:30 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _
{
}

ScalarConverter::~ScalarConverter() {
	
}

void ScalarConverter::convert(const std::string &value) {
	double stringConverter = static_cast<double>(value);
	//std::cout << static_cast<int>(stringConverter) << std::endl;
	convertInt(stringConverter);
	convertChar(stringConverter);
	convertFloat(stringConverter);
	convertDouble(stringConverter);	
}

void convertInt(double typeInt) {
	if (typeInt < std::numeric_limits<int>::min() || typeInt > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(typeInt) << std::endl;
}

void convertChar(double typeChar) {
	if (typeChar < std::numeric_limits<char>::min() || typeChar > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if(!std::isprint(typeChar))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(typeChar) << "'" << std::endl;
}

void convertFloat(double typeFloat) {
	if (std::isnan(typeFloat))
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(typeFloat) << "f"<<std::endl;
}

void convertDouble(double typeDouble) {
	if (std::isnan(typeDouble))
		std::cout << "double: nan" << std::endl;
	else
		std::cout << "double: " << static_cast<float>(typeDouble) << std::endl;
}


Any function to convert from a string to an int, a
float or a double. This will help, but won’t do the whole job.

	
static method "convert"
that will takes as parameter a string representation o


• char
• int
• float
• double
