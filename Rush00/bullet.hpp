/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <ssibiya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 17:08:11 by ssibiya           #+#    #+#             */
/*   Updated: 2018/06/10 18:23:25 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

#include <ncurses.h>

class bullet
{
    private:
        unsigned int        _pos_x;
        unsigned int        _pos_y;
        char                _bullet;
    
    public:
        bullet();
        bullet(int x, int y, char bullet);
        ~bullet();

        bullet              &operator=( bullet const &blt );
        bullet              &operator!=( bullet const &blt );
        void                update(int dir);
        char                getBullet() const;
        unsigned int        getPos_x() const;
        unsigned int        getPos_y() const;
        unsigned int        getRandomY();
};

#endif
