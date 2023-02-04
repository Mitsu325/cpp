/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:40:17 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 16:09:52 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const &obj)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

Intern&	Intern::operator=(Intern const &obj)
{
	(void)obj;
	return (*this);
}

AForm*	Intern::makeForm(const std::string form_name, const std::string target)
{
	int	i = 0;
	std::string option[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(Intern::*func_ptr[3])(const std::string &) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	while (i < 3)
	{
		if (form_name == option[i])
		{
			std::cout << "Inter creates " << target << std::endl;
			return ((this->*(func_ptr[i]))(target));
		}
		i++;
	}
	throw UnkownFormException();
}

AForm*	Intern::makeShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::UnkownFormException::what() const throw()
{
	return ("* Unkown Form *");
}
