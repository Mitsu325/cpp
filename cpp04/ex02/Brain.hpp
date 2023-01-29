/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:29:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 15:17:08 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_H

# include "iostream"
# include "string"

# define IDEA_SIZE 100

class Brain
{
	private:
		int	idea_index;

	protected:
		std::string	ideas[IDEA_SIZE];

	public:
		Brain(void);
		Brain(Brain const &obj);
		~Brain(void);
		Brain&	operator=(Brain const &obj);

		std::string	getIdea(int index) const;
		void		setIdea(std::string idea);
};

std::ostream&	operator<<(std::ostream &stream, Brain const &obj);

#endif
