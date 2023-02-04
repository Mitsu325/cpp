/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:28:21 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 12:10:24 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_grade_sign;
		const int			_grade_execute;
		bool				_is_signed;

	public:
		AForm(void);
		AForm(std::string name, int grade_sign, int grade_execute);
		AForm(AForm const &obj);
		virtual ~AForm(void);
		virtual AForm&	operator=(AForm const &obj);

		std::string	getName(void) const;
		bool		getSign(void) const;
		void		setSign(bool sign);
		int			getGradeSign(void) const;
		int			getGradeExecute(void) const;
		void		beSigned(Bureaucrat& bureaucrat);

		virtual std::string	getTarget(void) const = 0;
		virtual void	execute(Bureaucrat& bureaucrat) const = 0;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &stream, AForm const &obj);

#endif
