/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/05 18:43:41 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	convertTest(char* input)
{
	try
	{
		Convert	param(input);
		param.convert();
		std::cout << param << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments..." << std::endl;
		std::cout << "usage: ./convert arg" << std::endl;
		return (1);
	}
	if (std::string(argv[1]) == "-t")
	{
		convertTest((char*)"m");
		convertTest((char*)"0");
		convertTest((char*)"-12");
		convertTest((char*)"+12");
		convertTest((char*)"42.0f");
		convertTest((char*)"+42.0f");
		convertTest((char*)"-42.0f");
		convertTest((char*)"42.0");
		convertTest((char*)"+42.0");
		convertTest((char*)"-42.0");
		convertTest((char*)"nan");
		convertTest((char*)"nanf");
		convertTest((char*)"+inf");
		convertTest((char*)"+inff");
		convertTest((char*)"-inf");
		convertTest((char*)"-inff");
		return (0);
	}

	convertTest(argv[1]);
	return (0);
}
