/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:08:22 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:30:45 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << this->getType() << " constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &obj): Animal(obj)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Cat::~Cat(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
	return ;
}

Cat&	Cat::operator=(Cat const &obj)
{
	std::cout << obj.getType() << " assigment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow, Meow, Meow..." << std::endl;
}

std::ostream&	operator<<(std::ostream &stream, Cat const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
