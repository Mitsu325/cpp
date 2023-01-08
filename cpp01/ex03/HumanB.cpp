/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:35:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 20:34:59 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{
	std::cout << "HumanB " << name << " constructor" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << name << " destructor" << std::endl;
}

void	HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their "
		<< this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
