/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:06:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:43:02 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_H

# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(Cat const &obj);
		~Cat(void);
		Cat&	operator=(Cat const &obj);

		void	makeSound(void) const;
};

std::ostream&	operator<<(std::ostream &stream, Cat const &obj);

#endif
