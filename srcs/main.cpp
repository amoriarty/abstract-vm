//
//           :::      ::::::::
//         :+:      :+:    :+:     main.cpp
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 5/13/16 12:07 PM by alegent
//

#include <iostream>
#include <vector>
#include <map>
#include "Operand.tpp"
#include "Factory.hpp"
#include "eOperandType.hpp"
#include <limits>

void									dump(IOperand *operand)
{
	std::cout << operand->toString() << std::endl;
}



int										main(void) {
	Factory								manufactory;
	const IOperand						*n;

	std::cout << "Min Limit char " << std::numeric_limits<char>::min() << std::endl;
	std::cout << "Max Limit char " << std::numeric_limits<char>::max() << std::endl;
	std::cout << "Min Limit short " << std::numeric_limits<short>::min() << std::endl;
	std::cout << "Max Limit short " << std::numeric_limits<short>::max() << std::endl;
	std::cout << "Min Limit int " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "Max Limit int " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "Min Limit float " << std::numeric_limits<float>::min() << std::endl;
	std::cout << "Max Limit float " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "Min Limit double " << std::numeric_limits<double>::min() << std::endl;
	std::cout << "Max Limit double " << std::numeric_limits<double>::max() << std::endl;

	try {
		n = manufactory.createOperand(Float, "1.17549e+500");
		std::cout << n->toString() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}