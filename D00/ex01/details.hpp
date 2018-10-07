/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:37:03 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/05 16:42:46 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_H
#define AWESOME_H

#include <iomanip>
#include <iostream>
#include <string>

class Contact {
public:
	Contact();
	~Contact();
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string login;
	std::string postal;
	std::string email;
	std::string phone;
	std::string dob;
	std::string meal;
	std::string colour;
	std::string secret;
};

Contact	add();
void	search(Contact con, int index);
int		main(int argc, char** argv);

#endif
