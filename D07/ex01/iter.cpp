/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:29:58 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/14 13:30:02 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void print(T const & type) {
	std::cout << "Passed: " << type << std::endl;
}

template<typename T>
void iter(T * array, int len, void (*f)(T const & type)) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}
