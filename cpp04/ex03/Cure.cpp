/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:05:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 19:28:47 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
	return ;
}

Cure::Cure(std::string const & type): AMateria(type)
{
	std::cout << "Cure constructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &obj): AMateria(obj)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure&	Cure::operator=(Cure const &obj)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

std::ostream&	operator<<(std::ostream &stream, Cure const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
