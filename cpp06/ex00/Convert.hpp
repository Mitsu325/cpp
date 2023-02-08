/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:13:29 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/08 08:27:16 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONVERT_H
# define CONVERT_H

# include <string>
# include <iostream>
# include <stdexcept>
# include <limits>
# include <ctype.h>
# include <stdlib.h>

typedef enum e_type
{
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
}	t_option;

class Convert
{
	private:
		int			_type;
		std::string	_input;
		char		_c;
		int			_i;
		float		_f;
		double		_d;

		void		checkType(std::string str);
		bool		isChar(std::string str);
		bool		isInt(std::string str);
		bool		isFloat(std::string str);
		bool		isDouble(std::string str);
		bool		isPseudo(std::string str);

	public:
		Convert(void);
		Convert(char* arg);
		Convert(Convert const &obj);
		~Convert(void);
		Convert&	operator=(Convert const &obj);

		int			getType(void) const;
		std::string	getInput(void) const;
		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;

		void		convert(void);

		void		printChar(void) const;
		void		printInt(void) const;
		void		printFloat(void) const;
		void		printDouble(void) const;

		class InputException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &stream, Convert const &obj);

#endif
