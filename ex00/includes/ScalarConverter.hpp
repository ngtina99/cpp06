/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:38:39 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 20:00:30 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#define MYEOF "\033[0m"
#define MYRED "\033[1;31m"
#define MYBLUE "\033[1;34m"
#define MYGREEN "\033[1;32m"
#define MYPURPLE "\033[1;35m"

#define MIN_NEG_DOUBLE -1.7976931348623157e+308
#define MIN_NEG_FLOAT -3.402823466e+38f

#include <iostream>
#include <limits> // numeric_limits
#include <cmath> // isnan, isinf
#include <iomanip> //setpricision

class ScalarConverter
{
	private:

		ScalarConverter(); // Private constructor prevents instantiation
		~ScalarConverter();
		ScalarConverter( const ScalarConverter &copy);
		ScalarConverter &operator=( const ScalarConverter &rhs);

		static  double	StringToDouble(const std::string &value);
		static  size_t	PrecisionChecker(const std::string &value);

	public:

		static void convert(const std::string &type);
		void	ConvertInt( double value );
		void	ConvertChar( double value );
		void	ConvertFloat( double value, size_t precision, size_t len );
		void	ConvertDouble( double value, size_t precision, size_t len );


};



#endif