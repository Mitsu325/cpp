/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:18:12 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/25 20:18:26 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	mergeMe(char** argv)
{
	try
	{
		PmergeMe Pmerge(argv);

		Pmerge.execute();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error: invalid arguments" << std::endl;
		return (1);
	}
	mergeMe(argv);
	return (0);
}
