/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:48:34 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/03 20:17:31 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name(""), _grade_sign(150), _grade_execute(150),
	_is_signed(false)
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

Form::Form(std::string name, int grade_sign, int grade_execute): _name(name),
	_grade_sign(grade_sign), _grade_execute(grade_execute), _is_signed(false)
{
	std::cout << "Form constructor called" << std::endl;
	if (grade_sign < 1 || grade_execute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (grade_sign > 150 || grade_execute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(Form const &obj):
	_name(obj.getName()),
	_is_signed(obj.getSign()),
	_grade_sign(obj.getGradeSign()),
	_grade_execute(obj.getGradeExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

Form&	Form::operator=(Form const &obj)
{
	if (this != &obj)
	{
		this->_is_signed = obj.getSign();
	}
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSign(void) const
{
	return (this->_is_signed);
}

int	Form::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int	Form::getGradeExecute(void) const
{
	return (this->_grade_execute);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
	{
		throw Form::GradeTooLowException();
	}
	else if (this->getSign())
	{
		throw Form::AlreadySignedException();
	}
	else
	{
		this->_is_signed = true;
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("* Grade too high *");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("* Grade too low *");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("* Form already signed *");
}

std::ostream&	operator<<(std::ostream &stream, Form const &obj)
{
	stream << obj.getName() << ", Form grade required to sign it is "
		<< obj.getGradeSign() << " and grade required to execute it is "
		<< obj.getGradeExecute() << "."
		<< std::endl;
	return (stream);
}
