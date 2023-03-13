/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:13:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/17 20:13:07 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void	test_subject(void)
{
	std::cout << "================ Subject ================" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return ;
}

void	test_exception(void)
{
	std::cout << "=============== Exception ===============" << std::endl;
	Span sp = Span();
	try
	{
		sp.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Span sp1 = Span(1);
	sp1.addNumber(2);
	try
	{
		sp1.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp1.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Span sp2 = Span(2);
	sp2.addNumber(2);
	sp2.addNumber(3);
	try
	{
		sp2.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

void	test_big(void)
{
	std::cout << "================== Big ==================" << std::endl;

	Span sp1 = Span(10000);

	sp1.randFill();
	std::cout << "&sp1: " << &sp1 << std::endl;
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp2(sp1);
	std::cout << "&sp2: " << &sp2 << std::endl;
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp3 = sp1;
	std::cout << "&sp3: " << &sp3 << std::endl;
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	std::cout << std::endl;
	return ;
}

int	main(void)
{
	test_subject();
	test_exception();
	test_big();
	return (0);
}
