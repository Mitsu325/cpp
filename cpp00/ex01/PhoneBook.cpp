/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:17:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/12/05 06:51:18 by pmitsuko         ###   ########.fr       */
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

void	PhoneBook::init_phone_book()
{
	std::cout << "First Name: ";
	std::cin >> contact.first_name;
	std::cout << "Last Name: ";
	std::cin >> contact.last_name;
	std::cout << "Nickname: ";
	std::cin >> contact.nickname;
	std::cout << "Phone number: ";
	std::cin >> contact.phone_number;
	std::cout << "Darkest secret: ";
	std::cin >> contact.darkest_secret;
}
