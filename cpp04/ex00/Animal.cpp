/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:50:45 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:46:38 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

Animal::Animal(std::string type): type(type)
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal&	Animal::operator=(Animal const &obj)
{
	this->type = obj.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "........." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

std::ostream&	operator<<(std::ostream &stream, Animal const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
