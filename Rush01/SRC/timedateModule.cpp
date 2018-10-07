/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timedateModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:50:24 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:50:31 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/timedateModule.hpp"

dtModule::dtModule() : IMonitorModule(1, 5) {}

dtModule::dtModule(dtModule const & src) {
	*this = src;
}

dtModule::~dtModule() {}

dtModule & 	dtModule::operator=(dtModule const & src) {
	this->_dtModuleLvl = src.getdtModuleLvl();
	this->_minLvl = src.getMinLvl();
	this->_maxLvl = src.getMaxLvl();
	return *this;
}

int					dtModule::getdtModuleLvl() const {
	return (this->_dtModuleLvl);
}

void				dtModule::setdtModuleLvl(int lvl) {
	this->_dtModuleLvl = lvl;
}

int					dtModule::getMaxLvl() const {
	return (this->_maxLvl);
}

void				dtModule::setMaxLvl(int lvl) {
	this->_maxLvl = lvl;
}

int					dtModule::getMinLvl() const {
	return (this->_minLvl);
}

void				dtModule::setMinLvl(int lvl) {
	this->_minLvl = lvl;
}

std::string         dtModule::get_date() const {
	return(this->_date);
}
void                dtModule::set_date(std::string date) {
	this->_date= "Date: " + date;
}

std::string         dtModule::get_time() const {
	return(this->_time);
}
void                dtModule::set_time(std::string time) {
	this->_time= "Time: " + time;
}

std::string			dtModule::get_day() const {
	return(this->_day);
}

void				dtModule::set_day(std::string day) {
	this->_day= "Day: " + day;
}

std::string			dtModule::get_week() const {
	return(this->_week);
}

void				dtModule::set_week(std::string week) {
	this->_week= "Week: " + week;
}

std::string			dtModule::get_year() const {
	return(this->_year);
}

void				dtModule::set_year(std::string year) {
	this->_year= "Year: " + year;
}

std::string			dtModule::get_month() const {
	return(this->_month);
}

void				dtModule::set_month(std::string month) {
	this->_month= "Month: " + month;
}
