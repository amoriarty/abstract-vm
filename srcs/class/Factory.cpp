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
#include "Exceptions.hpp"
#include "Operand.tpp"

//PUBLIC CONSTRUCTOR
Factory::Factory(void) {
	this->_func.push_back(&Factory::createInt8);
	this->_func.push_back(&Factory::createInt16);
	this->_func.push_back(&Factory::createInt32);
	this->_func.push_back(&Factory::createFloat);
	this->_func.push_back(&Factory::createDouble);
}

//PUBLIC DESTRUCTOR
Factory::~Factory(void) {}

//PRIVATE CONSTRUCTOR
Factory::Factory(const Factory &rhs) {
	static_cast<void>(rhs);
	Factory();
}

Factory &
Factory::operator=(const Factory &rhs) const {
	return (*new Factory(rhs));
}

//PUBLIC METHOD
const IOperand *
Factory::createOperand(const eOperandType type, std::string const &value) const {
	return (this->*(this->_func[type]))(value);
}

//PRIVATE METHOD
const IOperand *
Factory::createInt8(const std::string &value) const {
	int 					number = atoi(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0) {
		if (value.find('-') != std::string::npos)
			throw Exceptions::Underflow();
		throw Exceptions::Overflow();
	}
	return new Operand<char>(Int8, static_cast<char>(number));
}

const IOperand *
Factory::createInt16(const std::string &value) const {
	int 					number = atoi(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0) {
		if (value.find('-') != std::string::npos)
			throw Exceptions::Underflow();
		throw Exceptions::Overflow();
	}
	return new Operand<short>(Int16, static_cast<short>(number));
}

const IOperand *
Factory::createInt32(const std::string &value) const {
	int 					number = atoi(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0) {
		if (value.find('-') != std::string::npos)
			throw Exceptions::Underflow();
		throw Exceptions::Overflow();
	}
	return new Operand<int>(Int32, number);
}

const IOperand *
Factory::createFloat(const std::string &value) const {
	double 					number = atof(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0) {
		if (value.find('-') != std::string::npos)
			throw Exceptions::Underflow();
		throw Exceptions::Overflow();
	}
	return new Operand<float>(Float, static_cast<float>(number));
}

const IOperand *
Factory::createDouble(const std::string &value) const {
	double 					number = atof(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.substr(0, value.find('.')).compare(ss.str().substr(0, ss.str().find('.'))) != 0) {
		if (value.find('-') != std::string::npos)
			throw Exceptions::Underflow();
		throw Exceptions::Overflow();
	}
	return new Operand<double>(Double, number);
}
