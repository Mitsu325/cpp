/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:17:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/05 08:07:07 by pmitsuko         ###   ########.fr       */
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

int	PhoneBook::validate_contact(Contact new_contact)
{
	if (new_contact.first_name.empty() || new_contact.last_name.empty()
		|| new_contact.nickname.empty() || new_contact.phone_number.empty()
		|| new_contact.darkest_secret.empty())
	{
		std::cout << "Error add contact: empty field!" << std::endl;
		return (0);
	}
	if (!(new_contact.phone_number.find_first_not_of("+-0123456789")
		== std::string::npos))
	{
		std::cout << "Error add contact: phone number with non-numeric char!"
			<< std::endl;
		return (0);
	}
	return (1);
}

void	PhoneBook::save_contact(Contact new_contact)
{
	contact.first_name = new_contact.first_name;
	contact.last_name = new_contact.last_name;
	contact.nickname = new_contact.nickname;
	contact.phone_number = new_contact.phone_number;
	contact.darkest_secret = new_contact.darkest_secret;
}

void	PhoneBook::add_contact()
{
	Contact	new_contact;

	this->save_entry_string("First Name:", &new_contact.first_name);
	this->save_entry_string("Last Name:", &new_contact.last_name);
	this->save_entry_string("Nickname:", &new_contact.nickname);
	this->save_entry_string("Phone number:", &new_contact.phone_number);
	this->save_entry_string("Darkest secret:", &new_contact.darkest_secret);
	if (this->validate_contact(new_contact))
	{
		this->save_contact(new_contact);
		// std::cout << contact.first_name << std::endl;
		// std::cout << contact.last_name << std::endl;
		// std::cout << contact.nickname << std::endl;
		// std::cout << contact.phone_number << std::endl;
		// std::cout << contact.darkest_secret << std::endl;
	}
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
