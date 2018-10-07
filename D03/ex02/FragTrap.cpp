/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:53:40 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/08 16:53:42 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 100, 100, 1, 30, 20, 5) {
    std::cout << "<" << this->_name << ">Look out everybody! Things are about to get awesome!\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5) {
    std::cout << "<" << this->_name << ">Let's get this party started!\n";
}

FragTrap::FragTrap(FragTrap const & src) {
    *this = src;
    std::cout << "<" << this->_name << ">Recompiling my combat code!\n";
}

FragTrap &  FragTrap::operator=(FragTrap const & src) {
    this->_HP = src.getHP();
    this->_EP = src.getEP();
    this->_level = src.getLevel();
    this->_name = src.getName();
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "<" << this->_name << ">Argh arghargh death gurgle gurglegurgle urgh... d e a t h.\n";
}

void    FragTrap::vaulthunter_dot_exe(std::string const & target) {
    int i = rand() % 5;

    if (this->_EP < 25) {
        std::cout << this->_name << " doesn't have enough EP.\n";
    }
    else if (this->_HP == 0) {
        std::cout << this->_name << " is already a pile of rubble.\n";
    }
    else {
        this->_EP -= 25;
        std::cout << "<" << this->_name << ">I have an IDEA!\n";
        if (i == 0) {
            std::cout << "<" << this->_name << ">How many ways can I say... THROWING GRENADE?!\n";
            std::cout << this->_name << " throws what can only be described as a waterbaloon from hell at " << target << " causing >9001 damage.\n";
        }
        else if (i == 1) {
            std::cout << "<" << this->_name << "> This could've gone better!\n";
            std::cout << this->_name << " misses " << target << " miserably causing 0 damage.\n";
        }
        else if (i == 2) {
            std::cout << "<" << this->_name << ">Wow, that actually worked?\n";
            beRepaired(10);
        }
        else if (i == 3) {
            std::cout << "<" << this->_name << ">Crack shot!\n";
            rangedAttack(target);
        }
        else if (i == 4) {
            std::cout << "<" << this->_name << ">Eat my shiny metal ass!\n";
            meleeAttack(target);
        }
    }
}
