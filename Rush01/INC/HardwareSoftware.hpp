/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HardwareSoftware.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:10:42 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 15:49:27 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARDWARESOFTWARE_HPP
#define HARDWARESOFTWARE_HPP

#include "IMonitorModule.hpp"
#include <iostream>

class HsModule : public IMonitorModule
{
public:
	HsModule();
	HsModule(HsModule const & src);
    ~HsModule();
    HsModule & 	operator=(HsModule const & src);
    int					getHsModuleLvl() const;
    int					getMaxLvl() const;
    int					getMinLvl() const;
    void				setMinLvl(int lvl);
    void				setMaxLvl(int lvl);
    void				setHsModuleLvl(int lvl);

    std::string         get_hard() const;
    void                set_hard(std::string hard);

    std::string         get_soft() const;
    void                set_soft(std::string soft);

private:
    std::string                 _soft;
    std::string                 _hard;
};

#endif
