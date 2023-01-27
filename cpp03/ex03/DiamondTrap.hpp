/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:09:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/26 19:58:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMOND_TRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string new_name);
		DiamondTrap(DiamondTrap const &diamond_trap);
		~DiamondTrap(void);
		DiamondTrap&	operator=(DiamondTrap const &diamond_trap);

		void	attack(const std::string& target);
		void	whoAmI();
		std::string	getName(void) const;
};

std::ostream&	operator<<(std::ostream &stream, DiamondTrap const &diamond_trap);

#endif
