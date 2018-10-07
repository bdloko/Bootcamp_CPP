/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <ssibiya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 17:12:56 by ssibiya           #+#    #+#             */
/*   Updated: 2018/06/10 18:27:13 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "player.hpp"
#include "bullet.hpp"
#include <unistd.h>

bullet::bullet()
{
    this->_pos_x = COLS - 5;
    this->_pos_y = getRandomY();
    this->_bullet = 'Z';
}

bullet::bullet(int x, int y, char bullet)
{
    this->_pos_x = x;
    this->_pos_y = y;
    this->_bullet = bullet;
    mvaddch(y, x, _bullet);
}

bullet::~bullet()
{
    
}

bullet &bullet::operator=( bullet const &blt)
{
    this->_bullet = blt.getBullet();
    this->_pos_x = blt.getPos_x();
    this->_pos_y = blt.getPos_y();
    return (*this);
}

void    bullet::update(int dir)
{
    if (dir == 1)
    {
        this->_pos_x += 1;
        mvaddch(this->_pos_y, this->_pos_x, _bullet);
        mvaddch(this->_pos_y, this->_pos_x - 1, ' ');
    }
    if (dir == 2)
    {
        this->_pos_x -= 1;
        mvaddch(this->_pos_y, this->_pos_x, _bullet);
        // mvaddch(this->_pos_y, this->_pos_x + 1, ' ');
    }
    
}

unsigned int bullet::getPos_x() const
{
    return (this->_pos_x);
}

unsigned int bullet::getPos_y() const
{
    return (this->_pos_y);
}

char bullet::getBullet() const
{
    return (this->_bullet);
}

unsigned int     bullet::getRandomY()
{
    int		randYPos;
	int		top_bound;
	int		bottom_bound;

	top_bound = LINES / 10;
	bottom_bound = LINES - top_bound;
	std::srand(time(NULL));
	randYPos = std::rand() % (bottom_bound - top_bound) + top_bound;
    // mvprintw(50, 50, "Random: %d", randYPos);
    return randYPos;
}