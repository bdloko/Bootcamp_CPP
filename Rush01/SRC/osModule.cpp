/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:50:09 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:50:11 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/osModule.hpp"

osModule::osModule() : IMonitorModule(1, 5) {}

osModule::osModule(osModule const & src) {
	*this = src;
}

osModule::~osModule() {}

osModule & 	osModule::operator=(osModule const & src) {
	this->_osModuleLvl = src.getosModuleLvl();
	this->_minLvl = src.getMinLvl();
	this->_maxLvl = src.getMaxLvl();
	return *this;
}

int					osModule::getosModuleLvl() const {
	return (this->_osModuleLvl);
}

void				osModule::setosModuleLvl(int lvl) {
	this->_osModuleLvl = lvl;
}

int					osModule::getMaxLvl() const {
	return (this->_maxLvl);
}

void				osModule::setMaxLvl(int lvl) {
	this->_maxLvl = lvl;
}

int					osModule::getMinLvl() const {
	return (this->_minLvl);
}

void				osModule::setMinLvl(int lvl) {
	this->_minLvl = lvl;
}


std::string         osModule::get_system_name() const
{
	return(this->_system_name);
}
void                osModule::set_system_name(std::string system_name)
{
	this->_system_name= "System Name: " + system_name;
}




std::string         osModule::get_system_version() const
{
	return(this->_system_version);
}
void                osModule::set_system_version(std::string system_version)
{
	this->_system_version= "System Version: " + system_version;
}




std::string         osModule::get_system_release() const
{
	return(this->_system_release);
}
void                osModule::set_system_release(std::string system_release)
{
	this->_system_release = "System Release: " + system_release;
}




std::string         osModule::get_node() const
{
	return(this->_node);
}
void                osModule::set_node(std::string node)
{
	this->_node= "Node name: " + node;
}


std::string         osModule::get_machine() const
{
	return(this->_machine);
}
void                osModule::set_machine(std::string machine)
{
	this->_machine= "Machine Name: " + machine;
}














