/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:33:09 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/11/24 17:55:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <locale>

void	put_uppercase(const char *msg)
{
	std::locale loc;

	while (*msg)
	{
		if (std::islower(*msg))
			std::cout << std::toupper(*msg, loc);
		else
			std::cout << *msg;
		msg++;
	}
}

void	print_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		put_uppercase(argv[i]);
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	print_arg(argv);
	return (0);
}
