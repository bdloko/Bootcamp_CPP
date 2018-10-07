/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:17:24 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/08 16:17:26 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap
{
public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(FragTrap const & src);
    ~FragTrap();
    FragTrap & 		operator=(FragTrap const & src);
    void 			rangedAttack(std::string const & target);
    void 			meleeAttack(std::string const & target);
    void 			takeDamage(unsigned int amount);
    void 			beRepaired(unsigned int amount);
    void 			vaulthunter_dot_exe(std::string const & target);
    unsigned int	getHP() const;
    unsigned int	getMaxHP() const;
    unsigned int	getEP() const;
    unsigned int	getMaxEP() const;
    unsigned int	getLevel() const;
    std::string		getName() const;
    unsigned int	getMAD() const;
    unsigned int	getRAD() const;
    unsigned int	getADR() const;
    std::string     random() const;

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
