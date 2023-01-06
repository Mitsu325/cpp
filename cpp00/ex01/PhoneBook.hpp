/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:14:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/06 19:52:52 by pmitsuko         ###   ########.fr       */
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
		Contact	contact[8];
		int		contact_index;
		bool	full_contact;
		void	add_contact();
		int		validate_contact(Contact new_contact);
		void	save_contact(Contact new_contact);
		void	search_contact();
		void	select_contact(int limit);
		void	print_contact(std::string field, int endl);
		std::string	truncate(std::string str, size_t width);
		int		check_contact_range(int index, int limit);

	public:
		int		check_option(std::string option);
		void	save_entry_string(const char *instruction, std::string *var);
		PhoneBook();
		~PhoneBook();
};

#endif
