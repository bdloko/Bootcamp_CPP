/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDisplayModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:52:05 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:52:21 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDISPLAYMODULE_HPP
#define IDISPLAYMODULE_HPP

#include <ncurses.h>

class IDisplayModule
{
public:
	virtual ~IDisplayModule() {}
	virtual int getLenX() const = 0;
	virtual int getLenY() const = 0;
	
protected:
	IDisplayModule() {}
	IDisplayModule(int lenY, int lenX) : _lenY(lenY), _lenX(lenX) {}
	int				_lenY;
	int				_lenX;
};

#endif
