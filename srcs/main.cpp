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

void									dump(IOperand *operand)
{
	std::cout << operand->toString() << std::endl;
}



int										main(void) {
	Factory								manufactory;
	const IOperand						*n;

	n = manufactory.createOperand(Int8, "42");
	std::cout << n->toString() << std::endl;

	return (EXIT_SUCCESS);
}