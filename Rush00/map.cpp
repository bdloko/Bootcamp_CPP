/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <ssibiya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:21:56 by ssibiya           #+#    #+#             */
/*   Updated: 2018/06/10 17:42:10 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "map.hpp"
#include "Enemy.hpp"

map::map()
{
    initscr();
    cbreak();
    noecho();
    clear();
    refresh();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    curs_set(0);
    if (!has_colors())
    {
        endwin();
        std::cout << "ERROR: Terminal does not support color." << std::endl;
        exit(1);
    }
    start_color();
    box(stdscr, 0, 0);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(1));
}

map::~map()
{
    endwin();
}

void    map::draw_map()
{
    attroff(A_REVERSE | A_BLINK);
    move(0, 0);
    int x;
    int y;
    for (y = 0; y < (LINES / 10); y++) //sky
        mvhline(y, 0, this->_sky, COLS);
    for (x = LINES; x >= (LINES - (LINES / 10)); x--) //ground
        mvhline(x, 0, this->_ground, COLS);
    refresh();
}

void    map::intro(int ch)
{
    int x;
    int y;

    y = LINES / 5;
    x = COLS / 3;

    mvhline(y, x, '*', 75);
    for (int i = 0 ; i < 20; i++)
    {
        mvaddch(y, x, '*');
        mvaddch(y, (x + 75), '*');
        y++;
    }
    mvhline(y, x, '*', 75);
    ch = getch();
    move(10, (x + 20));
    attron(A_BOLD | A_BLINK);

    addstr("Welcome To Rush00, Press Enter To Start");
    while (ch != '\n')
    {
        ch = getch();
    }
    clear();
    refresh();
}

/*void map::createEnemy()
{
    enemy enemy;

    loadEnemy(&enemy);
}

void map::loadEnemy(enemy *en)
{
    static int i = 0;

    if (i == 9)
        i = 0;
    this->_enemies[i] = *en;
    i++;
}

enemy  *map::getEnemies()
{
    return this->_enemies;
}*/
