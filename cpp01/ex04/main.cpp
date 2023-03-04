/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:59:07 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/11 00:43:28 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"

int	main(int argc, char **argv)
{
	FileReplace	*file_replace;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		std::cout << "Enter the commands: ./file_replace <filename> <s1> <s2>"
			<< std::endl;
		return (1);
	}
	file_replace = new FileReplace(argv[1], argv[2], argv[3]);
	if (file_replace->getFileContent())
	{
		delete file_replace;
		file_replace = NULL;
		return (1);
	}
	file_replace->allStringReplace();
	if (file_replace->writeFile())
	{
		delete file_replace;
		file_replace = NULL;
		return (1);
	}
	delete file_replace;
	file_replace = NULL;
	return (0);
}
