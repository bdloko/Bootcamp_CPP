/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntityField.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <ssibiya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:35:47 by tmwalo            #+#    #+#             */
/*   Updated: 2018/06/10 17:45:50 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntityField.hpp"
#include <iostream>
#include <ncurses.h>

GameEntityField::GameEntityField(void)
{
	return ;
}

GameEntityField::GameEntityField(Rectangle gameBounds) : _gameBounds(gameBounds)
{
	return ;
}

GameEntityField::GameEntityField(GameEntityField const & src)
{
	*this = src;
	return ;
}

GameEntityField::~GameEntityField(void)
{
	return ;
}

GameEntityField &			GameEntityField::operator=(GameEntityField const & rhs)
{
	this->_gameBounds = rhs.getGameBounds();
	return (*this);
}

Rectangle					GameEntityField::getGameBounds(void) const
{
	return (this->_gameBounds);
}

void						GameEntityField::resetEnemyPos(unsigned int index)
{
	int		randYPos;
	int		top_bound;
	int		bottom_bound;

	top_bound = LINES / 10;
	bottom_bound = LINE - top_bound;
	std::srand(time(NULL));
	randYPos = std::rand() % (bottom_bound - top_bound) + top_bound;
	((this->_field)[index])._x -= 1;
	if (((this->_field)[index])._x == 0)
	{
		(this->_field[index])._x = COLS - 2;
		(this->_field[index])._x = randYPos - 2;
	}
}

void						GameEntityField::update(void)
{
	for (int index = 0; index < 10; i++)
	{
		this->resetEnemyPos(index);
	}
}
