/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:08:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/24 19:51:28 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name(""),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &clap_trap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clap_trap;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &clap_trap)
{
	std::cout << "ClapTrap assigment operator called" << std::endl;
	if (this != &clap_trap)
	{
		this->_name = clap_trap.getName();
		this->_hit_points = clap_trap.getHitPoints();
		this->_energy_points = clap_trap.getEnergyPoints();
		this->_attack_damage = clap_trap.getAttackDamage();
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks ";
		std::cout << target << ", causing " << this->_attack_damage;
		std::cout << " points of damage!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is out of energy" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount;
		std::cout << " points of damage!" << std::endl;
		if (amount > this->_hit_points)
			this->_hit_points = 0;
		else
			this->_hit_points -= amount;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is out of energy" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_hit_points += amount;
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " is repaired by " << amount;
		std::cout << " points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is out of energy" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attack_damage);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hit_points)
{
	this->_hit_points = hit_points;
}

void	ClapTrap::setEnergyPoints(unsigned int energy_points)
{
	this->_energy_points = energy_points;
}

void	ClapTrap::setAttackDamage(unsigned int attack_damage)
{
	this->_attack_damage = attack_damage;
}

std::ostream&	operator<<(std::ostream &stream, ClapTrap const &clap_trap)
{
	stream << "ClapTrap Name: " << clap_trap.getName() << std::endl;
	stream << "HP: " << clap_trap.getHitPoints() << " | ";
	stream << "EP: " << clap_trap.getEnergyPoints() << " | ";
	stream << "AD: " << clap_trap.getAttackDamage() << std::endl;
	return (stream);
}
