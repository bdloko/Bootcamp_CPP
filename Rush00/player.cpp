/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <ssibiya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:29:12 by ssibiya           #+#    #+#             */
/*   Updated: 2018/06/10 18:24:53 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.hpp"
#include "bullet.hpp"
#include <ncurses.h>
#include <unistd.h>

player::player()
{
    this->_x = 5;
    this->_y = LINES / 2;
    this->_body = '>';
}
player::~player()
{
    std::cout << "Game Over" << std::endl;
}
player::player( char body )
{
    this->_body = body;
}

player::player( player const &p1)
{
    *this = p1;
}

player &player::operator=( player const &p1)
{
    this->_x = p1.get_x();
    this->_y = p1.get_y();
    return (*this);
}

bool    player::canMove()
{
    if (this->get_y() <= (LINES / 10) + 2)
    {
        this->_y += 5;
        return false;
    }
    else if (this->get_y() > (LINES - (LINES / 10) - 2))
    {
        this->_y -= 5;
        return false;
    }
    else if (this->get_x() <= 0)
    {
        this->_x += 5;
        return false;
    }
    else if (this->get_x() >= (COLS - 2))
    {
        this->_x -= 5;
        return false;
    }
    return true;
}

void    player::move(int ch)
{
    static int  num = 0;
    bullet en;
    if (canMove())
    {
        mvaddch(this->_y, this->_x, ' ');
        switch (ch)
        {
            case KEY_UP:
                // if (y > (LINES / 10))
                    this->_y--;
                    break;
            case KEY_DOWN:
                // if (y < (LINES - (LINES / 10)))
                    this->_y++;
                    break;
            case KEY_LEFT:
                // if (x != 5)
                    this->_x--;
                    break;
            case KEY_RIGHT:
                // if (x < (COLS - 5))
                    this->_x++;
                    break;  
            case ' ':
                shoot();
                break;
            case 'p':
                pauseGame();
                break;
        }
        if (canMove())
        {
            mvaddch(_y, _x, _body);
            if (num % 2 == 0)
            {
                mvaddch(en.getPos_y(), en.getPos_x(), en.getBullet());
                loadEnemy(&en);
            }
            num++;
        }
    }
    refresh();
}

void    player::shoot()
{
    bullet bullet((this->_x + 1), this->_y, 'O');
    loadCartridge(&bullet);
}

void    player::pauseGame()
{
    int ch;
    while(1)
    {
        attron(A_BLINK | A_BOLD);
        mvaddstr(LINES / 2, COLS / 2, "Game Paused");
        ch = getch();
        if (ch == 'p')
        {
            mvaddstr(LINES / 2, COLS / 2, "            ");
            break;
        }
    }
}

int     player::get_x() const
{
    return this->_x;
}

int     player::get_y() const
{
    return this->_y;
}

void player::loadCartridge(bullet *blt)
{
    static int i = 0;

    if (i == 999)
        i = 0;
    this->_cartridge[i] = *blt;
    i++;
}

void player::loadEnemy(bullet *en)
{
    static int i = 0;

    if (i == 999)
        i = 0;
    this->_cartridge[i] = *en;
    i++;
}

bullet  *player::getCartridge()
{
    return this->_cartridge;
}

bullet  *player::getEnemies()
{
    return this->_enemies;
}