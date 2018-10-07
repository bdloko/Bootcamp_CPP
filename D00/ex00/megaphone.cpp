/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:02:46 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/05 15:15:22 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

int		main(int ac, char **av) {
	int		i;
	int		j;
	int		a;

	i = 0;
	j = 1;
	a = 1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		while (j < ac) {
			while (av[j][i]) {
				av[j][i] = toupper(av[j][i]);
				i++;
			}
			std::cout << trim(av[j]) << ' ';
			j++;
			i = 0;
		}
	}
	std::cout << '\n';
}
