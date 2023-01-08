/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:05:40 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/08 17:13:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
#include <iostream>

int	main(void)
{
	std::string	msg = "HI THIS IS BRAIN";
	std::string	*stringPTR = &msg;
	std::string	&stringREF = msg;

	std::cout << "The memory address of the string var: " << &msg << std::endl;
	std::cout << "The memory address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "The value of the string variable:  " << msg << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
