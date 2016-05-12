//
// Created by Alexandre LEGENT on 5/12/16.
//

#include "eOperandType.hpp"

//PRIVATE CONSTRUCTOR
//DEFAULT
eOperandType::eOperandType(void) : _type(NULL) { }

//COPY
eOperandType::eOperandType(eOperandType &rhs) : _type(rhs.getType()) { }

//PUBLIC CONSTRUCTOR
//DEFAULT
eOperandType::eOperandType(const std::string type) : _type(type) { }

//DESCONSTRUCTOR
eOperandType::~eOperandType(void) { }

//COPY OPERATOR
eOperandType						&eOperandType::operator=(const eOperandType &rhs) {
	return (*new eOperandType(rhs.getType()));
}

//PUBLIC METHOD
const std::string					eOperandType::getType(void) const { return (this->_type); }

//OSTREAM OPERATOR OVERLOAD
std::ostream						&operator<<(std::ostream &o, const eOperandType &rhs) {
	o << rhs.getType();
	return (o);
}