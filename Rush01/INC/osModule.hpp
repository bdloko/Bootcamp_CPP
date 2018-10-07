/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:53:03 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:53:06 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_HPP
#define OSMODULE_HPP

#include <iostream>

#include "IMonitorModule.hpp"

class osModule : public IMonitorModule
{
public:
	osModule();
	osModule(osModule const & src);
    ~osModule();
    osModule & 	operator=(osModule const & src);
    int					getosModuleLvl() const;
    int					getMaxLvl() const;
    int					getMinLvl() const;
    void				setMinLvl(int lvl);
    void				setMaxLvl(int lvl);
    void				setosModuleLvl(int lvl);

    std::string         get_system_name() const;
    void                set_system_name(std::string system_name);

    std::string         get_system_version() const;
    void                set_system_version(std::string system_version);

    std::string         get_system_release() const;
    void                set_system_release(std::string system_release);

    std::string         get_node() const;
    void                set_node(std::string node);

    std::string         get_machine() const;
    void                set_machine(std::string machine);
    
private:
    std::string         _system_name;
    std::string         _system_version;
    std::string         _system_release;
    std::string         _node;
    std::string         _machine;
};

#endif
