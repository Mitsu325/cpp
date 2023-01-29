/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:08:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 19:55:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_H

# include <string>
# include <iostream>

# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const &obj);
		virtual ~AAnimal(void);
		virtual AAnimal&	operator=(AAnimal const &obj);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
		virtual void	printIdeas(void) const = 0;
		virtual void	addIdea(std::string idea) = 0;
		virtual Brain*	getBrain(void) const = 0;
};

std::ostream&	operator<<(std::ostream &stream, AAnimal const &obj);

#endif
