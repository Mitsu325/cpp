/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:08:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:28:40 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONG_ANIMAL_H

# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &obj);
		~WrongAnimal(void);
		WrongAnimal&	operator=(WrongAnimal const &obj);

		void			makeSound(void) const;
		std::string		getType(void) const;
};

std::ostream&	operator<<(std::ostream &stream, WrongAnimal const &obj);

#endif
