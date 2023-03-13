/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:35:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 16:09:06 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void): idea_index(0)
{
	std::cout << "Brain constructor called" << std::endl;
	return ;
}

Brain::Brain(Brain const &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain&	Brain::operator=(Brain const &obj)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (size_t i = 0; i < IDEA_SIZE; i++)
		{
			this->ideas[i] = obj.getIdea(i);
		}
	}
	return (*this);
}

std::string	Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}

void	Brain::setIdea(std::string idea)
{
	this->ideas[this->idea_index] = idea;
	this->idea_index++;
	return ;
}

std::ostream&	operator<<(std::ostream &stream, Brain const &obj)
{
	int	i;

	i = 0;
	while (!obj.getIdea(i).empty())
	{
		stream << obj.getIdea(i) << std::endl;
		i++;
	}
	return (stream);
}
