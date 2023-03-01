/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:17:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/28 20:51:20 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	contact_index = -1;
	full_contact = false;
}

PhoneBook::~PhoneBook(void)
{}

int	PhoneBook::validate_contact(Contact new_contact)
{
	if (new_contact.getFirstName().empty() || new_contact.getLastName().empty()
		|| new_contact.getNickname().empty() || new_contact.getPhoneNumber().empty()
		|| new_contact.getDarkestSecret().empty())
	{
		std::cout << "Error add contact: empty field!" << std::endl;
		return (0);
	}
	if (!(new_contact.getPhoneNumber().find_first_not_of("+-0123456789")
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
	contact[contact_index].setFirstName(new_contact.getFirstName());
	contact[contact_index].setLastName(new_contact.getLastName());
	contact[contact_index].setNickname(new_contact.getNickname());
	contact[contact_index].setPhoneNumber(new_contact.getPhoneNumber());
	contact[contact_index].setDarkestSecret(new_contact.getDarkestSecret());
}

void	PhoneBook::add_contact()
{
	Contact	new_contact;

	new_contact.setFirstName(this->input_str("\nFirst Name:"));
	new_contact.setLastName(this->input_str("Last Name:"));
	new_contact.setNickname(this->input_str("Nickname:"));
	new_contact.setPhoneNumber(this->input_str("Phone number:"));
	new_contact.setDarkestSecret(this->input_str("Darkest secret:"));
	if (this->validate_contact(new_contact))
		this->save_contact(new_contact);
}

int	PhoneBook::check_contact_range(int index, int limit)
{
	if (index < 0 || index > limit)
	{
		std::cout << "* Index out of contact range *" << std::endl;
		return (1);
	}
	return (0);
}

void	PhoneBook::select_contact(int limit)
{
	std::string	contact_choice;
	int			index;

	do {
		contact_choice.clear();
		std::cout << std::endl;
		contact_choice = this->input_str("Choose a contact index to see all information:");
		index = atoi(contact_choice.c_str()) - 1;
	} while (this->check_contact_range(index, limit));
	std::cout << "\nFirst Name:" << std::endl;
	std::cout << contact[index].getFirstName() << std::endl;
	std::cout << "Last Name:" << std::endl;
	std::cout << contact[index].getLastName() << std::endl;
	std::cout << "Nickname:" << std::endl;
	std::cout << contact[index].getNickname() << std::endl;
	std::cout << "Phone number:" << std::endl;
	std::cout << contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret:" << std::endl;
	std::cout << contact[index].getDarkestSecret() << std::endl;
}

std::string	PhoneBook::truncate(std::string str, size_t str_length)
{
	if (str.length() > str_length)
		return (str.substr(0, str_length - 1) + '.');
	return (str);
}

void	PhoneBook::print_contact(std::string field, int endl)
{
	std::cout << std::right << std::setw(10) << field;
	if (endl)
		std::cout << std::endl;
	else
		std::cout << "|";
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
	std::cout << std::endl;
	this->print_contact("Index", 0);
	this->print_contact("First Name", 0);
	this->print_contact("Last Name", 0);
	this->print_contact("Nickname", 1);
	while (index <= limit)
	{
		std::cout << std::right << std::setw(10) << index + 1 << "|";
		this->print_contact(this->truncate(contact[index].getFirstName(), 10), 0);
		this->print_contact(this->truncate(contact[index].getLastName(), 10), 0);
		this->print_contact(this->truncate(contact[index].getNickname(), 10), 1);
		index++;
	}
	this->select_contact(limit);
}

std::string	PhoneBook::input_str(const char *instruction)
{
	std::string	input;

	std::cout << instruction << std::endl;
	std::getline(std::cin, input);
	if (!std::cin)
	{
		std::cout << "oh no, input failed" << std::endl;
		this->~PhoneBook();
		exit(EXIT_FAILURE);
	}
	return (input);
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

void	PhoneBook::loop_phone()
{
	std::string	option;

	option.clear();
	while (this->check_option(option))
	{
		std::cout << "=================================" << std::endl;
		option = this->input_str("Enter one command:");
	}
}
