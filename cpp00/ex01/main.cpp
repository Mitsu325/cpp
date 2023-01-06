/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 05:54:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/06 20:03:37 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phone_book;
	std::string	option;

	option.clear();
	while (phone_book.check_option(option))
	{
		std::cout << "=================================" << std::endl;
		phone_book.save_entry_string("Enter one command:", &option);
	}
	return (0);
}
