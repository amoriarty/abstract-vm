//
// Created by Alexandre LEGENT on 9/8/16.
//

#include "Exceptions.hpp"

//CONSTRUCTOR
Exceptions::Exceptions(void) {}
Exceptions::Exceptions(const Exceptions &rhs) { static_cast<void>(rhs); }
Exceptions::~Exceptions(void) {}
Exceptions					&Exceptions::operator=(const Exceptions &rhs) {
	return (*new Exceptions(rhs));
}
const char *
Exceptions::Overflow::what(void) const throw() {
	return ("Overflow on a value.");
}

const char *
Exceptions::Underflow::what(void) const throw() {
	return ("Underflow on a value.");
}

const char *
Exceptions::Syntax::what(void) const throw() {
	return ("Syntax error.");
}

const char *
Exceptions::UnknownInstruction::what(void) const throw() {
	return ("Unknown instruction.");
}

const char *
Exceptions::PopOnEmptyStack::what(void) const throw() {
	return ("Try to pop an empty stack.");
}

const char *
Exceptions::FloatingPointException::what(void) const throw() {
	return ("Division/Modulo by 0.");
}

const char *
Exceptions::MissingExitInstruction::what(void) const throw() {
	return ("Missing exit instruction.");
}

const char *
Exceptions::AssertError::what(void) const throw() {
	return ("Assert instruction is not true.");
}

const char *
Exceptions::OperationOnEmptyStack::what() const throw() {
	return ("Operation can't be done because the stack have less than two operands.");
}