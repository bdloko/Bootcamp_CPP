/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:52:45 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:52:47 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
#define NETWORKMODULE_HPP

#include "IMonitorModule.hpp"
#include <iostream>

class NetworkModule : public IMonitorModule
{
public:
	NetworkModule();
	NetworkModule(NetworkModule const & src);
    ~NetworkModule();
    NetworkModule & 	operator=(NetworkModule const & src);
    int					getNetworkModuleLvl() const;
    int					getMaxLvl() const;
    int					getMinLvl() const;
    void				setMinLvl(int lvl);
    void				setMaxLvl(int lvl);
    void				setNetworkModuleLvl(int lvl);



    std::string         get_packages_in() const;
    void                set_packages_in(std::string in);

    std::string         get_packages_out() const;
    void                set_packages_out(std::string out);

    std::string         get_router_ip() const;
    void                set_router_ip(std::string ip);

    std::string         get_domain_name_server() const;
    void                set_domain_name_server(std::string dns);

    std::string         get_domain_search() const;
    void                set_domain_search(std::string ds);

    
private:
    std::string         _packages_in;
    std::string         _packages_out;
    std::string         _router_ip;
    std::string         _domain_name_server;
    std::string         _domain_search;
};

#endif
