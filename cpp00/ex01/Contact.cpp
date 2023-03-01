/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 05:50:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/28 20:32:22 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

std::string	Contact::getFirstName(void) const
{
	return (this->first_name);
}

void	Contact::setFirstName(std::string input)
{
	this->first_name = input;
	return ;
}

std::string	Contact::getLastName(void) const
{
	return (this->last_name);
}

void	Contact::setLastName(std::string input)
{
	this->last_name = input;
	return ;
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

void	Contact::setNickname(std::string input)
{
	this->nickname = input;
	return ;
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

void	Contact::setPhoneNumber(std::string input)
{
	this->phone_number = input;
	return ;
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}

void	Contact::setDarkestSecret(std::string input)
{
	this->darkest_secret = input;
	return ;
}
