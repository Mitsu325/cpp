/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:09:46 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/13 21:30:24 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_H
# define ITER_H

# include <iostream>
# include <string>

template<typename T>
void	iter(T *arr, size_t size, void (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

template<typename T>
void	put(T &x)
{
	std::cout << x << std::endl;
}

#endif
