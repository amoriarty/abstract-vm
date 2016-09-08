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