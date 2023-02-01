/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:12:57 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 21:52:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_H
# define CHARACTER_H

# include "AMateria.hpp"
# include "ICharacter.hpp"
# define INVENTORY_SIZE 4

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[INVENTORY_SIZE];

	public:
		Character(void);
		Character(std::string name);
		Character(Character const &obj);
		~Character(void);
		Character&	operator=(Character const &obj);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria*	getMateria(int idx);
};

#endif
