/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:08:22 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 18:26:20 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << this->getType() << " constructor called" << std::endl;
	brain = new Brain();
	return ;
}

Dog::Dog(Dog const &obj): Animal(obj)
{
	std::cout << this->getType() << " copy constructor called" << std::endl;
	*this = obj;
	this->brain = new Brain();
	*this->brain = *(obj.getBrain());
	return ;
}

Dog::~Dog(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
	delete brain;
	brain = NULL;
	return ;
}

Dog&	Dog::operator=(Dog const &obj)
{
	std::cout << "Dog assignment operator called" << std::endl;
	this->type = obj.getType();
	this->brain = new Brain();
	*this->brain = *(obj.getBrain());
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof, Woof, Woof..." << std::endl;
}

void	Dog::printIdeas(void) const
{
	int	i;

	i = 0;
	while (!this->brain->getIdea(i).empty())
	{
		std::cout << this->brain->getIdea(i) << std::endl;
		i++;
	}
	return ;
}

void	Dog::addIdea(std::string idea)
{
	this->brain->setIdea(idea);
	return ;
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}

std::ostream&	operator<<(std::ostream &stream, Dog const &obj)
{
	stream << "Type: " << obj.getType() << std::endl;
	return (stream);
}
