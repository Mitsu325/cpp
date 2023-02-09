/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/09 08:37:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data	*data = new Data("test serialize");
	uintptr_t	serialized_data;
	Data	*deserialized_data;

	std::cout << "================= Init value =================" << std::endl;
	std::cout << "data: " << data << std::endl;
	std::cout << *data << std::endl;

	std::cout << "===== Compare data and deserialized_data =====" << std::endl;
	std::cout << (data == deserialized_data) << std::endl;
	std::cout << std::endl;

	std::cout << "================= Serialized =================" << std::endl;
	serialized_data = serialize(data);
	std::cout << "serialized_data" << serialized_data << std::endl;
	std::cout << std::endl;

	std::cout << "================ Deserialized ================" << std::endl;
	deserialized_data = deserialize(serialized_data);
	std::cout << "deserialized_data: " << deserialized_data << std::endl;
	std::cout << *deserialized_data << std::endl;

	std::cout << "===== Compare data and deserialized_data =====" << std::endl;
	std::cout << (data == deserialized_data) << std::endl;
	std::cout << std::endl;

	delete data;
	return (0);
}
