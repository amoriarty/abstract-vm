//
// Created by Alexandre LEGENT on 9/9/16.
//

#include <fstream>
#include "Parser.hpp"

//CONSTRUCTOR
Parser::Parser(void) {}
Parser::Parser(const Parser &rhs) { static_cast<void>(rhs); }
Parser::~Parser(void) {}
Parser					&Parser::operator=(const Parser &rhs) { return (*new Parser(rhs)); }

const std::vector<std::string *>		*Parser::readFile(const char *file_name) const {
	std::ifstream 					file;
	std::vector<std::string *>		*command_list = new std::vector<std::string *>;
	char 							*line = new char [BUFF_SIZE];

	file.open(file_name);
	while (file.getline(line, BUFF_SIZE))
		command_list->push_back(new std::string(line));
	delete [] (line);
	return command_list;
}