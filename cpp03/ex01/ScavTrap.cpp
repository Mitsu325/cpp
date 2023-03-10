/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 06:12:53 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/24 19:46:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_name = "";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &scav_trap): ClapTrap(scav_trap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = scav_trap;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const &scav_trap)
{
	std::cout << "ScavTrap assigment operator called" << std::endl;
	if (this != &scav_trap)
	{
		this->_name = scav_trap.getName();
		this->_hit_points = scav_trap.getHitPoints();
		this->_energy_points = scav_trap.getEnergyPoints();
		this->_attack_damage = scav_trap.getAttackDamage();
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		std::cout << "ScavTrap " << this->_name << " attacks ";
		std::cout << target << ", causing " << this->_attack_damage;
		std::cout << " points of damage!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is out of energy" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode"
		<< std::endl;
}


std::ostream&	operator<<(std::ostream &stream, ScavTrap const &scav_trap)
{
	stream << "ScavTrap Name: " << scav_trap.getName() << std::endl;
	stream << "HP: " << scav_trap.getHitPoints() << " | ";
	stream << "EP: " << scav_trap.getEnergyPoints() << " | ";
	stream << "AD: " << scav_trap.getAttackDamage() << std::endl;
	return (stream);
}
