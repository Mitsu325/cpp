/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:06:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 17:43:56 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain*	brain;

	public:
		Dog(void);
		Dog(Dog const &obj);
		~Dog(void);
		Dog&	operator=(Dog const &obj);

		void	makeSound(void) const;
		void	printIdeas(void) const;
		void	addIdea(std::string idea);
		Brain*	getBrain(void) const;
};

std::ostream&	operator<<(std::ostream &stream, Dog const &obj);

#endif
