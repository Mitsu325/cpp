/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:59:21 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 14:31:33 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm", 72, 45),
	_target("RobotomyRequestForm")
{
	std::cout << "Robotomy Request Form constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm(target, 72, 45),
	_target(target)
{
	std::cout << "Robotomy Request Form constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj):
	AForm(obj.getTarget(), 72, 45),
	_target(obj.getTarget())
{
	std::cout << "Robotomy Request Form copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	if (this != &obj)
	{
		this->setSign(obj.getSign());
		this->_target = obj.getTarget();
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat& bureaucrat) const
{
	if (!this->getSign())
	{
		throw RobotomyRequestForm::NotSignedException();
	}
	else if (bureaucrat.getGrade() > this->getGradeExecute())
	{
		throw RobotomyRequestForm::GradeTooLowException();
	}
	else
	{
		this->robotomized();
	}
}

void	RobotomyRequestForm::robotomized(void) const
{
	srand(time(0));
	std::cout << "Bzzzz Bzzzz Bzzzz Bzzzz..." << std::endl;
	if (rand() % 2)
	{
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << this->getTarget() << " robotomy failed" << std::endl;
	}
	return ;
}
