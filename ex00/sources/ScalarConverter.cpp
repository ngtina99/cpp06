/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:37:54 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/29 05:07:12 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

size_t const ScalarConverter::PrecisionChecker(const std::string &value) {

	size_t	stringSize = value.size();
	size_t	dotCounter = 0;
	size_t	precisionNum = 0;

	if (value[stringSize - 1] == '.' || (value[stringSize - 1] == 'f' && stringSize == 1)) {
		std::cerr << MYRED << "Error: Invalid Input" << MYEOF << std::endl;
		exit (1);
	}
	if (value[stringSize - 1] == 'f') {
		stringSize = stringSize - 1;
	}
	for(size_t i = 0; i < stringSize; i++) {
		if (dotCounter > 1) {
			std::cerr << MYRED << "Error: Invalid Input" << MYEOF << std::endl;
			exit (1);
		}
		if(dotCounter > 0)
			precisionNum++;
		if (value[i] == '.')
			dotCounter++;
	}
	return (precisionNum);
}

double const ScalarConverter::StringToDouble(const std::string &value) {
	
	double	result = 0.0;
	int		negativeSign = 1;
	bool	isFraction = false;
	double	divisorFraction = 1.0;
	size_t	fCounter = 0;

	int stringSize = value.size();
    if (value == "nan" || value == "nanf") {
        return (std::nan(""));
    }
    if (value == "+inf" || value == "inf" || value == "+inff" || value == "inff") {
        return (INFINITY);
    }
	if (value == "-inf" || value == "-inff") {
		return (-INFINITY);
    }
	if (value[0] == '-')
		negativeSign  = -1;
	for (size_t i = 0; i < stringSize; i++) {
		if(((value[i] < '0' || value[i] > '9') && (value[i] != 'f' && value[i] != '.')) || fCounter == 1) {
			std::cerr << MYRED << "Error: Invalid input" << MYEOF << std::endl;
			exit (1);
		}
		if (value[i] == '.') {
			isFraction  = true;
			continue;
		}
		if (value[i] == 'f')
			fCounter = 1;
		if(fCounter == 1 && i == stringSize - 1)
			break ;
		else if (isFraction) {
			divisorFraction *= 10.0;
			result += static_cast<double>(value[i] - '0') / divisorFraction;	
		}
		else {
			result = (result * 10.0) + static_cast<double>(value[i] - '0');
		}
	}
	return (negativeSign * result);
}

void ScalarConverter::convert(const std::string &value) {

	ScalarConverter instanceUtil;
	
	size_t precisionNum = PrecisionChecker(value); 
	double convertedValue = StringToDouble(value);
	//std::cout << static_cast<int>(stringConverter) << std::endl;
	instanceUtil.ConvertInt(convertedValue);
	instanceUtil.ConvertChar(convertedValue);
	instanceUtil.ConvertFloat(convertedValue, precisionNum);
	instanceUtil.ConvertDouble(convertedValue, precisionNum);
}

void ScalarConverter::ConvertInt(double typeInt) {
	if (std::isnan(typeInt) || std::isinf(typeInt))
		std::cout << "int: impossible" << std::endl;
	else if (typeInt < std::numeric_limits<int>::min() || typeInt > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(typeInt) << std::endl;
}

void ScalarConverter::ConvertChar(double typeChar) {
	if (std::isnan(typeChar) || std::isinf(typeChar))
		std::cout << "char: impossible" << std::endl;
	else if (typeChar < std::numeric_limits<char>::min() || typeChar > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if(!std::isprint(typeChar))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(typeChar) << "'" << std::endl;
}
#include <iomanip>
void ScalarConverter::ConvertFloat(double typeFloat, size_t i) {
	if (std::isnan(typeFloat))
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(i) << static_cast<float>(typeFloat) << "f"<<std::endl;
}

void ScalarConverter::ConvertDouble(double typeDouble, size_t i) {
	if (std::isnan(typeDouble))
		std::cout << "double: nan" << std::endl;
	else
		std::cout << "double: " << std::setprecision(i) << static_cast<double>(typeDouble) <<std::endl;
}
