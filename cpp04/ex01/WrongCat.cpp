/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:08:22 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:31:50 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << this->getType() << " constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &obj): WrongAnimal(obj)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	*this = obj;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
	return ;
}

WrongCat&	WrongCat::operator=(WrongCat const &obj)
{
	std::cout << obj.getType() << " assigment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow, Meow, Meow..." << std::endl;
}

std::ostream&	operator<<(std::ostream &stream, WrongCat const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
