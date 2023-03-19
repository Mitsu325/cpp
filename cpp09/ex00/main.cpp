/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 12:05:13 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

void	btc(char *file)
{
	try
	{
		BitcoinExchange bitcoinExchange(file);

		bitcoinExchange.displayExchange();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "." << std::endl;
	}
}

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	btc(argv[1]);
	return (0);
}
