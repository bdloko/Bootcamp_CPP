/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:24:24 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/07 18:24:27 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const n) : _value(n * (1 << this->_bits)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _value(roundf(n * (1 << this->_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &		Fixed::operator=(Fixed const & src) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = src.getRawBits();
	return *this;
}

int			Fixed::getRawBits() const {
	return this->_value;
}

void		Fixed::setRawBits(int const a ) {
	this->_value = a;
}

float		Fixed::toFloat( void ) const {
	return this->_value / (float)( 1 << this->_bits);
}

int			Fixed::toInt( void ) const {
	return this->_value / ( 1 << this->_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
