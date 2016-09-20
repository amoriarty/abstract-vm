//
// Created by Alexandre LEGENT on 9/20/16.
//

#include "Parser.hpp"
#include "Exceptions.hpp"
#include "IOperand.hpp"
#include "Calculator.hpp"

Calculator::Calculator(void) : _command_list(NULL) {}
//TODO GET STD::VECTOR
Calculator::Calculator(const Calculator &rhs) : _command_list(NULL)  { static_cast<void>(rhs); }
Calculator::~Calculator(void) {}
Calculator							Calculator::operator=(const Calculator &rhs) { return *new Calculator(rhs); }

Calculator::Calculator(const std::vector<std::string *> &command_list) : _command_list(&command_list) {}

void 								Calculator::doMagic(void) {
	Parser											parser;
	std::vector<std::string *>::const_iterator		it;
	std::vector<std::string *>::const_iterator		ite;

	it = _command_list->begin();
	ite = _command_list->end();
	while (it != ite) {
		switch (parser.getCommandType(**it)) {
			case ERROR:
				throw Exceptions::UnknownInstruction();
			case DUMP:
				this->dump();
				break ;
			default:
				break ;
		}
		it++;
	}
}

void 								Calculator::push(IOperand *operand) {
	_operand_table.push_back(operand);
}

void								Calculator::dump(void) const {
	std::vector<IOperand *>::const_iterator			it;
	std::vector<IOperand *>::const_iterator			ite;

	it = _operand_table.begin();
	ite = _operand_table.end();
	while (it != ite) {
		std::cout << (*it)->toString() << std::endl;
		it++;
	}
}