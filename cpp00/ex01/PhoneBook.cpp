/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:17:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/05 06:31:38 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

int	PhoneBook::check_option(std::string option)
{
	if (option == "ADD")
		std::cout << "ADD" << std::endl;
	else if (option == "SEARCH")
		std::cout << "SEARCH" << std::endl;
	else if (option == "EXIT")
		return (0);
	else
		std::cout << "* Valid commands are: ADD, SEARCH, EXIT *" << std::endl;
	option.clear();
	return (1);
}

void	PhoneBook::init_phone_book()
{
	std::string	option;

	option.clear();
	while (check_option(option))
	{
		std::cout << "Enter one command:" << std::endl;
		std::cin >> option;
	}
	// std::cout << "First Name: ";
	// std::cin >> contact.first_name;
	// std::cout << "Last Name: ";
	// std::cin >> contact.last_name;
	// std::cout << "Nickname: ";
	// std::cin >> contact.nickname;
	// std::cout << "Phone number: ";
	// std::cin >> contact.phone_number;
	// std::cout << "Darkest secret: ";
	// std::cin >> contact.darkest_secret;
}
