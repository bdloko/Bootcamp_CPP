/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:48:28 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/07 17:48:43 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <stdlib.h>
#include <cmath>

class Fixed {

public:
    Fixed();
    Fixed( Fixed const & src );
    Fixed( const int n);
    Fixed( const float n);
    ~Fixed();

    int				getRawBits( void ) const;
    void			setRawBits( int const raw );
    float			toFloat( void ) const;
    int				toInt( void ) const;
    bool            operator>( Fixed const & src );
    bool            operator<( Fixed const & src );
    bool            operator>=( Fixed const & src );
    bool            operator<=( Fixed const & src );
    bool            operator==( Fixed const & src );
    bool            operator!=( Fixed const & src );
    Fixed &			operator=( Fixed const & src );
    Fixed           operator+( Fixed const & src );
    Fixed           operator-( Fixed const & src );
    Fixed           operator*( Fixed const & src );
    Fixed           operator/( Fixed const & src );
    Fixed &         operator++();
    Fixed &         operator--();
    Fixed           operator++(int);
    Fixed           operator--(int);
    static Fixed const &   min( Fixed const & fix1, Fixed const & fix2 );
    static Fixed const &   max( Fixed const & fix1, Fixed const & fix2 );

private:
    int					_value;
    static int const	_bits = 8;
};

std::ostream &      operator<<( std::ostream & o, Fixed  const & rhs);
Fixed &             max( Fixed & fix1, Fixed & fix2 );
Fixed &             min( Fixed & fix1, Fixed & fix2 );

#endif
