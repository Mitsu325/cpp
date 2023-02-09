/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:16:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/09 08:28:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATA_H
# define DATA_H

# include <string>
# include <iostream>
# include <stdint.h>

class Data
{
	private:
		std::string	_name;

	public:
		Data(void);
		Data(std::string name);
		Data(Data const &obj);
		~Data(void);
		Data&	operator=(Data const &obj);

		std::string	getName(void) const;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

std::ostream&	operator<<(std::ostream &stream, Data const &obj);

#endif
