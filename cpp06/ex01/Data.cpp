/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:16:11 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/09 08:29:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void):
	_name("")
{
	std::cout << "Data default constructor called" << std::endl;
	return ;
}

Data::Data(std::string name):
	_name(name)
{
	std::cout << "Data constructor called" << std::endl;
	return ;
}

Data::Data(Data const &obj)
{
	std::cout << "Data copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Data::~Data(void)
{
	std::cout << "Data destructor called" << std::endl;
	return ;
}

Data&	Data::operator=(Data const &obj)
{
	if (this != &obj)
	{
		this->_name = obj.getName();
	}
	return (*this);
}

std::string	Data::getName(void) const
{
	return (this->_name);
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

std::ostream&	operator<<(std::ostream &stream, Data const &obj)
{
	stream << "name: " << obj.getName() << std::endl;
	return (stream);
}
