/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:57:38 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 20:32:18 by pmitsuko         ###   ########.fr       */
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
		Zombie(void);
		~Zombie(void);

		void	announce(void) const;
		void	set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
