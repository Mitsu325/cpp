/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:29:41 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 11:53:45 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):
	_name(""),
	_grade_sign(150),
	_grade_execute(150),
	_is_signed(false)
{
	std::cout << "Abstract Form default constructor called" << std::endl;
	return ;
}

AForm::AForm(std::string name, int grade_sign, int grade_execute):
	_name(name),
	_grade_sign(grade_sign),
	_grade_execute(grade_execute),
	_is_signed(false)
{
	std::cout << "Abstract Form constructor called" << std::endl;
	if (grade_sign < 1 || grade_execute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (grade_sign > 150 || grade_execute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(AForm const &obj):
	_name(obj.getName()),
	_grade_sign(obj.getGradeSign()),
	_grade_execute(obj.getGradeExecute()),
	_is_signed(obj.getSign())
{
	std::cout << "Abstract Form copy constructor called" << std::endl;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "Abstract Form destructor called" << std::endl;
	return ;
}

AForm&	AForm::operator=(AForm const &obj)
{
	if (this != &obj)
	{
		this->_is_signed = obj.getSign();
	}
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSign(void) const
{
	return (this->_is_signed);
}

int	AForm::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int	AForm::getGradeExecute(void) const
{
	return (this->_grade_execute);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
	{
		throw AForm::GradeTooLowException();
	}
	else if (this->getSign())
	{
		throw AForm::AlreadySignedException();
	}
	else
	{
		this->_is_signed = true;
	}
}

void	AForm::execute(Bureaucrat& bureaucrat) const
{
	if (!this->getSign())
	{
		throw AForm::NotSignedException();
	}
	else if (bureaucrat.getGrade() > this->getGradeExecute())
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << bureaucrat.getName() << " executed " << this->getName()
			<< std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("* Grade too high *");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("* Grade too low *");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("* Form already signed *");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("* Form not signed *");
}

std::ostream&	operator<<(std::ostream &stream, AForm const &obj)
{
	stream << "Form: " << obj.getName() << std::endl;
	stream << "Sign: " << obj.getSign() << std::endl;
	stream << "Grade to sign: " << obj.getGradeSign() << std::endl;
	stream << "Grade to execute: " << obj.getGradeExecute() << std::endl;
	return (stream);
}
