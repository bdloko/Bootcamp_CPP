/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:49:58 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:50:01 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/NetworkModule.hpp"

NetworkModule::NetworkModule() : IMonitorModule(1, 5) {}

NetworkModule::NetworkModule(NetworkModule const & src) {
	*this = src;
}

NetworkModule::~NetworkModule() {}

NetworkModule & 	NetworkModule::operator=(NetworkModule const & src) {
	this->_networkModuleLvl = src.getNetworkModuleLvl();
	this->_minLvl = src.getMinLvl();
	this->_maxLvl = src.getMaxLvl();
	return *this;
}

int					NetworkModule::getNetworkModuleLvl() const {
	return (this->_networkModuleLvl);
}

void				NetworkModule::setNetworkModuleLvl(int lvl) {
	this->_networkModuleLvl = lvl;
}

int					NetworkModule::getMaxLvl() const {
	return (this->_maxLvl);
}

void				NetworkModule::setMaxLvl(int lvl) {
	this->_maxLvl = lvl;
}

int					NetworkModule::getMinLvl() const {
	return (this->_minLvl);
}

void				NetworkModule::setMinLvl(int lvl) {
	this->_minLvl = lvl;
}

void                 NetworkModule::set_packages_in(std::string in)
{
	this->_packages_in = in;
}

std::string                NetworkModule::get_packages_in() const
{
	return(this->_packages_in);
}

void                 NetworkModule::set_packages_out(std::string out)
{
	this->_packages_out = out;
}
std::string                NetworkModule::get_packages_out() const
{
	return(this->_packages_out);
}

void         NetworkModule::set_router_ip(std::string ip)
{
	this->_router_ip = ip;
}
std::string               NetworkModule::get_router_ip() const
{
	return(this->_router_ip);
}

void         NetworkModule::set_domain_name_server(std::string dns)
{
	this->_domain_name_server = dns;
}
std::string                NetworkModule::get_domain_name_server() const
{
	return(this->_domain_name_server);
}

void         NetworkModule::set_domain_search(std::string ds)
{
	this->_domain_search = ds;
}
std::string                NetworkModule::get_domain_search() const
{
	return(this->_domain_search);
}








