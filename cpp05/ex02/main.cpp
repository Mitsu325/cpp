/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 15:08:51 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	shrubbery_creation_form(void)
{
	std::cout << "========= SHRUBBERY EXEC FORM ==========" << std::endl;
	try
	{
		ShrubberyCreationForm	scf("Shrubbery");
		Bureaucrat				bob("Bob", 140);
		scf.beSigned(bob);
		std::cout << "------" << std::endl;
		bob.executeForm(scf);
		std::cout << "------" << std::endl;
		Bureaucrat				ted("Ted", 135);
		std::cout << "------" << std::endl;
		ted.executeForm(scf);
		std::cout << "------" << std::endl;
		Bureaucrat				judy("Judy", 148);
		std::cout << "------" << std::endl;
		judy.executeForm(scf);
		std::cout << "------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
}

void	robotomy_request_form(void)
{
	std::cout << "========= ROBOTOMY EXEC FORM ===========" << std::endl;
	try
	{
		RobotomyRequestForm	rrf("Robot");
		Bureaucrat				bob("Bob", 72);
		rrf.beSigned(bob);
		std::cout << "------" << std::endl;
		bob.executeForm(rrf);
		std::cout << "------" << std::endl;
		Bureaucrat				ted("Ted", 40);
		std::cout << "------" << std::endl;
		ted.executeForm(rrf);
		std::cout << "------" << std::endl;
		Bureaucrat				judy("Judy", 73);
		std::cout << "------" << std::endl;
		judy.executeForm(rrf);
		std::cout << "------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=========================================" << std::endl;
}

void	presidential_pardon_form(void)
{
	std::cout << "========== PARDON EXEC FORM =============" << std::endl;
	try
	{
		PresidentialPardonForm	ppf("Robot");
		Bureaucrat				bob("Bob", 20);
		ppf.beSigned(bob);
		std::cout << "------" << std::endl;
		bob.executeForm(ppf);
		std::cout << "------" << std::endl;
		Bureaucrat				ted("Ted", 2);
		std::cout << "------" << std::endl;
		ted.executeForm(ppf);
		std::cout << "------" << std::endl;
		Bureaucrat				judy("Judy", 26);
		std::cout << "------" << std::endl;
		judy.executeForm(ppf);
		std::cout << "------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=========================================" << std::endl;
}

int	main(void)
{
	shrubbery_creation_form();
	robotomy_request_form();
	presidential_pardon_form();
	return (0);
}
