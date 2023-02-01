/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:58:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 22:34:52 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (size_t i = 0; i < TEMPLATE_SIZE; i++)
	{
		this->_materia_template[i] = NULL;
	}
	std::cout << "MateriaSource default constructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	for (size_t i = 0; i < TEMPLATE_SIZE; i++)
	{
		if (obj._materia_template[i])
		{
			this->_materia_template[i] = obj._materia_template[i]->clone();
		}
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (size_t i = 0; i < TEMPLATE_SIZE; i++)
	{
		if (this->_materia_template[i] != NULL)
		{
			delete this->_materia_template[i];
			this->_materia_template[i] = NULL;
		}
	}
	std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const &obj)
{
	for (size_t i = 0; i < TEMPLATE_SIZE; i++)
	{
		if (this->_materia_template[i])
		{
			delete this->_materia_template[i];
			this->_materia_template[i] = NULL;
		}
		if (obj._materia_template[i])
		{
			this->_materia_template[i] = obj._materia_template[i]->clone();
		}
	}
	std::cout << "MateriaSource assignment operator called" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (size_t i = 0; i < TEMPLATE_SIZE; i++)
	{
		if (!this->_materia_template[i])
		{
			this->_materia_template[i] = materia;
			std::cout << "Materia learned: "
				<< this->_materia_template[i]->getType() << std::endl;
			break;
		}
	}
	std::cout << "Can't learn more than 4 Materia" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i = 0;

	while (this->_materia_template[i] &&
		this->_materia_template[i]->getType() != type && i < 4)
	{
		i++;
	}
	if (i >= 4 || !this->_materia_template[i])
	{
		std::cout << type << " materia does not exit" << std::endl;
		return (NULL);
	}
	std::cout << "Create Materia: " << this->_materia_template[i]->getType()
		<< std::endl;
	return (this->_materia_template[i]->clone());
}
