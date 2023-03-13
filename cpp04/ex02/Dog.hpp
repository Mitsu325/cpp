/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:06:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 19:58:25 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		Brain*	brain;

	public:
		Dog(void);
		Dog(Dog const &obj);
		~Dog(void);
		Dog&		operator=(Dog const &obj);
		AAnimal&	operator=(AAnimal const &obj);

		void	makeSound(void) const;
		void	printIdeas(void) const;
		void	addIdea(std::string idea);
		Brain*	getBrain(void) const;
};

std::ostream&	operator<<(std::ostream &stream, Dog const &obj);

#endif
