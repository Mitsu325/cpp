/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:56:46 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 20:26:58 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice(std::string const & type): AMateria(type)
{
	std::cout << "Ice constructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const &obj): AMateria(obj)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

Ice&	Ice::operator=(Ice const &obj)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
}

std::ostream&	operator<<(std::ostream &stream, Ice const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
