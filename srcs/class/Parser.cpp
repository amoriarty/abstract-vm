//
// Created by Alexandre LEGENT on 9/9/16.
//

#include <iostream>
#include <fstream>
#include <regex>
#include "Parser.hpp"

//CONSTRUCTOR
Parser::Parser(void) {}
Parser::Parser(const Parser &rhs) { static_cast<void>(rhs); }
Parser::~Parser(void) {}
Parser					&Parser::operator=(const Parser &rhs) { return (*new Parser(rhs)); }

//PARSER
const std::vector<std::string *>		&Parser::readFile(const char *file_name) const {
	std::ifstream 					file;
	std::vector<std::string *>		*command_list = new std::vector<std::string *>;
	char 							*line = new char [BUFF_SIZE];

	file.open(file_name);
	while (file.getline(line, BUFF_SIZE))
	{
		if (strlen(line))
			command_list->push_back(new std::string(line));
	}
	file.close();
	delete [] (line);
	return *command_list;
}

//LEXER
eCommandType							Parser::getCommandType(const std::string &str) const throw() {
	if (str.substr(0, 4) == "push")
		return PUSH;
	if (str.substr(0, 6) == "assert")
		return ASSERT;
	if (str.substr(0, 2) == "; ")
		return COMMENT;
	if (str == "pop")
		return POP;
	if (str == "dump")
		return DUMP;
	if (str == "add")
		return ADD;
	if (str == "sub")
		return SUB;
	if (str == "mul")
		return MUL;
	if (str == "div")
		return DIV;
	if (str == "mod")
		return MOD;
	if (str == "print")
		return PRINT;
	if (str == "exit")
		return EXIT;
	if (str == ";;")
		return END;
	return ERROR;
}