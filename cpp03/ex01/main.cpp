/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/24 19:52:13 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap marvin("Marvin");

		std::cout << marvin << std::endl;
		marvin.attack("foo");
		marvin.takeDamage(1);
		marvin.beRepaired(5);
		marvin.guardGate();
		std::cout << marvin << std::endl;
	}
	{
		std::cout << "==========================" << std::endl;
		ScavTrap marvin("Marvin");
		ClapTrap norm("Norm");

		std::cout << marvin << std::endl;
		std::cout << norm << std::endl;
		marvin.attack(norm.getName());
		norm.takeDamage(marvin.getAttackDamage());
		norm.beRepaired(50);
		marvin.guardGate();
		std::cout << marvin << std::endl;
		std::cout << norm << std::endl;
		while (marvin.getEnergyPoints() > 1)
			marvin.attack(norm.getName());
		std::cout << marvin << std::endl;
		marvin.takeDamage(99);
		marvin.beRepaired(5);
		marvin.guardGate();
		marvin.beRepaired(5);
		std::cout << marvin << std::endl;
	}
	return (0);
}
