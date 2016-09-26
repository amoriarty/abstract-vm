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
# include "Factory.hpp"
# include "Exceptions.hpp"

template <typename T>
class Operand : public IOperand {
	//PRIVATE ATTRIBUTS
	const eOperandType			_type;
	T							_value;
	Factory						_factory;

	//PRIVATE CONSTRUCTOR
	Operand(void) : _type(Int8), _value(0) {};

	public:
		//PUBLIC CONSTRUCTOR
		Operand(const eOperandType type, const T value) : _type(type), _value(value) {};
		Operand(const Operand &rhs) : _type(rhs.getType()), _value(rhs.getValue()) {};
		~Operand(void) {};
		Operand &
		operator=(const Operand &rhs) { return (*new Operand(rhs)); };

		//PUBLIC GETTER
		eOperandType
		getType(void) const { return (this->_type); };
		int
		getPrecision(void) const { return (_type); };
		T
		getValue(void) const { return (this->_value); };

		//TO STRING METHOD
		const std::string &
		toString(void) const {
			std::ostringstream		ss;

			if (this->_type == Int8)
				ss << static_cast<int>(this->_value);
			else
				ss << this->_value;
			return *new std::string(ss.str());
		};

		//OPERATOR OVERLOAD
		const IOperand *
		operator+(const IOperand &rhs) const {
			const Operand<T>	*down = NULL;
			eOperandType 		type;
			int					iv = 0;
			double 				id = 0;

			if (_type == rhs.getPrecision()) {
				down = static_cast<const Operand<T> *>(&rhs);
				return (new Operand<T>(_type, down->getValue() + _value));
			}
			else {
				if (_type > rhs.getPrecision())
					type = _type;
				else
					type = rhs.getType();
				switch (type) {
					case Int8:
					case Int16:
					case Int32:
						iv = std::stoi(rhs.toString()) + _value;
						break ;
					case Float:
					case Double:
						id = std::stod(rhs.toString()) + _value;
						break ;
					case Error:
						break ;
				}
				return (_factory.createOperand(type, std::to_string((iv) ? iv : id)));
			}
			return (NULL);
		}

		const IOperand *
		operator-(const IOperand &rhs) const {
			const Operand<T>	*down = NULL;
			eOperandType 		type;
			int					iv = 0;
			double 				id = 0;

			if (_type == rhs.getPrecision()) {
				down = static_cast<const Operand<T> *>(&rhs);
				return (new Operand<T>(_type, down->getValue() - _value));
			}
			else {
				if (_type > rhs.getPrecision())
					type = _type;
				else
					type = rhs.getType();
				switch (type) {
					case Int8:
					case Int16:
					case Int32:
						iv = std::stoi(rhs.toString()) - _value;
						break ;
					case Float:
					case Double:
						id = std::stod(rhs.toString()) - _value;
						break ;
					case Error:
						break ;
				}
				return (_factory.createOperand(type, std::to_string((iv) ? iv : id)));
			}
			return (NULL);
		}

		const IOperand *
		operator*(const IOperand &rhs) const {
			const Operand<T>	*down = NULL;
			eOperandType 		type;
			int					iv = 0;
			double 				id = 0;

			if (_type == rhs.getPrecision()) {
				down = static_cast<const Operand<T> *>(&rhs);
				return (new Operand<T>(_type, down->getValue() * _value));
			}
			else {
				if (_type > rhs.getPrecision())
					type = _type;
				else
					type = rhs.getType();
				switch (type) {
					case Int8:
					case Int16:
					case Int32:
						iv = std::stoi(rhs.toString()) * _value;
						break ;
					case Float:
					case Double:
						id = std::stod(rhs.toString()) * _value;
						break ;
					case Error:
						break ;
				}
				return (_factory.createOperand(type, std::to_string((iv) ? iv : id)));
			}
			return (NULL);
		}

		const IOperand *
		operator/(const IOperand &rhs) const {
			const Operand<T>	*down = NULL;
			eOperandType 		type;
			int					iv = 0;
			double 				id = 0;

			if (_type == rhs.getPrecision()) {
				down = static_cast<const Operand<T> *>(&rhs);
				if (!(_value))
					throw Exceptions::FloatingPointException();
				return (new Operand<T>(_type, down->getValue() / _value));
			}
			else {
				if (!(_value))
					throw Exceptions::FloatingPointException();
				if (_type > rhs.getPrecision())
					type = _type;
				else
					type = rhs.getType();
				switch (type) {
					case Int8:
					case Int16:
					case Int32:
						iv = std::stoi(rhs.toString()) / _value;
						break ;
					case Float:
					case Double:
						id = std::stod(rhs.toString()) / _value;
						break ;
					case Error:
						break ;
				}
				return (_factory.createOperand(type, std::to_string((iv) ? iv : id)));
			}
			return (NULL);
		}

		const IOperand *
		operator%(const IOperand &rhs) const {
			const Operand<T>	*down = NULL;
			eOperandType 		type;
			int					iv = 0;
			long int			id = 0;

			if (_type == rhs.getPrecision()) {
				down = static_cast<const Operand<T> *>(&rhs);
				if (!(_value))
					throw Exceptions::FloatingPointException();
				return (new Operand<T>(_type, static_cast<long int>(down->getValue()) % static_cast<long int>(_value)));
			}
			else {
				if (!(_value))
					throw Exceptions::FloatingPointException();
				if (_type > rhs.getPrecision())
					type = _type;
				else
					type = rhs.getType();
				switch (type) {
					case Int8:
					case Int16:
					case Int32:
						iv = static_cast<long int>(std::stoi(rhs.toString())) % static_cast<long int>(_value);
						break ;
					case Float:
					case Double:
						throw Exceptions::ModuloOnFloatingPoint();
					case Error:
						break ;
				}
				return (_factory.createOperand(type, std::to_string((iv) ? iv : id)));
			}
			return (NULL);
		}
};

#endif
