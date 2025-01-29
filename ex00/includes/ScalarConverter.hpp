/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:38:39 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/29 04:52:57 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#define MYEOF "\033[0m"
#define MYRED "\033[1;31m"
#define MYBLUE "\033[1;34m"
#define MYGREEN "\033[1;32m"
#define MYPURPLE "\033[1;35m"

#include <iostream>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:

	static  double	const StringToDouble(const std::string &value);
	static  size_t	const PrecisionChecker(const std::string &value);
	void	ConvertInt( double value );
	void	ConvertChar( double value );
	void	ConvertFloat( double value, size_t precision );
	void	ConvertDouble( double value, size_t precision );

public:
	ScalarConverter();
	// ScalarConverter(const std::string &stringArg);
	// ScalarConverter( const );
	// ScalarConverter &operator=(/* args */);
	~ScalarConverter();

	static void convert(const std::string &type);
};



#endif