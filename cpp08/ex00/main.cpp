/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/15 20:24:18 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>

void	vector_test(void)
{
	std::vector<int>::iterator	it;
	std::vector<int>			group_num;

	for (int i = 0; i < 8; i++)
	{
		group_num.push_back(i);
	}
	it = easyfind(group_num, 7);
	std::cout << *it << std::endl;

	try
	{
		it = easyfind(group_num, 8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	list_test(void)
{
	std::list<int>::iterator	it;
	std::list<int>			group_num;

	for (int i = 0; i < 8; i++)
	{
		group_num.push_back(i);
	}
	it = easyfind(group_num, 5);
	std::cout << *it << std::endl;

	try
	{
		it = easyfind(group_num, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	set_test(void)
{
	std::set<int>::iterator	it;
	std::set<int>			group_num;

	for (int i = 0; i < 8; i++)
	{
		group_num.insert(i);
	}
	it = easyfind(group_num, 3);
	std::cout << *it << std::endl;

	try
	{
		it = easyfind(group_num, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	vector_test();
	list_test();
	set_test();
	return (0);
}
