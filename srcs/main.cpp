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
#include <fstream>
#include "Parser.hpp"
#include "Operand.tpp"
#include "Calculator.hpp"

//TODO STD::VECTOR<STD::STRING *>				_command_list -> CONST STD::STRING

int												main(int ac, char **av) {
	Parser										parser;
	//Operand<int>								*operand = new Operand<int>(Int8, 42);

	try {
		if (ac == 2) {
			Calculator							calculator(parser.readFile(av[1]));

			calculator.doMagic();
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}