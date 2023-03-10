/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:13:30 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/26 21:33:10 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	ClapTrap("_clap_name"),
	ScavTrap(""),
	FragTrap("")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ScavTrap::_energy_points = 50;
	this->_name = "";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	return ;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called: " << std::endl;
	ScavTrap::_energy_points = 50;
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy):
	ClapTrap(copy),
	ScavTrap(copy),
	FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &obj)
{
	std::cout << "DiamondTrap assigment operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_hit_points = obj.getHitPoints();
		this->_energy_points = obj.getEnergyPoints();
		this->_attack_damage = obj.getAttackDamage();
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap named " << this->_name
		<< " and I am originated from the ClapTrap named " << ClapTrap::_name
		<< "." << std::endl;
	return ;
}

std::string	DiamondTrap::getName(void) const
{
	return (this->_name);
}

std::ostream&	operator<<(std::ostream &stream, DiamondTrap const &diamond_trap)
{
	stream << "DiamondTrap Name: " << diamond_trap.getName() << std::endl;
	stream << "HP: " << diamond_trap.getHitPoints() << " | ";
	stream << "EP: " << diamond_trap.getEnergyPoints() << " | ";
	stream << "AD: " << diamond_trap.getAttackDamage() << std::endl;
	return (stream);
}
