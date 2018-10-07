/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:47:45 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/07 17:48:10 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->_value = 0;
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
}

Fixed::Fixed(int const n) : _value(n << this->_bits) {
}

Fixed::Fixed(float const n) : _value(roundf(n * (1 << this->_bits))) {
}

Fixed::~Fixed(void) {
}

bool            Fixed::operator>( Fixed const & src ) {
	if (this->_value > src.getRawBits())
		return true;
	return false;
}

bool            Fixed::operator<( Fixed const & src ) {
	if (this->_value < src.getRawBits())
		return true;
	return false;
}

bool            Fixed::operator>=( Fixed const & src ) {
	if (this->_value >= src.getRawBits())
		return true;
	return false;
}

bool            Fixed::operator<=( Fixed const & src ) {
	if (this->_value <= src.getRawBits())
		return true;
	return false;
}

bool			Fixed::operator==( Fixed const & src ) {
	if (this->_value == src.getRawBits())
		return true;
	return false;
}

bool			Fixed::operator!=( Fixed const & src ) {
	if (this->_value != src.getRawBits())
		return true;
	return false;
}

Fixed &		Fixed::operator=(Fixed const & src) {
	this->_value = src.getRawBits();
	return *this;
}

Fixed		Fixed::operator+(Fixed const & src) {
	Fixed res = Fixed(*this);
	res.setRawBits(this->toFloat() + src.toFloat());
	return (res);
}

Fixed		Fixed::operator-(Fixed const & src) {
	Fixed res = Fixed(*this);
	res.setRawBits(this->toFloat() - src.toFloat());
	return (res);
}

Fixed 		Fixed::operator*(Fixed const & src) {
	Fixed res = Fixed(this->toFloat() * src.toFloat());
	return (res);
}

Fixed 		Fixed::operator/(Fixed const & src) {
	return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed 		Fixed::operator++(int) {
	Fixed holder = Fixed(*this);
	_value++;
	return (holder);
}

Fixed &		Fixed::operator++() {
   	++(_value);
	return (*this);
}

Fixed 		Fixed::operator--(int) {
	Fixed temp = Fixed(*this);
	_value--;
	return (temp);
}

Fixed &		Fixed::operator--() {
	--(_value);
	return (*this);

}

int			Fixed::getRawBits() const {
	return this->_value;
}

void		Fixed::setRawBits(int const raw ) {
	this->_value = raw;
}

float		Fixed::toFloat( void ) const {
	return this->_value / (float)(1 << this->_bits);
}

int			Fixed::toInt( void ) const {
	return this->_value / (1 << this->_bits);
}

Fixed const &       Fixed::max( Fixed const & fix1, Fixed const & fix2 ) {
	if (fix1.toFloat() > fix2.toFloat())
		return fix1;
	else
		return fix2;
}
Fixed const &       Fixed::min( Fixed const & fix1, Fixed const & fix2 ) {
	if (fix1.toFloat() < fix2.toFloat())
		return fix1;
	else
		return fix2;
}

Fixed &     min( Fixed & fix1, Fixed & fix2 ) {
	if (fix1.toFloat() < fix2.toFloat())
		return fix1;
	else
		return fix2;
}

Fixed &     max( Fixed & fix1, Fixed & fix2 ) {
	if (fix1.toFloat() > fix2.toFloat())
		return fix1;
	else
		return fix2;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
