/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:54:14 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/08 17:38:33 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(100, 100, 50, 50, 1, 20, 15, 3) {
    std::cout << "<" << this->_name << ">This time it'll be awesome, I promise!\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3) {
    std::cout << "<" << this->_name << ">Hey everybody! Check out my package!\n";
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	*this = src;
    std::cout << "<" << this->_name << ">Glitching weirdness is a term of endearment, right?\n";
}

ScavTrap &  ScavTrap::operator=(ScavTrap const & src) {
    this->_HP = src.getHP();
    this->_EP = src.getEP();
    this->_level = src.getLevel();
    this->_name = src.getName();
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "<" << this->_name << ">My robotic flesh! AAHH!\n";
}

void    ScavTrap::challengeNewcomer(std::string const & target) {
    int i = rand()  % 3;

    if (this->_EP < 25) {
        std::cout << this->_name << " doesn't have enough EP.\n";
    }
    else if (this->_HP == 0) {
        std::cout << this->_name << " is already a pile of rubble.\n";
    }
    else {
        this->_EP -= 25;
        std::cout << "<" << this->_name << "> Hey " << target << "! Let's see what you can really do huh?\n";
        if (i == 0) {
            std::cout << "<" << this->_name << ">Bring me Red Bellys big red belly!\n";
        }
        else if (i == 1) {
            std::cout << "<" << this->_name << ">Beat me at a dance off!\n";
        }
        else if (i == 2) {
            std::cout << "<" << this->_name << ">Bring me FragTraps eye...\n";
        }
    }
}
