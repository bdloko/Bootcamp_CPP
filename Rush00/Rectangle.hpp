/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rectangle.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <ssibiya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:41:13 by tmwalo            #+#    #+#             */
/*   Updated: 2018/06/10 17:45:03 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_H
# define RECTANGLE_H

#include "Point.hpp"

class Rectangle
{

	private:
		Point	_topLeftCoords;
		Point	_bottomRightCoords;

	public:
		Rectangle(void);
		Rectangle(Point topLeftCoords, Point topRightCoords);
		Rectangle(Rectangle const & src);
		~Rectangle(void);
		Rectangle &		operator=(Rectangle const & rhs);
		Point			getTopLeftCoords(void) const;
		Point			getBottomRightCoords(void) const;
		void			setTopLeftCoords(Point topLeftCoords);
		void			setBottomRightCoords(Point bottomRightCoords);

};

#endif
