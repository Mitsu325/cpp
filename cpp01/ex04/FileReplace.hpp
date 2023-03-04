/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:59:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/11 00:36:08 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FILE_REPLACE_H

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstring>

class FileReplace
{
	private:
		char*		_filename;
		std::string	_s1;
		std::string	_s2;
		std::string	_content;
		std::string	_replaced_content;

	public:
		FileReplace(char* filename, char* s1, char* s2);
		~FileReplace(void);

		int		getFileContent();
		void	allStringReplace();
		int		writeFile();
};

#endif
