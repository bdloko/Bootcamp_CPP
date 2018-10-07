/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:51:53 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:51:56 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP

#include "IMonitorModule.hpp"
#include <iostream>

class HostnameModule : public IMonitorModule
{
public:
	HostnameModule();
	HostnameModule(HostnameModule const & src);
    ~HostnameModule();
    HostnameModule & 	operator=(HostnameModule const & src);
    int					getHostnameModuleLvl() const;
    int					getMaxLvl() const;
    int					getMinLvl() const;
    void				setMinLvl(int n);
    void				setMaxLvl(int n);
    void				setHostnameModuleLvl(int n);

    std::string         get_username() const;
    void                set_username(std::string username);

    std::string         get_system_id() const;
    void                set_system_id(std::string system_id);

    std::string         get_internal_ip() const;
    void                set_internal_ip(std::string internal_ip);

    std::string         get_external_ip() const;
    void                set_external_ip(std::string external_ip);
    
private:
    std::string                 _username;
    std::string                 _system_id;
    std::string                 _internal_ip;
    std::string                 _external_ip;
};

#endif
