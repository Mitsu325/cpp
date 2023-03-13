/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:50:45 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 22:30:37 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): type("")
{
	std::cout << "Abstract Materia constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type): type(type)
{
	std::cout << "Abstract Materia constructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &obj)
{
	std::cout << "Abstract Materia copy constructor called" << std::endl;
	*this = obj;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "Abstract Materia destructor called" << std::endl;
	return ;
}

AMateria&	AMateria::operator=(AMateria const &obj)
{
	std::cout << "Abstract Materia assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return (*this);
}

std::string const &	AMateria::getType(void) const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
