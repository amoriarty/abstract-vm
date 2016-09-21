//
// Created by Alexandre LEGENT on 9/9/16.
//

#ifndef PARSER_HPP
# define PARSER_HPP
# include <vector>
# include "eCommandType.hpp"
# include "eOperandType.hpp"

# define BUFF_SIZE 256

//TODO CHANGE TO NAMESPACE
class Parser {

											Parser(const Parser &rhs);
	Parser									&operator=(const Parser &rhs);

	public:
											Parser(void);
											~Parser(void);

	//PARSER
	const std::vector<std::string *>		&readFile(const char *file_name) const;

	//LEXER
	eCommandType							getCommandType(const std::string &str) const;
	eOperandType 							getOperandType(const std::string &str) const;
	std::string								getOperandValue(const std::string &str) const;
};

#endif
