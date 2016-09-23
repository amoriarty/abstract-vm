//
// Created by Alexandre LEGENT on 9/9/16.
//

#include <iostream>
#include <fstream>
#include <regex>
#include <eOperandType.hpp>
#include <class/Exceptions.hpp>
#include "Parser.hpp"

const std::vector<std::string *>		&Parser::readFile(const char *file_name) {
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
	if (strncmp(line, "exit", 4))
		throw Exceptions::MissingExitInstruction();
	delete [] (line);
	return *command_list;
}

//LEXER
//TODO JE RISQUE D'AVOIR UN PROBLEME ENTRE LES COMMENTAIRES ET LA FIN DES ENTREE (';;')
eCommandType							Parser::getCommandType(const std::string &str) {
	if (str.substr(0, 4) == "push")
		return PUSH;
	if (str.substr(0, 6) == "assert")
		return ASSERT;
	if (str.substr(0, 1) == ";")
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

eOperandType							Parser::getOperandType(const std::string &str) {
	std::string							operand_type = str.substr(str.find(' ') + 1, str.size());

	if (operand_type.substr(0, 4) == "int8")
		return Int8;
	if (operand_type.substr(0, 5) == "int16")
		return Int16;
	if (operand_type.substr(0, 5) == "int32")
		return Int32;
	if (operand_type.substr(0, 5) == "float")
		return Float;
	if (operand_type.substr(0, 6) == "double")
		return Double;
	return Error;
}

std::string								Parser::getOperandValue(const std::string &str) {
	std::string							operand_value = str.substr(str.find('(') + 1, str.size());

	return operand_value.substr(0, operand_value.find(')'));
}