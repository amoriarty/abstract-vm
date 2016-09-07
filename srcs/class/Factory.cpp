//
//           :::      ::::::::
//         :+:      :+:    :+:     Factory.cpp
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 07/09/2016 14:09 by alegent
//

#include <iostream>
#include "Factory.hpp"
#include "Operand.tpp"

//PUBLIC CONSTRUCTOR
Factory::Factory(void) {
	//TODO STD::COUT
	std::cout << "Factory constructed" << std::endl;
	this->_map.push_back(&Factory::createInt8);
	this->_map.push_back(&Factory::createInt16);
}

//PUBLIC DESTRUCTOR
Factory::~Factory(void) {
	//TODO STD::COUT
	std::cout << "Factory destructed" << std::endl;
}

Factory::Factory(const Factory &rhs) {
	//TODO MAYBE CHANGE THAT
	static_cast<void>(rhs);
}

Factory						&Factory::operator=(const Factory &rhs) const {
	return (*new Factory(rhs));
}

//PUBLIC METHOD
const IOperand				*Factory::createOperand(const eOperandType type, std::string const &value) const {
	return (this->*(this->_map[type]))(value);
}


//PRIVATE METHOD
const IOperand				*Factory::createInt8(const std::string &value) const {
	//TODO CHAR CONVERSION
	return (new Operand<char>(Int8, atoi(value.c_str())));
}

const IOperand				*Factory::createInt16(const std::string &value) const {
	//TODO SHORT CONVERSION
	return (new Operand<short>(Int16, value[0]));
}