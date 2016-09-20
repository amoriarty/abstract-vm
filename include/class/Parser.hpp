//
// Created by Alexandre LEGENT on 9/9/16.
//

#ifndef PARSER_HPP
# define PARSER_HPP
# include <vector>

# define BUFF_SIZE 256

class Parser {

											Parser(const Parser &rhs);
	Parser									&operator=(const Parser &rhs);

	public:
											Parser(void);
											~Parser(void);

	const std::vector<std::string *>		&readFile(const char *file_name) const;

};

#endif
