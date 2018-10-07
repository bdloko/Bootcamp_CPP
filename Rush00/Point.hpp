/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmwalo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:41:24 by tmwalo            #+#    #+#             */
/*   Updated: 2018/06/10 15:12:52 by tmwalo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include <iostream>

class Point
{

	private:
		unsigned int	_y;
		unsigned int	_x;

	public:
		Point(void);
		Point(unsigned int y, unsigned int x);
		Point(Point const & src);
		~Point(void);
		Point &			operator=(Point const & rhs);
		unsigned int	getY(void) const;
		unsigned int	getX(void) const;
		void			setY(unsigned int val);
		void			setX(unsigned int val);

};

std::ostream &			operator<<(std::ostream & o, Point const & rhs);

#endif
