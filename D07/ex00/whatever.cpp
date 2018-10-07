/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdloko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:49:31 by bdloko            #+#    #+#             */
/*   Updated: 2018/06/14 13:31:05 by bdloko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
T const &	max(T const & x, T const & y) {
	return(x>y ? x : y);
}

template<typename T>
T const &	min(T const & x, T const & y) {
	return(x<y ? x : y);
}

template<typename T>
void	swap(T & x, T & y) {
	T temp;
	temp = x;
	x = y;
	y = temp;
}
