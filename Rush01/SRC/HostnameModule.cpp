/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:49:33 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:49:51 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/HostnameModule.hpp"

HostnameModule::HostnameModule() : IMonitorModule(1, 4) {}

HostnameModule::HostnameModule(HostnameModule const & src) {
	*this = src;
}

HostnameModule::~HostnameModule() {}

HostnameModule & 	HostnameModule::operator=(HostnameModule const & src) {
	this->_hostnameModuleLvl = src.getHostnameModuleLvl();
	this->_minLvl = src.getMinLvl();
	this->_maxLvl = src.getMaxLvl();
	return *this;
}

int					HostnameModule::getHostnameModuleLvl() const {
	return (this->_hostnameModuleLvl);
}
void				HostnameModule::setHostnameModuleLvl(int n) {
	this->_hostnameModuleLvl = n;
}

int					HostnameModule::getMaxLvl() const {
	return (this->_maxLvl);
}

void				HostnameModule::setMaxLvl(int n) {
	this->_maxLvl = n;
}

int					HostnameModule::getMinLvl() const {
	return (this->_minLvl);
}

void				HostnameModule::setMinLvl(int n) {
	this->_minLvl = n;
}

std::string			HostnameModule::get_username() const
{
	return (this->_username);
}

void                HostnameModule::set_username(std::string username)
{
	this->_username = username;

}

std::string			HostnameModule::get_system_id() const
{
	return (this->_system_id);
}

void                HostnameModule::set_system_id(std::string system_id)
{
	this->_system_id = system_id;

}

std::string			HostnameModule::get_internal_ip() const
{
	return (this->_internal_ip);
}

void                HostnameModule::set_internal_ip(std::string internal_ip)
{
	this->_internal_ip = internal_ip;

}

std::string			HostnameModule::get_external_ip() const
{
	return (this->_external_ip);
}

void                HostnameModule::set_external_ip(std::string external_ip)
{
	this->_external_ip = external_ip;

}

















