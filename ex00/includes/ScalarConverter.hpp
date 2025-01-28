/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:38:39 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/28 01:50:34 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
	/* data */
public:
	ScalarConverter(  );
	ScalarConverter(/* args */);
	// ScalarConverter( const );
	// ScalarConverter &operator=(/* args */);
	// ~ScalarConverter();

	static void convert(const std::string &type);
};



#endif