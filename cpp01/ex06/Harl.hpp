/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:17:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/11 03:22:06 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_H

# include <iostream>
# include <string>

# define DEBUG_MSG "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
# define INFO_MSG "I cannot believe adding extra bacon costs more money.\n\
You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!\n"
# define WARNING_MSG "I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years whereas you started working here since last month.\n"
# define ERROR_MSG "This is unacceptable! I want to speak to the manager now.\n"
# define NOT_MSG "[ Probably complaining about insignificant problems ]"

typedef enum e_option
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
}	t_option;

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
