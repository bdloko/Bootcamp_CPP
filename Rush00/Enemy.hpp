/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmwalo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:40:25 by tmwalo            #+#    #+#             */
/*   Updated: 2018/06/10 17:11:20 by tmwalo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include <iostream>
# include <ncurses.h>

class Enemy
{
    private:
        char                _body;
        unsigned int        _x;
        unsigned int        _y;
    
    public:
        Enemy();
        ~Enemy();
        Enemy( char body );
        Enemy( Enemy const &p1);
        
        Enemy              &operator=( Enemy const &p1);

        //void                move(int y, int x);
        void                update();
        int                 get_x(void) const;
        int                 get_y(void) const;
        char                get_body(void) const;
        int                 getRandomY();
};

#endif
