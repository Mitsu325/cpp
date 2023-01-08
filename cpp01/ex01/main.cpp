/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:25:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 13:19:14 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		num_zombies = 5;
	Zombie*	horde = zombieHorde(num_zombies, "Foo");

	for (int i = 0; i < num_zombies; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
