/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:08:22 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:30:53 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << this->getType() << " constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &obj): Animal(obj)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Dog::~Dog(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
	return ;
}

Dog&	Dog::operator=(Dog const &obj)
{
	std::cout << obj.getType() << " assigment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof, Woof, Woof..." << std::endl;
}

std::ostream&	operator<<(std::ostream &stream, Dog const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
