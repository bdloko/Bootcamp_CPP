/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:22:05 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/08 16:22:09 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : _name(random()), _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _MAD(30), _RAD(20), _ADR(5) {
    std::cout << "<" << this->_name << ">Hold your balls the game is about to start\n";
}

FragTrap::FragTrap(std::string name) : _name(name), _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _MAD(30), _RAD(20), _ADR(5) {
    std::cout << "<" << this->_name << ">Let the game begin!\n";
}

FragTrap::FragTrap(FragTrap const & src) {
    *this = src;
    std::cout << "<" << this->_name << ">Reshuffle figth!\n";
}

FragTrap &  FragTrap::operator=(FragTrap const & src) {
    this->_HP = src.getHP();
    this->_EP = src.getEP();
    this->_level = src.getLevel();
    this->_name = src.getName();
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "<" << this->_name << ">This mother f***s have no mercy, nooo noo noo they got my as*\n";
}

void FragTrap::rangedAttack(std::string const & target) {
    std::cout << this->_name << " shooting " << target << " causing " << this->_RAD - this->_ADR << " range got shot.\n";
}

void FragTrap::meleeAttack(std::string const & target) {
    std::cout << this->_name << " shooting " << target << " causing " << this->_MAD - this->_ADR<< " melee got shot.\n";
}

void FragTrap::takeDamage(unsigned int amount) {
    amount = (amount - this->_ADR);
    if(this->_HP > amount) {
        this->_HP = this->_HP - amount;
        std::cout << this->_name << " lost " << amount << " damage.\n";
    }
    else {
        this->_HP = 0;
        std::cout << "<" << this->_name << ">Got shot! I will be back! bye :(\n";
    }
}

void FragTrap::beRepaired(unsigned int amount) {
    unsigned int need;
    need = this->_maxHP - this->_HP;
    if(need >= amount) {
        this->_HP = this->_HP + amount;
        std::cout << this->_name << " absorbed " << amount << " HP.\n";
    }
    else if (need < amount && need != 0) {
        this->_HP = this->_HP + need;
        std::cout << this->_name << " absorbed " << need << " HP.\n";
    }
    else if (need == 0) {
        std::cout << this->_name << " HP are full.\n";
    }
}

void    FragTrap::vaulthunter_dot_exe(std::string const & target) {
    int i = rand() % 5;

    if (this->_EP < 25) {
        std::cout << this->_name << " is short of EP.\n";
    }
    else if (this->_HP == 0) {
        std::cout << this->_name << " is dieing slowly.\n";
    }
    else {
        this->_EP -= 25;
        std::cout << "<" << this->_name << ">Is getting in!\n";
        if (i == 0) {
            std::cout << "<" << this->_name << ">We all have one life to live!.. 'throwing grenade'\n";
            std::cout << this->_name << " Catch a warm death sucker..." << target << " damage.\n";
        }
        else if (i == 1) {
            std::cout << "<" << this->_name << "> This looser can miss!\n";
            std::cout << this->_name << " misses " << target << " 0 damage.\n";
        }
        else if (i == 2) {
            std::cout << "<" << this->_name << ">Wow, I guess I got him?\n";
            beRepaired(10);
        }
        else if (i == 3) {
            std::cout << "<" << this->_name << ">Bursted!\n";
            rangedAttack(target);
        }
        else if (i == 4) {
            std::cout << "<" << this->_name << ">The don't call me die hard for nothing...Oh damn I lost energy I lost life!\n";
            meleeAttack(target);
        }
    }
}

unsigned int    FragTrap::getHP() const {
    return (this->_HP);
}

unsigned int    FragTrap::getMaxHP() const {
    return (this->_maxHP);
}

unsigned int    FragTrap::getEP() const {
    return (this->_EP);
}

unsigned int    FragTrap::getMaxEP() const {
    return (this->_maxEP);
}

unsigned int    FragTrap::getLevel() const {
    return (this->_level);
}

std::string     FragTrap::getName() const {
    return (this->_name);
}

unsigned int    FragTrap::getMAD() const {
    return (this->_MAD);
}

unsigned int    FragTrap::getRAD() const {
    return (this->_RAD);
}

unsigned int    FragTrap::getADR() const {
    return (this->_ADR);
}

std::string     FragTrap::random() const {
    std::string players[] = {"Litha", "Gary", "Collen", "Oliver"};
    return players[(rand() % 3)];
}
