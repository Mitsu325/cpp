/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:19:26 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 18:34:31 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_H
# define RPN_H

# include <cctype>
# include <cstdlib>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <stack>

class RPN
{
	private:
		std::stack<int>	_stack;
		std::string		_notation;

		bool	validateOperator(std::string token);
		bool	validateNumber(std::string token);
		void	calculate(const char* arithmetic_operator);

	public:
		RPN(void);
		RPN(char* notation);
		RPN(RPN const &obj);
		~RPN(void);
		RPN&	operator=(RPN const &obj);

		std::string	getNotation(void) const;
		void		compute(void);

		class RPNException: public std::exception
		{
			private:
				const char* _msg;

			public:
				RPNException(const char* msg);
				virtual const char* what() const throw();
		};
};

#endif
