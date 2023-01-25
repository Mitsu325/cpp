/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 06:07:31 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/24 19:45:53 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAV_TRAP_H

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string new_name);
		ScavTrap(ScavTrap const &scav_trap);
		~ScavTrap(void);
		ScavTrap&	operator=(ScavTrap const &scav_trap);

		void	attack(const std::string& target);
		void	guardGate(void);
};

std::ostream&	operator<<(std::ostream &stream, ScavTrap const &scav_trap);

#endif
