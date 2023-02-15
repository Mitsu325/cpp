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
typename T::iterator	easyfind(T &container, int num)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif
