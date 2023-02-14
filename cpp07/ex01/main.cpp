/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/13 21:36:10 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int	arr1[] = { 1, 2, 3, 4, 5 };

	std::cout << "arr1: " << std::endl;
	iter(arr1, sizeof(arr1)/sizeof(arr1[0]), &put);

	double	arr2[] = { 1.5, 0.2, 3.82, 4.1, 9.5 };

	std::cout << "arr2: " << std::endl;
	iter(arr2, sizeof(arr2)/sizeof(arr2[0]), &put);

	char	arr3[] = { 'H', 'o', 'l', '*' };

	std::cout << "arr3: " << std::endl;
	iter(arr3, sizeof(arr3)/sizeof(arr3[0]), &put);

	std::string	arr4[] = { "one", "two", "three" };

	std::cout << "arr4: " << std::endl;
	iter(arr4, sizeof(arr4)/sizeof(arr4[0]), &put);

	return (0);
}
