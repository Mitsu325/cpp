/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:51:04 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 11:06:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOIN_EXCHANGE_H
# define BITCOIN_EXCHANGE_H

# include <string>
# include <cstring>
# include <iostream>
# include <fstream>
# include <ctime>
# include <stdexcept>
# include <map>
# include <stdlib.h>

# define DATABASE_FILE "data.cs"

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;
		std::string						_file;

		int		loadDatabase(void);
		bool	checkFormat(std::string line, std::string delimiter, int num);

	public:
		BitcoinExchange(void);
		BitcoinExchange(char* file);
		BitcoinExchange(BitcoinExchange const &obj);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(BitcoinExchange const &obj);

		// std::string	getName(void) const;

		// class GradeTooHighException: public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw();
		// };

		// class GradeTooLowException: public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw();
		// };
};

#endif
