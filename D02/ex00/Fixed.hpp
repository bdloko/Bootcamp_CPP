/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:23:15 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/07 18:23:21 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

public:
    Fixed(void);
    Fixed( Fixed const & src );
    ~Fixed(void);

    int			getRawBits( void ) const;
    void		setRawBits( int const raw );
    Fixed &		operator=( Fixed const & src );


private:
    int					_value;
    static int const	_bits = 8;
};

#endif
