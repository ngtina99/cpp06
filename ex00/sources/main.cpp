/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:24:40 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/14 01:51:04 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		return(std::cout << MYRED <<"Please put only one argument" << MYEOF << std::endl, 1);
	ScalarConverter::convert(argv[1]);
}
