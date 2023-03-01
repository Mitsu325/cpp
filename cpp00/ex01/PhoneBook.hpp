/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:14:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/28 20:51:05 by pmitsuko         ###   ########.fr       */
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
		Contact		contact[8];
		int			contact_index;
		bool		full_contact;

		void		add_contact();
		int			validate_contact(Contact new_contact);
		void		save_contact(Contact new_contact);
		void		search_contact();
		void		select_contact(int limit);
		void		print_contact(std::string field, int endl);
		std::string	truncate(std::string str, size_t width);
		int			check_contact_range(int index, int limit);
		int			check_option(std::string option);
		std::string	input_str(const char *instruction);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		loop_phone(void);
};

#endif
