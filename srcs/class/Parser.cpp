//
// Created by Alexandre LEGENT on 9/9/16.
//

#include <iostream>
#include <fstream>
#include <regex>
#include <unistd.h>
#include "eOperandType.hpp"
#include "Exceptions.hpp"
#include "Parser.hpp"

const std::vector<std::string *>		&Parser::readFile(const char *file_name) {
	std::ifstream 					file;
	std::vector<std::string *>		*command_list = new std::vector<std::string *>;
	char 							*line = new char [BUFF_SIZE];

	if (access(file_name, F_OK) == -1)
		throw Exceptions::FileDoesNotExist();
	file.open(file_name);
	while (file.getline(line, BUFF_SIZE))
	{
		if (strlen(line))
			command_list->push_back(new std::string(line));
		if (!strncmp(line, "exit", 4))
			break ;
	}
	file.close();
	delete [] (line);
	if (command_list->size() && **(command_list->rbegin()) != "exit")
		throw Exceptions::MissingExitInstruction();
	return *command_list;
}

const std::vector<std::string *>		&Parser::readStdin(void) {
	std::vector<std::string *>		*command_list = new std::vector<std::string *>;
	char 							*line = new char [BUFF_SIZE];
	bool 							exit = false;

	while (strncmp(line, ";;", 2))
	{
		std::cin.getline(line, BUFF_SIZE);
		if (strlen(line) && strncmp(line, ";;", 2))
			command_list->push_back(new std::string(line));
		if (!strncmp(line, "exit", 4))
			exit = true;
	}
	delete [] (line);
	if (exit == false)
		throw Exceptions::MissingExitInstruction();
	return *command_list;
}

//LEXER
//TODO JE RISQUE D'AVOIR UN PROBLEME ENTRE LES COMMENTAIRES ET LA FIN DES ENTREE (';;')
eCommandType							Parser::getCommandType(const std::string &str) {
	if (str.substr(0, 5) == "push ")
		return PUSH;
	if (str.substr(0, 7) == "assert ")
		return ASSERT;
	if (str.substr(0, 1) == ";")
		return COMMENT;
	if (str.substr(0, 3) == "pop")
		return POP;
	if (str.substr(0, 4) == "dump")
		return DUMP;
	if (str.substr(0, 3) == "add")
		return ADD;
	if (str.substr(0, 3) == "sub")
		return SUB;
	if (str.substr(0, 3) == "mul")
		return MUL;
	if (str.substr(0, 3) == "div")
		return DIV;
	if (str.substr(0, 3) == "mod")
		return MOD;
	if (str.substr(0, 5) == "print")
		return PRINT;
	if (str.substr(0, 4) == "exit")
		return EXIT;
	if (str.substr(0, 2) == ";;")
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
	const char							*check;
	std::regex							num("^[0-9.-]*$");

	if (operand_value.find(')') != std::string::npos) {
		check = operand_value.substr(operand_value.find(')') + 1, std::string::npos).c_str();
		for (int i = 0; check[i]; i++) {
			if (check[i] == ';')
				break ;
			if (check[i] != ' ')
				throw Exceptions::Syntax();
		}
	}
	operand_value = operand_value.substr(0, operand_value.find(')'));
	if (!std::regex_match(operand_value, num))
		throw Exceptions::Syntax();
	return operand_value;
}