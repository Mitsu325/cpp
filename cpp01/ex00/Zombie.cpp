/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:59:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 10:35:28 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	std::cout << "Zombie " << name << " constructor" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destructor" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
