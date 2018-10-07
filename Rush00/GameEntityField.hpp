/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntityField.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmwalo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:14:57 by tmwalo            #+#    #+#             */
/*   Updated: 2018/06/10 16:15:22 by tmwalo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITYFIELD_H
# define GAMEENTITYFIELD_H
# include "Enemy.hpp"
# include "Rectangle.hpp"

class GameEntityField
{

	private:
		Enemy					_field[10];
		Rectangle				_gameBounds;

	public:
		GameEntityField(void);
		GameEntityField(Rectangle gameBounds);
		GameEntityField(GameEntityField const & src);
		~GameEntityField(void);
		GameEntityField  &		operator=(GameEntityField const & rhs);
		Rectangle				getGameBounds(void) const;
		void					resetEnemyPos(unsigned int index);

};

#endif
