/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 16:17:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	intern;
	AForm	*scf;
	AForm	*rrf;
	AForm	*ppf;
	AForm	*other;

	std::cout << "========== MAKE FORM =============" << std::endl;
	try
	{
		scf = intern.makeForm("shrubbery creation", "Shrubbery");
		rrf = intern.makeForm("robotomy request", "Robot");
		ppf = intern.makeForm("presidential pardon", "Presidential");
		other = intern.makeForm("other form", "Other");
		(void)other;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delete scf;
		delete rrf;
		delete ppf;
	}
	std::cout << std::endl;
	std::cout << "========== SIGN FORM =============" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 5);
		scf = intern.makeForm("shrubbery creation", "Shrubbery");
		rrf = intern.makeForm("robotomy request", "Robot");
		ppf = intern.makeForm("presidential pardon", "Presidential");
		std::cout << std::endl;
		std::cout << bob << std::endl;
		std::cout << *scf << std::endl;
		std::cout << *rrf << std::endl;
		std::cout << *ppf << std::endl;
		std::cout << std::endl;

		scf->beSigned(bob);
		std::cout << *scf << std::endl;
		scf->execute(bob);
		std::cout << std::endl;

		rrf->beSigned(bob);
		std::cout << *rrf << std::endl;
		rrf->execute(bob);
		std::cout << std::endl;

		ppf->beSigned(bob);
		std::cout << *ppf << std::endl;
		ppf->execute(bob);
		std::cout << std::endl;

		delete scf;
		delete rrf;
		delete ppf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
