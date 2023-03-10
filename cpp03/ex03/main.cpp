/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:42:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/26 20:51:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	bill("Bill");
	DiamondTrap	bee(bill);
	DiamondTrap	john("John");

	std::cout << bill << std::endl;
	std::cout << bee << std::endl;
	std::cout << john << std::endl;
	bee.attack(john.getName());
	john.takeDamage(bee.getAttackDamage());
	john.beRepaired(12);
	john.highFivesGuys();
	bee.guardGate();
	bill.whoAmI();
	bee.whoAmI();
	john.whoAmI();
	std::cout << bill << std::endl;
	std::cout << bee << std::endl;
	std::cout << john << std::endl;

	bill = john;

	std::cout << "================================" << std::endl;
	std::cout << bill << std::endl;
	std::cout << bee << std::endl;
	std::cout << john << std::endl;
	std::cout << "================================" << std::endl;

	while (bill.getEnergyPoints() > 1)
		bill.attack(john.getName());
	std::cout << bill << std::endl;
	bill.takeDamage(42);
	bill.beRepaired(5);
	bill.highFivesGuys();
	bill.beRepaired(5);
	std::cout << bill << std::endl;
	return (0);
}
