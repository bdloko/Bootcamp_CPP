/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:49:16 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/08 17:37:35 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(unsigned int hp, unsigned int maxHP, unsigned int ep, unsigned int maxEP, unsigned int level, unsigned int MAD, unsigned int RAD, unsigned int ADR);
    ClapTrap(std::string name, unsigned int hp, unsigned int maxHP, unsigned int ep, unsigned int maxEP, unsigned int level, unsigned int MAD, unsigned int RAD, unsigned int ADR);
    ClapTrap(ClapTrap const & src);
    ~ClapTrap();
    ClapTrap & 		operator=(ClapTrap const & src);
    void 			rangedAttack(std::string const & target);
    void 			meleeAttack(std::string const & target);
    void 			takeDamage(unsigned int amount);
    void 			beRepaired(unsigned int amount);
    unsigned int	getHP() const;
    unsigned int	getMaxHP() const;
    unsigned int	getEP() const;
    unsigned int	getMaxEP() const;
    unsigned int	getLevel() const;
    std::string		getName() const;
    unsigned int	getMAD() const;
    unsigned int	getRAD() const;
    unsigned int	getADR() const;
    std::string     randomName() const;

protected:
    std::string		_name;
    unsigned int	_HP;
    unsigned int	_maxHP;
    unsigned int	_EP;
    unsigned int	_maxEP;
    unsigned int	_level;
    unsigned int	_MAD;
    unsigned int	_RAD;
    int 			_ADR;
};

#endif
