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
#include "eOperandType.hpp"

int										main(void) {
	eOperandType						*test = new eOperandType("int8");

	std::cout << *test << std::endl;
	delete test;
	return (EXIT_SUCCESS);
}