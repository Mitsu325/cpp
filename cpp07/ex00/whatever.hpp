/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:57:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/13 20:51:48 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>
# include <string>

template<typename T>
void	swap(T &x, T &y)
{
	T	temp;

	temp = x;
	x = y;
	y = temp;
}

template<typename T>
T	min(T x, T y)
{
	return (x < y ? x : y);
}

template<typename T>
T	max(T x, T y)
{
	return (x > y ? x : y);
}

#endif
