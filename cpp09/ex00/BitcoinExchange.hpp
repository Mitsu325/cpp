/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:51:04 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 11:54:36 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOIN_EXCHANGE_H
# define BITCOIN_EXCHANGE_H

# include <string>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <ctime>
# include <stdexcept>
# include <map>

# define DATABASE_FILE "data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;
		std::string						_file;

		void	loadDatabase(void);
		bool	checkFormat(std::string line, std::string delimiter, int num);

	public:
		BitcoinExchange(void);
		BitcoinExchange(char* file);
		BitcoinExchange(BitcoinExchange const &obj);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(BitcoinExchange const &obj);

		std::string						getFile(void) const;
		std::map<std::string, float>	getDatabase(void) const;
		void							displayExchange(void);

		class BitcoinExchangeException: public std::exception
		{
			private:
				const char* _msg;

			public:
				BitcoinExchangeException(const char* msg);
				virtual const char* what() const throw();
		};
};

#endif
