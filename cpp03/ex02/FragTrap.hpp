/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:06:08 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/24 21:18:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAG_TRAP_H

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string new_name);
		FragTrap(FragTrap const &scav_trap);
		~FragTrap(void);
		FragTrap&	operator=(FragTrap const &scav_trap);

		void	highFivesGuys(void);
};

std::ostream&	operator<<(std::ostream &stream, FragTrap const &scav_trap);

#endif
