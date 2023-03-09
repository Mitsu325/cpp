/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:51:02 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/21 19:08:25 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	const b(Fixed( 5.05f ) * Fixed( 2 ));
	Fixed	c(2.01f);
	Fixed	d(2.01f);

	std::cout << "a: " << a << std::endl;
	std::cout << "pre-increment: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "pos-increment: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "(c > d): " << (c > d) << std::endl;
	std::cout << "(c >= d): " << (c >= d) << std::endl;
	std::cout << "(c <= d): " << (c <= d) << std::endl;
	std::cout << "(c < d): " << (c < d) << std::endl;
	std::cout << "(c == d): " << (c == d) << std::endl;
	std::cout << "(c != d): " << (c != d) << std::endl;

	std::cout << "(a + b): " << a + b << std::endl;
	std::cout << "(a - b): " << a - b << std::endl;
	std::cout << "(a * b): " << a * b << std::endl;
	std::cout << "(a / b): " << a / b << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "pre-decrement: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "pos-decrement: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	return 0;
}
