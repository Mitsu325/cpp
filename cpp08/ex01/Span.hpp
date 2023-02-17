/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:47:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/17 20:10:01 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_H
# define SPAN_H

# include <vector>
# include <algorithm>
# include <cstdlib>
# include <ctime>


class Span
{
	private:
		std::vector<int>	_vector;
		unsigned int		_size;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &obj);
		~Span(void);
		Span&	operator=(Span const &obj);

		void	addNumber(unsigned int num);
		void	randFill(void);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

	class SpanIsFullException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NoSpanFoundException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
