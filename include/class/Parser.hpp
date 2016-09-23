//
// Created by Alexandre LEGENT on 9/9/16.
//

#ifndef PARSER_HPP
# define PARSER_HPP
# include <vector>
# include "eCommandType.hpp"
# include "eOperandType.hpp"

# define BUFF_SIZE 256

namespace Parser {
	//PARSER
	const std::vector<std::string *>		&readFile(const char *file_name);

	//LEXER
	eCommandType							getCommandType(const std::string &str);
	eOperandType 							getOperandType(const std::string &str);
	std::string								getOperandValue(const std::string &str);
};

#endif
