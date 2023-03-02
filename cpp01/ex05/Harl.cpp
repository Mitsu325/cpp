/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:17:26 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/02 19:57:03 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructor" << std::endl;
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

void	Harl::no_option(void)
{
	std::cout << NOT_MSG << std::endl;
}

int	Harl::resolveOption(std::string level)
{
	std::string	option[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && level != option[i])
		i++;
	return (i);
}

void	Harl::complain(std::string level)
{
	int		option;
	void	(Harl::*func_ptr[5])() = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error, &Harl::no_option};

	option = resolveOption(level);
	(this->*(func_ptr[option]))();
	return ;
}
