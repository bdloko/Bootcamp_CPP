#include <ncurses.h>
#include <iostream>
#include "map.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "Enemy.hpp"
#include <unistd.h>

void	updatebullets(bullet *cartridge, bullet *en_bullet)
{
	int i = 0;
	while (cartridge[i].getPos_x() > 0)
	{
		// if (cartridge[i].getBullet() == 'O')
		cartridge[i].update(1);
		i++;
	}
	i = 0;
	while (en_bullet[i].getPos_x() > 0 )
	{
		en_bullet[i].update(2);
		i++;
	}
}

void	check_window_size()
{
	int	i;
	int j;

	getmaxyx(stdscr, i, j);
	while (i < 50 || j < 200)
	{
		clear();
		getmaxyx(stdscr, i, j);
		mvprintw((LINES / 2) + 2, COLS / 2, "Window needs to be at least 50 chars high and 200 chars long");
		mvprintw(LINES / 2, COLS / 2, "Window size is: %d x %d", j, i);
		refresh();
	}
	clear();
}


void	init_enemies(bullet *en_bullet)
{
	bullet bul;
	for (int i = 0; i < 9; i++)
	{
		en_bullet[i] = bul;
		mvaddch(en_bullet[i].getPos_y(), en_bullet[i].getPos_x(), en_bullet[i].getBullet());
	}
}

int main() 
{
	int			ch;
	int			x;
	int			y;
	map 		game_map;
	player		player1;
	std::string	name;
	bullet		en_bullet[10];
	bullet		en(COLS - 2, LINES / 2, 'Z');

	ch = 0;
	while (1) 
	{
		check_window_size();
		clear();
		game_map.draw_map();
		game_map.intro(ch);
		x = 0;
		y = LINES / 2;
		init_enemies(en_bullet);
		while (ch != 'q' && ch != 'Q')
		{
			check_window_size();
			game_map.draw_map();
			ch = getch();
			updatebullets(player1.getCartridge(), player1.getEnemies());
			player1.move(ch);
			refresh();
			usleep(10000);
		}
	}
	endwin();
	return 0;
}
