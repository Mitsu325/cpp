/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:06:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:42:32 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONG_CAT_H

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &obj);
		~WrongCat(void);
		WrongCat&	operator=(WrongCat const &obj);

		void	makeSound(void) const;
};

std::ostream&	operator<<(std::ostream &stream, WrongCat const &obj);

#endif
