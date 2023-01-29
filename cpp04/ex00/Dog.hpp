/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:06:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:43:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_H

# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(Dog const &obj);
		~Dog(void);
		Dog&	operator=(Dog const &obj);

		void	makeSound(void) const;
};

std::ostream&	operator<<(std::ostream &stream, Dog const &obj);

#endif
