/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurrentModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:51:30 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:51:33 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURRENTMODULE_HPP
#define CURRENTMODULE_HPP

#include "IMonitorModule.hpp"
#include <iostream>

class CurrentModule : public IMonitorModule
{
public:
	CurrentModule();
	CurrentModule(CurrentModule const & src);
    ~CurrentModule();
    CurrentModule & 	operator=(CurrentModule const & src);
    int					getCurrentModuleLvl() const;
    int					getMaxLvl() const;
    int					getMinLvl() const;
    void				setMinLvl(int lvl);
    void				setMaxLvl(int lvl);
    void				setCurrentModuleLvl(int lvl);

    std::string         get_cpu_p() const;
    void                set_cpu_p(std::string percentage);

    std::string         get_ram_p() const;
    void                set_ram_p(std::string percentage);

    std::string         get_clockspeed() const;
    void                set_clockspeed(std::string speed);

    std::string         get_model() const;
    void                set_model(std::string model);

    std::string         get_num_cores() const;
    void                set_num_cores(std::string number);
    
private:
    std::string                 _cpu_p;
    std::string                 _ram_p;
    std::string                 _clockspeed;
    std::string                 _model;
    std::string                 _num_cores;
};

#endif
