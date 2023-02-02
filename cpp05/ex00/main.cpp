/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/23 21:11:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap marvin("Marvin");
	ClapTrap norm("Norm");

	marvin.setAttackDamage(7);

	std::cout << marvin << std::endl;
	std::cout << norm << std::endl;

	marvin.attack(norm.getName());
	norm.takeDamage(marvin.getAttackDamage());

	std::cout << marvin << std::endl;
	std::cout << norm << std::endl;

	norm.beRepaired(5);

	std::cout << marvin << std::endl;
	std::cout << norm << std::endl;

	return (0);
}
