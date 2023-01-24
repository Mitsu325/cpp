/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:05:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/23 21:02:12 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAP_TRAP_H

# include <string>
# include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		ClapTrap(void);
		ClapTrap(std::string new_name);
		ClapTrap(ClapTrap const &clap_trap);
		~ClapTrap(void);
		ClapTrap&	operator=(ClapTrap const &clap_trap);

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		void			setName(std::string name);
		void			setHitPoints(unsigned int hit_points);
		void			setEnergyPoints(unsigned int energy_points);
		void			setAttackDamage(unsigned int attack_damage);
};

std::ostream&	operator<<(std::ostream &stream, ClapTrap const &clap_trap);

#endif
