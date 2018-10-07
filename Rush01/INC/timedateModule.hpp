/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timedateModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:53:12 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:53:18 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEDATEMODULE_HPP
#define TIMEDATEMODULE_HPP

#include <iostream>

#include "IMonitorModule.hpp"

class dtModule : public IMonitorModule
{
public:
	dtModule();
	dtModule(dtModule const & src);
    ~dtModule();
    dtModule & 	operator=(dtModule const & src);
    int					getdtModuleLvl() const;
	int					getMaxLvl() const;
	int					getMinLvl() const;
	void				setMaxLvl(int lvl);
	void				setMinLvl(int lvl);
    void				setdtModuleLvl(int lvl);

    std::string         get_date() const;
    void                set_date(std::string date);

    std::string         get_time() const;
    void                set_time(std::string time);

	std::string			get_day() const;
	void				set_day(std::string day);

	std::string			get_week() const;
	void				set_week(std::string week);

	std::string			get_month() const;
	void				set_month(std::string month);

	std::string			get_year() const;
	void				set_year(std::string year);

private:
    std::string         _date;
    std::string         _time;
	std::string			_day;
	std::string			_week;
	std::string			_year;
	std::string			_month;
};

#endif
