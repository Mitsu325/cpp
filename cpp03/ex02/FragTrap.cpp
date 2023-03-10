/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:07:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/24 21:18:17 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_name = "";
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_name = name;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const &scav_trap): ClapTrap(scav_trap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = scav_trap;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=(FragTrap const &frag_trap)
{
	std::cout << "FragTrap assigment operator called" << std::endl;
	if (this != &frag_trap)
	{
		this->_name = frag_trap.getName();
		this->_hit_points = frag_trap.getHitPoints();
		this->_energy_points = frag_trap.getEnergyPoints();
		this->_attack_damage = frag_trap.getAttackDamage();
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		std::cout << "FragTrap " << this->_name << " attacks ";
		std::cout << target << ", causing " << this->_attack_damage;
		std::cout << " points of damage!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " is out of energy" << std::endl;
}


void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " request a positive high fives"
		<< std::endl;
}


std::ostream&	operator<<(std::ostream &stream, FragTrap const &frag_trap)
{
	stream << "FragTrap Name: " << frag_trap.getName() << std::endl;
	stream << "HP: " << frag_trap.getHitPoints() << " | ";
	stream << "EP: " << frag_trap.getEnergyPoints() << " | ";
	stream << "AD: " << frag_trap.getAttackDamage() << std::endl;
	return (stream);
}
