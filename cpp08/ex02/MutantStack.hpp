/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:28:56 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/25 16:37:50 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

# include <stack>
# include <deque>
# include <algorithm>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(MutantStack const &obj): std::stack<T>(obj) {};
		~MutantStack() {};
		MutantStack&	operator=(MutantStack const &obj)
		{
			if (this != &obj) {
				std::stack<T>::operator=(obj);
			}
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin()
		{
			return this->c.begin();
		}

		iterator	end()
		{
			return this->c.end();
		}
};

#endif
