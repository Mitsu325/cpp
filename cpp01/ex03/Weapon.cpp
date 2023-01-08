/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:30:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 17:48:22 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Weapon constructor" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor" << std::endl;
}

const std::string&	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
