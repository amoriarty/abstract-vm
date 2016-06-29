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
	Operand<int>						*test = new Operand<int>(Int8);

	std::cout << test->getType() << std::endl;
	delete test;
	return (EXIT_SUCCESS);
}