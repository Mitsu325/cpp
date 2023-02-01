/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:14:44 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 22:33:12 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name("")
{
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = NULL;
	}
	std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(std::string name): _name(name)
{
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = NULL;
	}
	std::cout << "Character constructor called" << std::endl;
	return ;
}

Character::Character(Character const &obj)
{
	this->_name = obj._name;
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		if (obj._inventory[i])
		{
			this->_inventory[i] = obj._inventory[i]->clone();
		}
		else
		{
			this->_inventory[i] = NULL;
		}
	}
	std::cout << "Character copy constructor called" << std::endl;
	return ;
}

Character::~Character(void)
{
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << "Character " << this->_name << " destructor called"
		<< std::endl;
	return ;
}

Character&	Character::operator=(Character const &obj)
{
	this->_name = obj._name;
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		if (obj._inventory[i])
		{
			this->_inventory[i] = obj._inventory[i]->clone();
		}
	}
	std::cout << "Character assignment operator called" << std::endl;
	return (*this);
}

std::string const &	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	index;

	if (!m)
	{
		std::cout << this->_name << " tried to equip nothing..." << std::endl;
		return ;
	}
	index = 0;
	while (index < INVENTORY_SIZE && this->_inventory[index])
	{
		index++;
	}
	if (index < INVENTORY_SIZE)
	{
		this->_inventory[index] = m;
		std::cout << this->_name << " equipped materia "
			<< this->_inventory[index]->getType() << " in slots " << index
			<< std::endl;
	}
	else
		std::cout << this->_name << " can't equip more than " << INVENTORY_SIZE
			<< " Materia" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << this->_name << " tried to unequip nothing in slot " << idx
			<< std::endl;
	}
	else if (!this->_inventory[idx])
	{
		std::cout << this->_name << " has nothing equipped in slot " << idx
			<< " to unequip" << std::endl;
	}
	else
	{
		std::cout << this->_name << " unequip in slot " << idx
			<< std::endl;
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << this->_name << " tried to use nothing in slot " << idx
			<< std::endl;
	}
	else if (!this->_inventory[idx])
	{
		std::cout << this->_name << " has nothing equipped in slot " << idx
			<< " to use" << std::endl;
	}
	else
	{
		this->_inventory[idx]->use(target);
	}
}

AMateria*	Character::getMateria(int idx)
{
	return (this->_inventory)[idx];
}
