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
#include <string>
#include "Factory.hpp"
#include "Operand.tpp"

//PUBLIC CONSTRUCTOR
Factory::Factory(void) {
	//TODO STD::COUT
	std::cout << "Factory constructed" << std::endl;
	this->_map.push_back(&Factory::createInt8);
	this->_map.push_back(&Factory::createInt16);
	this->_map.push_back(&Factory::createInt32);
	this->_map.push_back(&Factory::createFloat);
	this->_map.push_back(&Factory::createDouble);
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
	int 					number = atoi(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.compare(ss.str()) != 0) {
		if (value.find('-') != std::string::npos)
			throw Factory::Underflow();
		throw Factory::Overflow();
	}
	return new Operand<char>(Int8, static_cast<char>(number));
}

const IOperand				*Factory::createInt16(const std::string &value) const {
	int 					number = atoi(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.compare(ss.str()) != 0) {
		if (value.find('-') != std::string::npos)
			throw Factory::Underflow();
		throw Factory::Overflow();
	}
	return new Operand<short>(Int16, static_cast<short>(number));
}

const IOperand				*Factory::createInt32(const std::string &value) const {
	int 					number = atoi(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.compare(ss.str()) != 0) {
		if (value.find('-') != std::string::npos)
			throw Factory::Underflow();
		throw Factory::Overflow();
	}
	return new Operand<int>(Int32, number);
}

const IOperand				*Factory::createFloat(const std::string &value) const {
	double 					number = atof(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.compare(ss.str()) != 0) {
		if (value.find('-') != std::string::npos)
			throw Factory::Underflow();
		throw Factory::Overflow();
	}
	return new Operand<float>(Float, static_cast<float>(number));
}

const IOperand				*Factory::createDouble(const std::string &value) const {
	double 					number = atof(value.c_str());
	std::ostringstream		ss;

	ss << number;
	if (value.compare(ss.str()) != 0) {
		if (value.find('-') != std::string::npos)
			throw Factory::Underflow();
		throw Factory::Overflow();
	}
	return new Operand<double>(Double, number);
}

//EXCEPTION CLASS
const char 					*Factory::Overflow::what(void) const throw() {
	return ("Overflow on a value.");
}

const char 					*Factory::Underflow::what(void) const throw() {
	return ("Underflow on a value.");
}