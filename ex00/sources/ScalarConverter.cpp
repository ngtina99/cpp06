/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:37:54 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 20:04:37 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter( const ScalarConverter &copy) {
	(void) copy;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &rhs) {
    (void) rhs;
	return (*this);
}

size_t ScalarConverter::PrecisionChecker(const std::string &value) {

	size_t	stringLen = value.size();
	size_t	dotCounter = 0;
	size_t	precisionNum = 0;

	if (value[stringLen - 1] == '.' || (value[stringLen - 1] == 'f' && stringLen == 1)) {
		std::cerr << MYRED << "Error: Invalid Input" << MYEOF << std::endl;
		exit (1);
	}
	if (value[stringLen - 1] == 'f') {
		stringLen = stringLen - 1;
	}
	for(size_t i = 0; i < stringLen; i++) {
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

double ScalarConverter::StringToDouble(const std::string &value) {
	
	double	result = 0.0;
	int		negativeSign = 1;
	bool	isFraction = false;
	double	divisorFraction = 1.0;
	size_t	fCounter = 0;

	size_t stringLen = value.length();
    if (value == "nan" || value == "nanf") {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit (0);
    }
    else if (value == "+inf" || value == "inf" || value == "+inff" || value == "inff") {
        return (INFINITY);
    }
	else if (value == "-inf" || value == "-inff") {
		return (-INFINITY);
    }
	size_t i = 0;
	if (value[0] == '-') {
		negativeSign  = -1;
		i = 1;
	}
	while (i < stringLen) {
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
		if(fCounter == 1 && i == stringLen - 1)
			break ;
		else if (isFraction) {
			divisorFraction *= 10.0;
			result += static_cast<double>(value[i] - '0') / divisorFraction;	
		}
		else {
			result = (result * 10.0) + static_cast<double>(value[i] - '0');
		}
        i++;
	}
	return (negativeSign * result);
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

void ScalarConverter::ConvertInt(double typeInt) {
	if (std::isnan(typeInt) || std::isinf(typeInt))
		std::cout << "int: impossible" << std::endl;
	else if (typeInt < std::numeric_limits<int>::min() || typeInt > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(typeInt) << std::endl;
}

void ScalarConverter::ConvertFloat(double typeFloat, size_t i, size_t len) {
	if (std::isnan(typeFloat))
		std::cout << "float: nanf" << std::endl;
	else if (typeFloat > std::numeric_limits<float>::max())
		std::cout << "float: inff" << std::endl;
	else if (typeFloat < MIN_NEG_FLOAT)
		std::cout << "float: -inff" << std::endl;
	else if(i == 0 && len <= 7)
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(typeFloat) << "f" <<std::endl;
	else if(len > 7)	
		std::cout << "float: " << std::setprecision(i) << static_cast<float>(typeFloat) << "f" <<std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(i) << static_cast<float>(typeFloat) << "f" <<std::endl;
}

void ScalarConverter::ConvertDouble(double typeDouble, size_t i, size_t len) {
	if (std::isnan(typeDouble))
		std::cout << "double: nan" << std::endl;
	else if (typeDouble > std::numeric_limits<double>::max())
		std::cout << "double: inf" << std::endl;
	else if (typeDouble < MIN_NEG_DOUBLE)
		std::cout << "double: -inf" << std::endl;
	else if (i == 0 && len <= 7)
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(typeDouble) <<std::endl;
	else if (len > 7)
		std::cout << "double: " << std::setprecision(i) << static_cast<double>(typeDouble) << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(i) << static_cast<double>(typeDouble) << std::endl;
}

void ScalarConverter::convert(const std::string &value) {

	ScalarConverter a;
	double convertedValue;

	size_t len = value.length();
	size_t precisionNum; 
	if (value.size() == 1 && std::isprint(value[0]) && !std::isdigit(value[0])) {
		precisionNum = 0;
		convertedValue = static_cast<double>(value[0]);
	}
	else {
		precisionNum = a.PrecisionChecker(value); 
		convertedValue = a.StringToDouble(value);
	}

	a.ConvertChar(convertedValue);
	a.ConvertInt(convertedValue);
	a.ConvertFloat(convertedValue, precisionNum, len);
	a.ConvertDouble(convertedValue, precisionNum, len);

}

