/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:17:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/02 19:57:22 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_H

# include <iostream>
# include <string>

# define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
# define INFO_MSG "I cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
# define WARNING_MSG "I think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.\n"
# define ERROR_MSG "This is unacceptable! I want to speak to the manager now.\n"
# define NOT_MSG "[ Probably complaining about insignificant problems ]"

class Harl
{
	private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	no_option(void);
	int		resolveOption(std::string level);

	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);
};

#endif
