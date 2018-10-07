/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:24:38 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/07 18:24:40 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <stdlib.h>
#include <cmath>

class Fixed {

public:
    Fixed(void);
    Fixed( Fixed const & src );
    Fixed( const int n);
    Fixed( const float n);
    ~Fixed();

    int				getRawBits( void ) const;
    void			setRawBits( int const a);
    float			toFloat( void ) const;
    int				toInt( void ) const;
    Fixed &			operator=( Fixed const & src );

private:
    int					_value;
    static int const	_bits = 8;
};

std::ostream &  operator<<( std::ostream & o, Fixed  const & rhs);

#endif
