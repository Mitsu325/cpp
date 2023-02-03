/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:47:28 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/03 20:01:08 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include <stdexcept>

class Form
{
	private:
		const std::string	_name;
		const int			_grade_sign;
		const int			_grade_execute;
		bool				_is_signed;

	public:
		Form(void);
		Form(std::string name, int grade_sign, int grade_execute);
		Form(Form const &obj);
		~Form(void);
		Form&	operator=(Form const &obj);

		std::string	getName(void) const;
		bool		getSign(void) const;
		int			getGradeSign(void) const;
		int			getGradeExecute(void) const;

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
};

std::ostream&	operator<<(std::ostream &stream, Form const &obj);

#endif
