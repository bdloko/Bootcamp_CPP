/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <ssibiya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:29:30 by ssibiya           #+#    #+#             */
/*   Updated: 2018/06/10 18:20:09 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "bullet.hpp"

class player
{
    private:
        char                _body;
        unsigned int        _x;
        unsigned int        _y;
        bullet              _cartridge[1000];
        bullet              _enemies[1000];
        bool                can_move();
    
    public:
        player();
        ~player();
        player( char body);
        player( player const &p1);
        
        player              &operator=( player const &p1);

        void                move(int ch);
        void                shoot();
        void                pauseGame();
        int                 get_x() const;
        int                 get_y() const;
        bool                canMove();
        void                loadCartridge( bullet *blt);
        void                loadEnemy(bullet *en);
        bullet              *getCartridge();
        bullet              *getEnemies();
};

#endif