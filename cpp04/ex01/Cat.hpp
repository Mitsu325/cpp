/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:06:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 18:59:28 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain*	brain;

	public:
		Cat(void);
		Cat(Cat const &obj);
		~Cat(void);
		Cat&	operator=(Cat const &obj);
		Animal&	operator=(Animal const &obj);

		void	makeSound(void) const;
		void	printIdeas(void) const;
		void	addIdea(std::string idea);
		Brain*	getBrain(void) const;
};

std::ostream&	operator<<(std::ostream &stream, Cat const &obj);

#endif
