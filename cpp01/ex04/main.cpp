/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:59:07 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/10 22:46:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"
#include <fstream>
#include <sstream>

int	main()
{
	std::fstream		fs_in;
	std::fstream		fs_out;
	std::stringstream	buffer;
	std::string			content;
	std::string			new_content;
	std::string			s1 = "Lorem Ipsum";
	std::string			s2 = "This is example";
	size_t				found = 0;
	size_t				start = 0;
	size_t				end = 0;

	fs_in.open("test", std::fstream::in);
	buffer << fs_in.rdbuf();
	content = buffer.str();
	fs_in.close();
	found = content.find(s1, found);
	end = found;
	new_content = content.substr(start, end - start);
	new_content += s2;
	start = found + s1.length();
	while (true)
	{
		found = content.find(s1, found + s1.length());
		if (found == std::string::npos)
		{
			new_content += content.substr(start);
			break;
		}
		end = found;
		new_content += content.substr(start, end - start);
		new_content += s2;
		start = found + s1.length();
	}
	fs_out.open("test.replace", std::fstream::out);
	fs_out << new_content;
	fs_out.close();
	return (0);
}
