/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:33:27 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/04 14:37:02 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;
		void	displayPardon(void) const;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		~PresidentialPardonForm(void);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const &obj);

		std::string	getTarget(void) const;
		void		execute(Bureaucrat& bureaucrat) const;
};

#endif
