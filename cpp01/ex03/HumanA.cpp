/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:54:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 20:34:44 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon_ref(weapon)
{
	std::cout << "HumanA " << name << " constructor" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << name << " destructor" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their "
		<< this->weapon_ref.getType() << std::endl;
}
