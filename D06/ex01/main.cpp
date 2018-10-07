/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:50:20 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/13 14:50:44 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>

struct Data 
{
	std::string s1;
	int n;
	std::string s2;
};

Data * deserialize(void *raw)
{
	Data *d = new Data;
	std::string temp;
	int len;

	temp = reinterpret_cast<char *>(raw);
	len = temp.length();
	d->s2 = temp.substr(len - 8, len);
	d->n = atoi(temp.substr(8, len - 8).c_str());
	d->s1 = temp.substr(0, 8);
	return (d);
}

void* serialize(void)
{
	const char alphaArr[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::string str;
	for (int i = 0; i < 20; i++) {
		if (i == 8) {
			std::stringstream out;
			out << rand() % INT_MAX;
			str += out.str();
		}
		else
			str.push_back(alphaArr[rand() % static_cast<int>(sizeof(alphaArr) + 1)]);
	}
	return const_cast<char *>(str.c_str());
}

int main(void)
{
	srand(time(NULL));
	void *s = serialize();
	std::cout << "Memory address: " << s << std::endl;
	std::cout << "Serialized data: "  << reinterpret_cast<char *>(s) << std::endl << std::endl;
	Data *d = deserialize(s);
	std::cout << "Deserialized data: "<< std::endl;
	std::cout << "\ts1: " << d->s1 << std::endl;
	std::cout << "\tn: " << d->n << std::endl;
	std::cout << "\ts2: " << d->s2 << std::endl;
	return (0);
}
