/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:52:32 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 18:04:06 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule
{
public:
	virtual 		~IMonitorModule() {}
    virtual int		getMaxLvl() const = 0;
    virtual int		getMinLvl() const = 0;
    virtual void	setMinLvl(int lvl) = 0;
    virtual void	setMaxLvl(int lvl) = 0;
protected:
	IMonitorModule() : _minLvl(0), _maxLvl(0) {}
	IMonitorModule(int minLvl, int maxLvl) : _minLvl(minLvl), _maxLvl(maxLvl) {}
	int			_networkModuleLvl;
	int			_hostnameModuleLvl;
	int			_osModuleLvl;
	int			_dtModuleLvl;
	int			_HsModuleLvl;
	int			_currentModuleLvl;
	int			_minLvl;
	int			_maxLvl;
};

#endif
