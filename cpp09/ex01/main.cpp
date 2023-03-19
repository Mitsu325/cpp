/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:18:12 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 18:26:42 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void	reversePolishNotation(char *arg)
{
	try
	{
		RPN rpn(arg);

		rpn.compute();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid arguments" << std::endl;
		return (1);
	}
	reversePolishNotation(argv[1]);
	return (0);
}
