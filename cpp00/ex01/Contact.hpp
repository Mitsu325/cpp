/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 05:17:48 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/28 20:29:32 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_H

# include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		Contact();
		~Contact();

		std::string	getFirstName(void) const;
		void		setFirstName(std::string input);
		std::string	getLastName(void) const;
		void		setLastName(std::string input);
		std::string	getNickname(void) const;
		void		setNickname(std::string input);
		std::string	getPhoneNumber(void) const;
		void		setPhoneNumber(std::string input);
		std::string	getDarkestSecret(void) const;
		void		setDarkestSecret(std::string input);
};

#endif
