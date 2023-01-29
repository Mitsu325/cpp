/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:08:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 17:43:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_H

# include <string>
# include <iostream>

# include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &obj);
		virtual ~Animal(void);
		Animal&	operator=(Animal const &obj);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
		virtual void	printIdeas(void) const = 0;
		virtual void	addIdea(std::string idea) = 0;
		virtual Brain*	getBrain(void) const = 0;
};

std::ostream&	operator<<(std::ostream &stream, Animal const &obj);

#endif
