/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:36:31 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 15:56:14 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_H
# define INTERN_H

# include <string>
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		AForm*	makeShrubberyCreationForm(const std::string &target);
		AForm*	makeRobotomyRequestForm(const std::string &target);
		AForm*	makePresidentialPardonForm(const std::string &target);

	public:
		Intern(void);
		Intern(Intern const &obj);
		~Intern(void);
		Intern&	operator=(Intern const &obj);

		AForm*	makeForm(const std::string form_name, const std::string target);


		class UnkownFormException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
