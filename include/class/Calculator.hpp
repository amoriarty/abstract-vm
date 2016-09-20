//
// Created by Alexandre LEGENT on 9/20/16.
//

#ifndef CALCULATOR_HPP
# define CALCULATOR_HPP
# include <iostream>
# include <vector>

class Calculator {

	//PRIVATE ATTRIBUT
	const std::vector<std::string *>	*_command_list;
	std::vector<IOperand *>				_operand_table;


								Calculator(void);
								Calculator(const Calculator &rhs);
	Calculator                  operator=(const Calculator &rhs);

	public:
								Calculator(const std::vector<std::string *> &command_list);
								~Calculator(void);

	//CALCULATOR FUNCTIONS
	void 						push(IOperand *operand);
	void						dump(void) const;
	void 						doMagic(void);
};

#endif