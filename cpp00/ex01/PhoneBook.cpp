/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:17:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/05 07:34:37 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{}

PhoneBook::~PhoneBook()
{}

// void	PhoneBook::input_filed()
// {
// 	std::cout << "oh no, input failed" << std::endl;
// 	this->~PhoneBook();
// 	exit(EXIT_FAILURE);
// }

void	PhoneBook::save_entry_string(const char *instruction, std::string *var)
{
	std::cout << instruction << std::endl;
	std::getline(std::cin, *var);
	if (!std::cin)
	{
		std::cout << "oh no, input failed" << std::endl;
		this->~PhoneBook();
		exit(EXIT_FAILURE);
	}
}

void	PhoneBook::add_contact()
{
	Contact	new_contact;

	this->save_entry_string("First Name:", &new_contact.first_name);
	this->save_entry_string("Last Name:", &new_contact.last_name);
	this->save_entry_string("Nickname:", &new_contact.nickname);
	this->save_entry_string("Phone number:", &new_contact.phone_number);
	this->save_entry_string("Darkest secret:", &new_contact.darkest_secret);
}

int	PhoneBook::check_option(std::string option)
{
	if (option == "ADD")
		this->add_contact();
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
	while (this->check_option(option))
	{
		std::cout << "=================================" << std::endl;
		this->save_entry_string("Enter one command:", &option);
	}
}
