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

int										main(int ac, char **av) {
	std::ifstream						file;
	char 								line[256];

	if (ac == 2)
	{
		file.open(av[1]);
		while (file.getline(line, 256))
			std::cout << line << std::endl;
		file.close();
	}
	return (EXIT_SUCCESS);
}