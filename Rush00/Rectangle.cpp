/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rectangle.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmwalo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:41:02 by tmwalo            #+#    #+#             */
/*   Updated: 2018/06/10 11:41:06 by tmwalo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rectangle.hpp"

Rectangle::Rectangle(void)
{
	return ;
}

Rectangle::Rectangle(Point topLeftCoords, Point bottomRightCoords) :
				_topLeftCoords(topLeftCoords),
				_bottomRightCoords(bottomRightCoords)
{
	return ;
}

Rectangle::Rectangle(Rectangle const & src)
{
	*this = src;
	return ;
}

Rectangle::~Rectangle(void)
{
	return ;
}

Rectangle &		Rectangle::operator=(Rectangle const & rhs)
{
	this->_topLeftCoords = rhs.getTopLeftCoords();
	this->_bottomRightCoords = rhs.getBottomRightCoords();
	return (*this);
}

Point			Rectangle::getTopLeftCoords(void) const
{
	return (this->_topLeftCoords);
}

Point			Rectangle::getBottomRightCoords(void) const
{
	return (this->_bottomRightCoords);
}

void			Rectangle::setTopLeftCoords(Point val)
{
	this->_topLeftCoords = val;
	return ;
}

void			Rectangle::setBottomRightCoords(Point val)
{
	this->_bottomRightCoords = val;
	return ;
}
