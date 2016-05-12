//
// Created by Alexandre LEGENT on 5/12/16.
//

#include <iostream>
#include "eOperandType.hpp"

int										main(void) {
	eOperandType						*test = new eOperandType("int8");

	std::cout << test->getType() << std::endl;
	delete test;
	return (EXIT_SUCCESS);
}