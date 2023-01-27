/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:07:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/26 20:48:10 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
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
	this->_name = frag_trap.getName();
	this->_hit_points = frag_trap.getHitPoints();
	this->_energy_points = frag_trap.getEnergyPoints();
	this->_attack_damage = frag_trap.getAttackDamage();
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " request a positive high fives"
		<< std::endl;
}


std::ostream&	operator<<(std::ostream &stream, FragTrap const &frag_trap)
{
	stream << "FragTrap Name: " << frag_trap.getName() << std::endl;
	stream << "HP: " << frag_trap.getHitPoints() << std::endl;
	stream << "EP: " << frag_trap.getEnergyPoints() << std::endl;
	stream << "AD: " << frag_trap.getAttackDamage() << std::endl;
	return (stream);
}
