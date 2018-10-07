/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurseWindow.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:51:43 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/17 13:51:46 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSEWINDOW_HPP
#define CURSEWINDOW_HPP

#include "IDisplayModule.hpp"

class CurseWindow : public IDisplayModule
{
public:
	CurseWindow(CurseWindow const & src);
    CurseWindow(int lenY, int lenX);
    CurseWindow(int lenY, int lenX, int startY, int startX);
    ~CurseWindow();
    CurseWindow & 	operator=(CurseWindow const & src);
	int 			getLenX() const;
	int 			getLenY() const;
	int 			getHalfX() const;
	int 			getHalfY() const;
	int 			getStartX() const;
	int 			getStartY() const;
	int 			getMidX(int len) const;
	int 			getMidY(int len) const;
	WINDOW *		getWindow() const;
	void 			setWindow(WINDOW *win);
	void			setLenX(int n);
	void			setLenY(int n);
	void			setHalfX(int n);
	void			setHalfY(int n);
	void			setStartX(int n);
	void			setStartY(int n);
	void			resizeWin(int newY, int newX);
	void			moveWin(int newY, int newX);
	void			clearWin();
	void			refreshWin();
	void			refreshClearWin();
	int				moveCursorWin(int x, int y);
    
    
private:
	CurseWindow();
	WINDOW 			*_win;
	int				_halfX;
	int				_halfY;
	int				_startX;
	int				_startY;
};

#endif
