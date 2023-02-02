/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:35:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/02 19:34:18 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string new_name);
		Bureaucrat(int grade);
		Bureaucrat(std::string new_name, int grade);
		Bureaucrat(Bureaucrat const &obj);
		~Bureaucrat(void);
		Bureaucrat&	operator=(Bureaucrat const &obj);

		std::string	getName(void) const;
		int			getGrade(void) const;
};

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const &obj);

#endif
