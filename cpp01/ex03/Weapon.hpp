/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:30:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 20:35:30 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string weapon_type);
		~Weapon(void);
		const std::string&	getType(void) const;
		void	setType(std::string new_type);
};

#endif
