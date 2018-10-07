/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <ssibiya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:21:48 by ssibiya           #+#    #+#             */
/*   Updated: 2018/06/10 17:40:06 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include "Enemy.hpp"

class map
{
    private:
        static const char   _sky = 'u';
        static const char   _ground = 'x';
        // Enemy               _enemies[10];
    
    public:
        map();
        ~map();

        void        draw_map();
        void        intro(int ch);
        void        close();
        //void        createEnemy();
        //void        loadEnemy(enemy *en);
        // enemy       *getEnemies();
};

#endif