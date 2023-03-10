/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/24 21:15:05 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	marvin("Marvin");
	ScavTrap	selene("Selene");
	FragTrap	bill("Bill");
	FragTrap	bee("Bee");

	std::cout << marvin << std::endl;
	std::cout << selene << std::endl;
	std::cout << bill << std::endl;
	std::cout << bee << std::endl;
	bee.attack(bill.getName());
	bill.takeDamage(bee.getAttackDamage());
	bill.beRepaired(12);
	selene.guardGate();
	bill.highFivesGuys();
	std::cout << marvin << std::endl;
	std::cout << selene << std::endl;
	std::cout << bill << std::endl;
	std::cout << bee << std::endl;
	while (bee.getEnergyPoints() > 1)
		bee.attack(marvin.getName());
	std::cout << bee << std::endl;
	bee.takeDamage(99);
	bee.beRepaired(5);
	bee.highFivesGuys();
	bee.beRepaired(5);
	std::cout << bee << std::endl;
	return (0);
}
