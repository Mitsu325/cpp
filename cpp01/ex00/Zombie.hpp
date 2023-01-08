/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:57:38 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 10:23:27 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		~Zombie();

		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
