/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:01:59 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/14 19:58:18 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <string>
# include <stdexcept>

template<typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(): _array(new T()), _size(0) {}

		Array(unsigned int n): _array(new T[n]), _size(n) {}

		Array(Array const &obj) {
			this->_size = obj._size;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < _size; i++)
			{
				this->_array[i] = obj[i];
			}
		}

		Array&	operator=(Array const &obj) {
			if (this != &obj)
			{
				delete [] _array;
				this->_size = obj._size;
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < _size; i++)
				{
					this->_array[i] = obj[i];
				}
			}
			return (*this);
		}

		T&	operator[](unsigned int i) const {
			if (i < 0 || i >= _size) {
				throw IndexOutOfBoundsException();
			}
			return (_array[i]);
		}

		~Array() {
			delete [] _array;
		}

		unsigned int	size(void) const {
			return (this->_size);
		}

		class IndexOutOfBoundsException: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("* Index is out of bounds *");
				};
		};
};

template<typename T>
std::ostream&	operator<<(std::ostream &stream, Array<T> const &obj) {
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		stream << obj[i] << " ";
	}
	return (stream);
};

#endif
