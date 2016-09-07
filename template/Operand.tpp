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
# include <sstream>
# include "IOperand.hpp"

//TODO USE THE TYPENAME
template <typename T>
class Operand : public IOperand {
	//PRIVATE ATTRIBUTS
	const eOperandType			_type;
	T							_value;

	//PRIVATE CONSTRUCTOR
								Operand(void) : _type(Int8), _value(0) {};

	//PRIVATE OVERLOAD

public:
	//PUBLIC CONSTRUCTOR
								Operand(const eOperandType type, const T value) : _type(type), _value(value) {};
								Operand(const Operand &rhs) : _type(rhs.getType()), _value(rhs.getValue()) {};
								~Operand(void) {};
	Operand 					&operator=(const Operand &rhs) { return (*new Operand(rhs)); };

	//PUBLIC GETTER
	eOperandType				getType(void) const { return (this->_type); };
	int 						getPrecision(void) const {
		switch (_type) {
			case Int8:
				return (Int8);
			case Int16:
				return (Int16);
			case Int32:
				return (Int32);
			case Float:
				return (Float);
			case Double:
				return (Double);
		}
		return (-1);
	};
	T							getValue(void) const { return (this->_value); };

	//TO STRING METHOD
	const std::string			&toString(void) const {
		std::ostringstream		ss;

		ss << this->_value;
		return *new std::string(ss.str());
	};



	//OPERATOR OVERLOAD
	const IOperand				*operator+(const IOperand &rhs) const {
		const Operand<T>		&down = static_cast<const Operand<T> &>(rhs);
		const Operand<T>		*final = new Operand<T>(_type, _value + down.getValue());

		return (final);
	};

	const IOperand				*operator-(const IOperand &rhs) const {
		const Operand<T>		&down = static_cast<const Operand<T> &>(rhs);
		const Operand<T>		*final = new Operand<T>(_type, _value - down.getValue());

		return (final);
	};

	const IOperand				*operator*(const IOperand &rhs) const {
		const Operand<T>		&down = static_cast<const Operand<T> &>(rhs);
		const Operand<T>		*final = new Operand<T>(_type, _value * down.getValue());

		return (final);
	};

	const IOperand				*operator/(const IOperand &rhs) const {
		const Operand<T>		&down = static_cast<const Operand<T> &>(rhs);
		const Operand<T>		*final = new Operand<T>(_type, _value / down.getValue());

		return (final);
	};

	const IOperand				*operator%(const IOperand &rhs) const {
		const Operand<T>		&down = static_cast<const Operand<T> &>(rhs);
		const Operand<T>		*final = new Operand<T>(_type, _value - down.getValue());

		return (final);
	};
	//TODO FACTORY METHOD
};

#endif