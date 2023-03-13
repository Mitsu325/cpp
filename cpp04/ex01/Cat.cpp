/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:08:22 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 19:39:17 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << this->getType() << " constructor called" << std::endl;
	brain = new Brain();
	return ;
}

Cat::Cat(Cat const &obj): Animal(obj)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Cat::~Cat(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
	delete brain;
	brain = NULL;
	return ;
}

Cat&	Cat::operator=(Cat const &obj)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		this->brain = new Brain();
		*this->brain = *(obj.getBrain());
	}
	return (*this);
}

Animal&	Cat::operator=(Animal const &obj)
{
	std::cout << "Animal - Cat assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.getType();
		*this->brain = *(obj.getBrain());
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow, Meow, Meow..." << std::endl;
}

void	Cat::printIdeas(void) const
{
	int	i;

	i = 0;
	std::cout << "Brain: " << this->getBrain() << std::endl;
	while (!this->brain->getIdea(i).empty())
	{
		std::cout << this->brain->getIdea(i) << std::endl;
		i++;
	}
	return ;
}

void	Cat::addIdea(std::string idea)
{
	this->brain->setIdea(idea);
	return ;
}

Brain*	Cat::getBrain(void) const
{
	return (this->brain);
}

std::ostream&	operator<<(std::ostream &stream, Cat const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
