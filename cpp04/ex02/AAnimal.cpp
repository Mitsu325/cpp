/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:50:45 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 19:57:16 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(std::string type): type(type)
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

AAnimal&	AAnimal::operator=(AAnimal const &obj)
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "........." << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}

std::ostream&	operator<<(std::ostream &stream, AAnimal const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
