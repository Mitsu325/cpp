/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:49:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/15 20:15:45 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>

class NotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return ("* Not Found *");
		};
};

template<typename T>
typename T::iterator	easyfind(T type, int num)
{
	typename T::iterator	it;

	it = std::find(type.begin(), type.end(), num);
	if (it == type.end())
		throw NotFoundException();
	return (it);
}

#endif
