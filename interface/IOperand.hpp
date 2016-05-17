//
//           :::      ::::::::
//         :+:      :+:    :+:     IOperand.h
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 5/13/16 11:57 AM by alegent
//

#ifndef IOPERAND_HPP
# define IOPERAND_HPP
# include <iostream>
# include "eOperandType.hpp"

class IOperand {

public:
	//PUBLIC GETTERS
	virtual int 						getPrecision(void) const = 0;
	virtual eOperandType				getType(void) const = 0;

	//PUBLIC OPERATOR OVERLOAD
	const virtual IOperand				*operator+(const IOperand &rhs) const = 0;
	const virtual IOperand				*operator-(const IOperand &rhs) const = 0;
	const virtual IOperand				*operator*(const IOperand &rhs) const = 0;
	const virtual IOperand				*operator/(const IOperand &rhs) const = 0;
	const virtual IOperand				*operator%(const IOperand &rhs) const = 0;

	//PUBLIC TO STRING METHOD
	const virtual std::string			&toString(void) const = 0;

	//PUBLIC DESTRUCTOR
	virtual 							~IOperand(void) {}
};

#endif
