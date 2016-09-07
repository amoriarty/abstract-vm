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
#include "Operand.tpp"


int										main(void) {
	Operand<float>						*t1 = new Operand<float>(Float, 42.01);
	Operand<float>						*t2 = new Operand<float>(Float, 42.01);
	const IOperand						*t3;
	const IOperand						*t4;
	const IOperand						*t5;
	const IOperand						*t6;

	std::cout << t1->toString() << std::endl;
	std::cout << t2->toString() << std::endl;

	t3 = *t1 + *t2;
	std::cout << t3->toString() << std::endl;

	t4 = *t1 - *t2;
	std::cout << t4->toString() << std::endl;

	t5 = *t1 / *t2;
	std::cout << t5->toString() << std::endl;

	t6 = *t1 % *t2;
	std::cout << t6->toString() << std::endl;

	std::cout << t6->getPrecision() << std::endl;

	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
	return (EXIT_SUCCESS);
}