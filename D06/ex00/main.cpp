/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:00:51 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/13 13:06:33 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

int		main (int strc, char** strv) {
	std::string str;
	if (strc != 2) {
		std::cout << "Error. Usage: ./conv 'str'" << std::endl;
		return (0);
	}
	str = strv[1];
	if (strcmp(str.c_str(),"nan") == 0 || strcmp(str.c_str(), "nanf") == 0 ) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	if (str.length() == 1 && !isdigit(str.at(0)) && isprint(str.at(0))) {
		std::cout << "char: " << "'" << str.at(0) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(str.at(0)) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(str.at(0)) << std::endl;
		return (0);
	}
	long int 	chkInt = atol(str.c_str());
	if (chkInt >= 0 && chkInt <= INT_MAX && chkInt >= INT_MIN && isdigit(str.at(0))) {
		if ( isprint(chkInt) )
			std::cout << "char: "<< "'" << static_cast<char> (chkInt) << "'" << std::endl;
		else
			std::cout << "char: " << " Non displayable"  << std::endl;
		std::cout << "int: " << chkInt << std::endl;
		if (static_cast<double>(chkInt)) {
			std::cout << std::setprecision(str.length()) << "float: " << static_cast<float>(chkInt) << ".0f" << std::endl;
			std::cout << std::setprecision(str.length()) << "double: " << static_cast<double>(chkInt) << ".0" << std::endl;
		}
		else if (isdigit(str.at(0))) {
			std::cout << std::setprecision(str.length()) << "float: " << static_cast<float>(chkInt) << ".0f" << std::endl;
			std::cout << std::setprecision(str.length()) << "double: " << static_cast<double>(chkInt) << ".0" << std::endl;
		}
	}
	return (0);
}
