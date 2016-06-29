//
//           :::      ::::::::
//         :+:      :+:    :+:     Operand.h
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 5/13/16 2:01 PM by alegent
//

#ifndef OPERAND_TPP
# define OPERAND_TPP
# include "IOperand.hpp"

//TODO USE THE TYPENAME
//template <typename T>
class Operand : public IOperand {
	//PRIVATE ATTRIBUTS
	const eOperandType			_type;

	//PRIVATE CONSTRUCTOR
								Operand(void) : _type(Int8) {};

public:
	//PUBLIC CONSTRUCTOR
								Operand(const eOperandType type) : _type(type) {};
								Operand(const Operand &rhs) : _type(rhs.getType()) {};
								~Operand(void) {};
	Operand 					&operator=(const Operand &rhs) { return (*new Operand(rhs)); };

	//PUBLIC GETTER
	eOperandType				getType(void) const { return (this->_type); };
	int 						getPrecision(void) const { return (0); };
	//TODO IMPLEMENT TO STRING METHOD.
	//const std::string			&toString(void) const { };

	//OPERATOR OVERLOAD
	//TODO OPERATOR OVERLOAD
	/*
	Operand						*operator+(const Operand &rhs) { return (rhs); };
	Operand						*operator-(const Operand &rhs) { return (rhs); };
	Operand						*operator*(const Operand &rhs) { return (rhs); };
	Operand						*operator/(const Operand &rhs) { return (rhs); };
	Operand						*operator%(const Operand &rhs) { return (rhs); };
	*/

	//TODO FACTORY METHOD
};


#endif
