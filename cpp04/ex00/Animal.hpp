/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:08:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:42:53 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_H

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &obj);
		virtual ~Animal(void);
		virtual Animal&	operator=(Animal const &obj);

		virtual void		makeSound(void) const;
		const std::string&	getType(void) const;
};

std::ostream&	operator<<(std::ostream &stream, Animal const &obj);

#endif
