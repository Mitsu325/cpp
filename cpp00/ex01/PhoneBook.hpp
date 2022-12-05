/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:14:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/12/05 06:32:21 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		/* data */

	public:
		Contact	contact;
		void	init_phone_book();
		PhoneBook();
		~PhoneBook();
};

#endif
