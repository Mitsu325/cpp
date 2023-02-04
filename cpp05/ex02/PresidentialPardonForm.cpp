/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:34:53 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 14:37:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", 25, 5),
	_target("PresidentialPardonForm")
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm(target, 25, 5),
	_target(target)
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj):
	AForm(obj.getTarget(), 25, 5),
	_target(obj.getTarget())
{
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	if (this != &obj)
	{
		this->setSign(obj.getSign());
		this->_target = obj.getTarget();
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat& bureaucrat) const
{
	if (!this->getSign())
	{
		throw PresidentialPardonForm::NotSignedException();
	}
	else if (bureaucrat.getGrade() > this->getGradeExecute())
	{
		throw PresidentialPardonForm::GradeTooLowException();
	}
	else
	{
		this->displayPardon();
	}
}

void	PresidentialPardonForm::displayPardon(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
	return ;
}
