/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 00:21:51 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/20 03:52:12 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string	readContent(std::ifstream &file)
{
	std::string	content;
	char		c;

	while (file.get(c))
		content = content + c;
	return (content);
}

void	writeReplaced(std::ofstream &file, const std::string &content, const std::string &s1,
		const std::string &s2)
{
	std::string::size_type	start;
	std::string::size_type	pos;

	start = 0;
	pos = content.find(s1, start);
	while (pos != std::string::npos)
	{
		file << content.substr(start, pos - start);
		file << s2;
		start = pos + s1.length();
		pos = content.find(s1, start);
	}
	file << content.substr(start);
}

int	checkArgs(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: <./program> <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	if (std::string(argv[2]).empty())
	{
		std::cerr << "s1 can't be empty" << std::endl;
		return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (checkArgs(argc, argv) == 1)
		return 1;

	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::ifstream	readFile(filename.c_str()); //reads a file
	if (!readFile)
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return 1;
	}
	std::string		outputFile = filename + ".replace";
	std::ofstream	fileReplace(outputFile.c_str()); //creates and opens a file
	if (!fileReplace)
	{
		std::cerr << "Error: could not open output file" << std::endl;
		return 1;
	}
	std::string		content;
	content = readContent(readFile);
	writeReplaced(fileReplace, content, s1, s2);
	readFile.close();
	return 0;
}

