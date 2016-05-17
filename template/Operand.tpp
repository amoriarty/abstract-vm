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
# include <IOperand.hpp>

template <typename T>
class Operand : public IOperand {
	//PRIVATE ATTRIBUTS
	const eOperandType			&_type;

	//PRIVATE CONSTRUCTOR
								Operand(void) : _type(*(new eOperandType(NULL))) {};

public:
	//PUBLIC CONSTRUCTOR
								Operand(const std::string type) : _type(*(new eOperandType(type))) {};
								Operand(const Operand &rhs) : _type(rhs.getType()) {};
								~Operand(void) {};
	Operand 					&operator=(const Operand &rhs) { return (*new Operand(rhs)); };

	//PUBLIC GETTER
	eOperandType				getType(void) const { return (this->_type); };
	int 						getPrecision(void) const { return (0); };
	const std::string			&toString(void) const { return this->_type.getType(); };

	//OPERATOR OVERLOAD
	Operand						*operator+(const Operand &rhs) { static_cast<void>(rhs); };
	Operand						*operator-(const Operand &rhs) { static_cast<void>(rhs); };
	Operand						*operator*(const Operand &rhs) { static_cast<void>(rhs); };
	Operand						*operator/(const Operand &rhs) { static_cast<void>(rhs); };
	Operand						*operator%(const Operand &rhs) { static_cast<void>(rhs); };
};


#endif
