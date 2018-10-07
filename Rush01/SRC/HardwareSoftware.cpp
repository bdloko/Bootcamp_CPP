/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurrentModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:49:10 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 16:03:16 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/HardwareSoftware.hpp"

HsModule::HsModule() : IMonitorModule(1, 5) {}
HsModule::HsModule(HsModule const & src) {
	*this = src;
}
HsModule::~HsModule() {}

HsModule & 	HsModule::operator=(HsModule const & src) {
	this->_HsModuleLvl = src.getHsModuleLvl();
	this->_minLvl = src.getMinLvl();
	this->_maxLvl = src.getMaxLvl();
	return *this;
}

int					HsModule::getHsModuleLvl() const {
	return (this->_HsModuleLvl);
}
void				HsModule::setHsModuleLvl(int lvl) {
	this->_HsModuleLvl = lvl;
}

int					HsModule::getMaxLvl() const {
	return (this->_maxLvl);
}

void				HsModule::setMaxLvl(int lvl) {
	this->_maxLvl = lvl;
}

int					HsModule::getMinLvl() const {
	return (this->_minLvl);
}

void				HsModule::setMinLvl(int lvl) {
	this->_minLvl = lvl;
}



std::string                 HsModule::get_hard() const
{
	return (this->_hard);
}

void               HsModule:: set_hard(std::string hard)
{
	this->_hard = hard;
}

std::string                 HsModule::get_soft() const
{
	return (this->_soft);
}

void                HsModule::set_soft(std::string soft)
{
	this->_soft = soft;
}
























