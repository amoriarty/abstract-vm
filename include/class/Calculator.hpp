//
// Created by Alexandre LEGENT on 9/20/16.
//

#ifndef CALCULATOR_HPP
# define CALCULATOR_HPP
# include <iostream>
# include <vector>
# include "Factory.hpp"

class Calculator {

	//PRIVATE ATTRIBUT
	const Factory						_factory;
	const Parser						_parser;
	const std::vector<std::string *>	*_command_list;
	std::vector<const IOperand *>		_operand_table;


								Calculator(void);
								Calculator(const Calculator &rhs);
	Calculator                  operator=(const Calculator &rhs);

	public:
								Calculator(const std::vector<std::string *> &command_list);
								~Calculator(void);

	//CALCULATOR FUNCTIONS
	void 						push(const std::string &str);
	void 						pop(void);
	void						dump(void) const;
	void 						assert(const std::string &str) const;
	void 						doMagic(void);
};

#endif