/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:44:05 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/05 18:15:33 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "details.hpp"

Contact	add() {
	Contact holder;
	std::cout << "Please provide me with the following details: \nFirst Name: ";
	std::getline(std::cin, holder.firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, holder.lastName);
	std::cout << "Nick Name: ";
	std::getline(std::cin, holder.nickname);
	std::cout << "Login: ";
	std::getline(std::cin, holder.login);
	std::cout << "Postal Address: ";
	std::getline(std::cin, holder.postal);
	std::cout << "Email: ";
	std::getline(std::cin, holder.email);
	std::cout << "Phone Number: ";
	std::getline(std::cin, holder.phone);
	std::cout << "Date of Birth: ";
	std::getline(std::cin, holder.dob);
	std::cout << "Favourite Meal: ";
	std::getline(std::cin, holder.meal);
	std::cout << "underwear Colour: ";
	std::getline(std::cin, holder.colour);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, holder.secret);
	return (holder);
}

std::string	truncated(std::string str) {
	if (str.length() > 10) {
		str.replace(9, str.length(), ".");
	}
	return (str);
}

void	table(Contact det[8], int index) {
	int Num;
	int i;
	char c;
	std::string option;
	std::cout << "Here are the avalible contacts:\n\n\t";
	std::cout << std::right << std::setw(10) << truncated("Index") << " | ";
	std::cout << std::right << std::setw(10) << truncated("First Name") << " | ";
	std::cout << std::right << std::setw(10) << truncated("Last Name") << " | ";
	std::cout << std::right << std::setw(10) << truncated("Nick Name") << std::endl;
	for (i = 0; i < index; i++) {
		std::string fn = truncated(det[i].firstName);
		std::string ln = truncated(det[i].lastName);
		std::string nick = truncated(det[i].nickname);
		std::cout << "\t" << std::right << std::setw(10) << i << " | ";
		std::cout << std::right << std::setw(10) << fn << " | ";
		std::cout << std::right << std::setw(10) << ln << " | ";
		std::cout << std::right << std::setw(10) << nick << std::endl;
	}
	std::cout << std::endl << "Please select a contact from 0 to " << i-1 << ": ";
	std::getline(std::cin, option);
	c = option[0];
	if (isdigit((int)c)) {
		Num = atoi(option.c_str());
		if (Num >= 0 && Num < i) {
		std::cout << "\nFirst Name: " << det[Num].firstName << std::endl;
		std::cout << "Last Name: " << det[Num].lastName << std::endl;
		std::cout << "Nick Name: " << det[Num].nickname << std::endl;
		std::cout << "Login: " << det[Num].login << std::endl;
		std::cout << "Postal Address: " << det[Num].postal << std::endl;
		std::cout << "Email: " << det[Num].email << std::endl;
		std::cout << "Phone Number: " << det[Num].phone << std::endl;
		std::cout << "Date of Birth: " << det[Num].dob << std::endl;
		std::cout << "Favourite Meal: " << det[Num].meal << std::endl;
		std::cout << "Current Underwear Colour: " << det[Num].colour << std::endl;
		std::cout << "Deepest Darkest Most Terrible Secret: " << det[Num].secret << std::endl << std::endl;
	}
	else
		std::cout << "You didnt enter a number between 0 and " << i-1 << " :(((\n";
	}
	else
		std::cout << "You didnt enter a number\n";
}

int		main(int argc, char **argv) {
	int		run;
	int		index;
	std::string	buff;
	Contact list[8];

	run = 1;
	index = 0;
	std::cout << "\nWelcome to PhoneBook\n\n\tADD -> Add a contact to your dairy\n\tSEARCH -> View a list\n\tEXIT -> Exit PhoneBook\n\n";
	while (run) {
		std::cout << "Please enter a command: ";
		getline(std::cin, buff);
		if (buff.compare("ADD") == 0 || buff.compare("add") == 0) {
			if (index < 8) {
				list[index] = add();
				index++;
			}
			else
				std::cout << "You have reached the max number of contacts\n";
		}
		else if (buff.compare("SEARCH") == 0 || buff.compare("search") == 0) {
			if (index == 0)
				std::cout << "Please add some contacts before tring to view them.\n";
			else
				table(list, index);
		}
		else if (buff.compare("EXIT") == 0 || buff.compare("exit") == 0) {
			run = 0;
			break;
		}
		else
			std::cout << "Error: unknown command\n";
	}
	return (0);
}
