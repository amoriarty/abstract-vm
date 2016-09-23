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
	try {
		if (ac == 2) {
			Calculator							calculator(Parser::readFile(av[1]));

			calculator.doMagic();
		}
		else if (ac == 1) {
			Calculator							cal(Parser::readStdin());

			cal.doMagic();
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}