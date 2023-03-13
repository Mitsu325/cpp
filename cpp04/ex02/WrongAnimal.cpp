/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:50:45 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:47:17 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &obj)
{
	std::cout << "WrongAnimal assigment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "?????????????????" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

std::ostream&	operator<<(std::ostream &stream, WrongAnimal const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
