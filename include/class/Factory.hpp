//
//           :::      ::::::::
//         :+:      :+:    :+:     Factory.h
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 07/09/2016 12:56 by alegent
//

#ifndef FACTORY_HPP
# define FACTORY_HPP
# include <vector>
# include "IOperand.hpp"
# include "eOperandType.hpp"

class Factory {
	//PRIVATE ATTRIBUTS
	std::vector<const IOperand *(Factory::*)(const std::string &) const>	_map;

	//PRIVATE CONSTRUCTOR
	//TODO MAKE THEM PUBLIC
						Factory(const Factory &rhs);
	Factory				&operator=(const Factory &rhs) const;

	//PRIVATE FACTORY METHOD
	const IOperand		*createInt8(const std::string &value) const;
	const IOperand		*createInt16(const std::string &value) const;
	const IOperand		*createInt32(const std::string &value) const;
	const IOperand		*createFloat(const std::string &value) const;
	const IOperand		*createDouble(const std::string &value) const;

	public:
	//PUBLIC CONSTRUCTOR AND DESTRUCTOR
						Factory(void);
						~Factory(void);

	//PUBLIC FACTORY METHOD
	const IOperand *createOperand(const eOperandType type, const std::string &value) const;
};

#endif
