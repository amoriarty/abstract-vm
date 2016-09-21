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
	std::vector<std::string *>::const_iterator		it;
	std::vector<std::string *>::const_iterator		ite;

	it = _command_list->begin();
	ite = _command_list->end();
	while (it != ite) {
		switch (_parser.getCommandType(**it)) {
			case ERROR:
				throw Exceptions::UnknownInstruction();
			case DUMP:
				this->dump();
				break ;
			case PUSH:
				this->push(**it);
				break ;
			case POP:
				this->pop();
				break ;
			default:
				break ;
		}
		it++;
	}
}

void 								Calculator::push(const std::string &str) {
	eOperandType 					openrand_type = _parser.getOperandType(str);
	std::string						value = _parser.getOperandValue(str);

	switch (openrand_type) {
		case Error:
			throw Exceptions::UnknownInstruction();
		default:
			_operand_table.push_back(_factory.createOperand(openrand_type, value));
			break ;
	}
}

void								Calculator::pop(void) {
	if (_operand_table.empty())
		throw Exceptions::PopOnEmptyStack();
	_operand_table.pop_back();
}

void								Calculator::dump(void) const {
	std::vector<const IOperand *>::const_reverse_iterator	it;
	std::vector<const IOperand *>::const_reverse_iterator	ite;

	it = _operand_table.rbegin();
	ite = _operand_table.rend();
	while (it != ite) {
		std::cout << (*it)->toString() << std::endl;
		it++;
	}
}