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
#include "Factory.hpp"

//TODO POUR LA PROCHAINE FOIS
// TU ES EN TRAIN DE FAIRE LE PARSEUR MAIS TU AS JUSTE APRIS A LIRE RAPIDEMENT UN FICHIER !

int												main(int ac, char **av) {
	Parser										parser;
	std::vector<std::string *>::const_iterator	it;
	std::vector<std::string *>::const_iterator	ite;

	try {
		if (ac == 2) {
			const std::vector<std::string *>	&command_list = parser.readFile(av[1]);
			it = command_list.begin();
			ite = command_list.end();
			while (it != ite)
				std::cout << **(it++) << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}