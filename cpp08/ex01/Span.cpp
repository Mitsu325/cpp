/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:00:13 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/17 20:10:25 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():
	_size(0)
{}

Span::Span(unsigned int n):
	_size(n)
{}

Span::Span(Span const &obj)
{
	*this = obj;
	return ;
}

Span::~Span(void)
{}

Span&	Span::operator=(Span const &obj)
{
	if (this != &obj)
	{
		this->_size = obj._size;
		this->_vector = obj._vector;
	}
	return (*this);
}

void	Span::addNumber(unsigned int num)
{
	if (this->_vector.size() < this->_size)
		this->_vector.push_back(num);
	else
		throw SpanIsFullException();
}

void	Span::randFill(void)
{
	srand(time(0));
	if (this->_vector.size() < this->_size)
	{
		for (size_t i = 0; i < this->_size; i++)
		{
			this->_vector.push_back(rand());
		}
	}
	else
		throw SpanIsFullException();
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int	shortest_span;

	if (this->_vector.size() < 2)
		throw NoSpanFoundException();
	std::sort(this->_vector.begin(), this->_vector.end());
	shortest_span = this->_vector.at(1) - this->_vector.at(0);
	for (size_t i = 1; i < (this->_vector.size() - 1); i++)
	{
		if ((this->_vector.at(i + 1) - this->_vector.at(i)) < static_cast<int>(shortest_span))
		{
			shortest_span = this->_vector.at(i + 1) - this->_vector.at(i);
		}
	}
	return (shortest_span);
}

unsigned int	Span::longestSpan(void)
{
	if (this->_vector.size() < 2)
		throw NoSpanFoundException();
	return (*std::max_element(this->_vector.begin(), this->_vector.end()) -
		*std::min_element(this->_vector.begin(), this->_vector.end()));
}

const char* Span::SpanIsFullException::what() const throw()
{
	return ("* Span is full *");
}

const char* Span::NoSpanFoundException::what() const throw()
{
	return ("* No Span Found *");
}
