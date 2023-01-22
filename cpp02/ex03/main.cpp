/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:51:02 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/21 21:36:51 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	bool	flag;

	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);
		Point const	P(10, 15);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);
		Point const	P(10, 30);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);
		Point const	P(100, 300);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);
		Point const	P(2, 3);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);
		Point const	P(2.1f, 3);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);
		Point const	P(2, 3.1f);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);
		Point const	P(2, 2.9f);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);
		Point const	P(8.00f, 6.000000f);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);
		Point const	P(11.75001f, 3.1415926f);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);
		Point const	P(-1.97531f, 0.987654f);

		flag = bsp(p1, p2, p3, P);

		if (flag)
			std::cout << "Yes it is." << std::endl;
		else
			std::cout << "No it is not." << std::endl;
	}
	return (0);
}
