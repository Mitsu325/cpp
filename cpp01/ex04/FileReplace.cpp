/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:59:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/11 00:42:41 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"

FileReplace::FileReplace(char* filename, char* s1, char* s2):
	_filename(filename), _s1(s1), _s2(s2)
{
	std::cout << "FileReplace constructor" << std::endl;
}

FileReplace::~FileReplace(void)
{
	std::cout << "FileReplace destructor" << std::endl;
}

int	FileReplace::getFileContent()
{
	std::fstream		fs_in;
	std::stringstream	buffer;

	fs_in.open(this->_filename, std::fstream::in);
	if (!fs_in.is_open())
	{
		std::cerr << "Error opening file: " << std::strerror(errno)
			<< std::endl;
		return (1);
	}
	buffer << fs_in.rdbuf();
	this->content = buffer.str();
	fs_in.close();
	return (0);
}

void	FileReplace::allStringReplace()
{
	size_t	found = 0;
	size_t	start_pos = 0;
	size_t	end_pos = 0;

	found = this->content.find(this->_s1, found);
	if (found == std::string::npos)
	{
		this->replaced_content = this->content;
		return ;
	}
	end_pos = found;
	this->replaced_content = this->content.substr(start_pos,
		end_pos - start_pos);
	this->replaced_content += this->_s2;
	start_pos = found + this->_s1.length();
	while (true)
	{
		found = this->content.find(this->_s1, found + this->_s1.length());
		if (found == std::string::npos)
		{
			this->replaced_content += this->content.substr(start_pos);
			break;
		}
		end_pos = found;
		this->replaced_content += this->content.substr(start_pos,
			end_pos - start_pos);
		this->replaced_content += this->_s2;
		start_pos = found + this->_s1.length();
	}
}

int	FileReplace::writeFile()
{
	std::fstream	fs_out;
	std::string		newFileName;

	newFileName = this->_filename;
	newFileName += ".replace";
	fs_out.open(newFileName.c_str(), std::fstream::out);
	if (!fs_out.is_open())
	{
		std::cerr << "Error opening file: " << std::strerror(errno)
			<< std::endl;
		return (1);
	}
	fs_out << this->replaced_content;
	fs_out.close();
	return (0);
}
