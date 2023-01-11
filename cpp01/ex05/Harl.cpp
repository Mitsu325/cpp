/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:17:26 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/11 02:48:01 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl destructor" << std::endl;
}


Harl::~Harl(void)
{
	std::cout << "Harl destructor" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG_MSG << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO_MSG << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING_MSG << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR_MSG << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;
	std::string option[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func_ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error};

	while (i < 4)
	{
		if (level == option[i])
		{
			(this->*(func_ptr[i]))();
			break;
		}
		i++;
	}
}
