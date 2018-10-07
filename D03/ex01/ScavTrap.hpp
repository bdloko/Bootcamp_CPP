/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:36:45 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/08 16:36:48 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const & src);
    ~ScavTrap();
    ScavTrap & 		operator=(ScavTrap const & src);
    void 			rangedAttack(std::string const & target);
    void 			meleeAttack(std::string const & target);
    void 			takeDamage(unsigned int amount);
    void 			beRepaired(unsigned int amount);
    void 			challengeNewcomer(std::string const & target);
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

private:
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
