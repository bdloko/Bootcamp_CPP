/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmwalo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:42:04 by tmwalo            #+#    #+#             */
/*   Updated: 2018/06/10 17:12:02 by tmwalo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "bullet.hpp"
#include <ncurses.h>

Enemy::Enemy()
{
    this->_body = 'Z';
    this->_x = COLS - 2;
    this->_y = LINES / 2;//getRandomY();
    mvaddch(this->get_y(), this->get_x(), this->get_body());
}
Enemy::~Enemy()
{
    return ;
}
Enemy::Enemy( char body )
{
    this->_body = body;
    this->_x = COLS - 2;
    this->_y = getRandomY();
    mvaddch(this->get_y(), this->get_x(), this->get_body());
}
Enemy::Enemy( Enemy const &p1)
{
    *this = p1;
}

Enemy &Enemy::operator=( Enemy const &p1)
{
    this->_body = p1.get_body();
    return (*this);
}

int     Enemy::getRandomY()
{
    int		randYPos;
	int		top_bound;
	int		bottom_bound;

	top_bound = LINES / 10;
	bottom_bound = LINES - top_bound;
	std::srand(time(NULL));
	randYPos = std::rand() % (bottom_bound - top_bound) + top_bound;
    mvprintw(50, 50, "Random: %d", randYPos);
    return randYPos;
}

/*void    Enemy::move(int y, int x)
{
    mvaddch(this->_y, this->_x, ' ');
    mvaddch(_y, _x, _body);
    refresh();
}*/

void    Enemy::update()
{
    mvaddch(this->_y, this->_x - 1, ' ');
    this->_x -= 1;
    mvaddch(this->_y, this->_x, _body);
}

int     Enemy::get_x(void) const
{
    return this->_x;
}

int     Enemy::get_y(void) const
{
    return this->_y;
}

char    Enemy::get_body(void) const
{
    return this->_body;
}
