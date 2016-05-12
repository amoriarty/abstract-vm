//
// Created by Alexandre LEGENT on 5/12/16.
//

#ifndef EOPERANDTYPE_HPP
# define EOPERANDTYPE_HPP
# include <iostream>


class eOperandType {
	std::string							_type;
										eOperandType(void);
										eOperandType(eOperandType &rhs);

public:

										eOperandType(const std::string type);
										~eOperandType(void);
	eOperandType                        &operator=(const eOperandType &rhs);

	const std::string					getType(void) const;

};


#endif
