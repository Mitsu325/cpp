/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:26:43 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/02 19:37:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name(""), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat donstructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(int grade): _name(""), _grade(grade)
{
	std::cout << "Bureaucrat donstructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat donstructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj): _name(obj.getName()),
	_grade(obj.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
	{
		this->_grade = obj.getGrade();
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const &obj)
{
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "."
		<< std::endl;
	return (stream);
}
