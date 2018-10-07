/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurrentModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:49:10 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:49:13 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/CurrentModule.hpp"

CurrentModule::CurrentModule() : IMonitorModule(1, 5) {}

CurrentModule::CurrentModule(CurrentModule const & src) {
	*this = src;
}

CurrentModule::~CurrentModule() {}

CurrentModule & 	CurrentModule::operator=(CurrentModule const & src) {
	this->_currentModuleLvl = src.getCurrentModuleLvl();
	this->_minLvl = src.getMinLvl();
	this->_maxLvl = src.getMaxLvl();
	return *this;
}

int					CurrentModule::getCurrentModuleLvl() const {
	return (this->_currentModuleLvl);
}
void				CurrentModule::setCurrentModuleLvl(int lvl) {
	this->_currentModuleLvl = lvl;
}

int					CurrentModule::getMaxLvl() const {
	return (this->_maxLvl);
}

void				CurrentModule::setMaxLvl(int lvl) {
	this->_maxLvl = lvl;
}

int					CurrentModule::getMinLvl() const {
	return (this->_minLvl);
}

void				CurrentModule::setMinLvl(int lvl) {
	this->_minLvl = lvl;
}



std::string                 CurrentModule::get_cpu_p() const
{
	return (this->_cpu_p);
}

void               CurrentModule:: set_cpu_p(std::string percentage)
{
	this->_cpu_p = percentage;
}

std::string                 CurrentModule::get_ram_p() const
{
	return (this->_ram_p);
}

void                CurrentModule::set_ram_p(std::string percentage)
{
	this->_ram_p = percentage;
}

std::string                 CurrentModule::get_clockspeed() const
{
	return (this->_clockspeed);
}

void                CurrentModule::set_clockspeed(std::string speed)
{
	this->_clockspeed = speed;
}

std::string			CurrentModule::get_model() const
{
	return (this->_model);
}

void                CurrentModule::set_model(std::string model)
{
	this->_model = model;

}

std::string                 CurrentModule::get_num_cores() const
{
	return (this->_num_cores);

}
void                CurrentModule::set_num_cores(std::string number)
{
	this->_num_cores = number;
}

























