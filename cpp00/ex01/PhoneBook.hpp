/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:14:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/05 08:53:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_H

# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		int		check_option(std::string option);
		void	add_contact();
		// void	input_filed();
		void	save_entry_string(const char *instruction, std::string *var);
		int		validate_contact(Contact new_contact);
		void	save_contact(Contact new_contact);
		void	search_contact();

	public:
		Contact	contact[8];
		int		contact_index;
		bool	full_contact;
		void	init_phone_book();
		PhoneBook();
		~PhoneBook();
};

#endif
