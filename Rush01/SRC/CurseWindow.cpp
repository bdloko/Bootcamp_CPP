/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurseWindow.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:49:22 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:49:25 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/CurseWindow.hpp"

CurseWindow::CurseWindow(int lenY, int lenX) : IDisplayModule(lenY, lenX)
{
	this->_halfY = this->_lenY/2;
	this->_halfX = this->_lenX/2;
	this->_startY = 0;
	this->_startX = 0;
	this->_win = newwin(_lenY, _lenX, _startY, _startX);
	box(this->_win, 0, 0);
	
}

CurseWindow::CurseWindow(int lenY, int lenX, int startY, int startX) : IDisplayModule(lenY, lenX)
{
	this->_halfY = this->_lenY/2;
	this->_halfX = this->_lenX/2;
	this->_startY = startY;
	this->_startX = startX;
	this->_win = newwin(_lenY, _lenX, _startY, _startX);
	box(this->_win, 0, 0);
}

CurseWindow::CurseWindow() {}

CurseWindow::CurseWindow(CurseWindow const & src)
{
	*this = src;
}

CurseWindow::~CurseWindow() {}

CurseWindow & 	CurseWindow::operator=(CurseWindow const & src)
{
	this->_lenY = src.getLenY();
	this->_lenX = src.getLenX();
	this->_halfY = src.getHalfY();
	this->_halfX = src.getHalfX();
	this->_startY = src.getStartY();
	this->_startX = src.getStartX();
	this->_win = src.getWindow();
	box(this->_win, 0, 0);
	return *this;
}

int 		CurseWindow::getLenX() const
{
	return this->_lenX;
}

int 		CurseWindow::getLenY() const
{
	return this->_lenY;
}

int 		CurseWindow::getHalfX() const
{
	return this->_halfX;
}

int 		CurseWindow::getHalfY() const
{
	return this->_halfY;
}

int 		CurseWindow::getStartX() const
{
	return this->_startX;
}

int 		CurseWindow::getStartY() const
{
	return this->_startY;
}

int 		CurseWindow::getMidX(int len) const
{
	return (this->_halfX - len/2);
}

int 		CurseWindow::getMidY(int len) const
{
	return (this->_halfY - len/2);
}

WINDOW * 		CurseWindow::getWindow() const
{
	return (this->_win);
}

void 		CurseWindow::setWindow(WINDOW *win)
{
	this->_win = win;
}

void 		CurseWindow::setLenX(int n)
{
	this->_lenX = n;
}
void		CurseWindow::setLenY(int n)
{
	this->_lenY = n;
}
void		CurseWindow::setHalfX(int n)
{
	this->_halfX = n;
}
void		CurseWindow::setHalfY(int n)
{
	this->_halfY = n;
}
void		CurseWindow::setStartX(int n)
{
	this->_startX = n;
}

void		CurseWindow::setStartY(int n)
{
	this->_startY = n;
}

void		CurseWindow::resizeWin(int newY, int newX)
{
	this->_lenY = newY;
	this->_lenX = newX;
	this->_halfY = _lenY/2;
	this->_halfX = _lenX/2;
	wresize(this->_win, _lenY, _lenX);
}

void		CurseWindow::moveWin(int newY, int newX)
{
	this->_startY = newY;
	this->_startX = newX;
	mvwin(this->_win, _startY, _startX);
}

void		CurseWindow::clearWin()
{
	wclear(this->_win);

}

void		CurseWindow::refreshWin()
{
	wrefresh(this->_win);
}

void		CurseWindow::refreshClearWin()
{
	clearWin();
	box(this->_win, 0, 0);
	wrefresh(this->_win);
}

int		CurseWindow::moveCursorWin(int x, int y)
{
	return wmove(this->_win, y, x);
}
