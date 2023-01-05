/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:17:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/05 09:21:30 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_index = -1;
	full_contact = false;
}

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
	if (contact_index == -1)
		contact_index = 0;
	else if (contact_index >= 7)
	{
		contact_index = 0;
		full_contact = true;
	}
	else
		contact_index++;
	contact[contact_index].first_name.clear();
	contact[contact_index].first_name = new_contact.first_name;
	contact[contact_index].last_name.clear();
	contact[contact_index].last_name = new_contact.last_name;
	contact[contact_index].nickname.clear();
	contact[contact_index].nickname = new_contact.nickname;
	contact[contact_index].phone_number.clear();
	contact[contact_index].phone_number = new_contact.phone_number;
	contact[contact_index].darkest_secret.clear();
	contact[contact_index].darkest_secret = new_contact.darkest_secret;
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
		this->save_contact(new_contact);
}

void	PhoneBook::search_contact()
{
	int	index;
	int	limit;

	if (contact_index == -1)
	{
		std::cout << "Phone Book is empty!" << std::endl;
		return ;
	}
	index = 0;
	limit = full_contact ? 7 : contact_index;
	std::cout << std::right <<std::setw(10) << "Index" << "|";
	std::cout << std::right <<std::setw(10) << "First Name" << "|";
	std::cout << std::right <<std::setw(10) << "Last Name" << "|";
	std::cout << std::right <<std::setw(10) << "Nickname" << std::endl;
	while (index <= limit)
	{
		std::cout << std::right <<std::setw(10) << index << "|";
		std::cout << std::right <<std::setw(10) << contact[index].first_name << "|";
		std::cout << std::right <<std::setw(10) << contact[index].last_name << "|";
		std::cout << std::right <<std::setw(10) << contact[index].nickname << std::endl;
		index++;
	}
}

int	PhoneBook::check_option(std::string option)
{
	if (option == "ADD")
		this->add_contact();
	else if (option == "SEARCH")
		this->search_contact();
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
