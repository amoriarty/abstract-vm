//
//           :::      ::::::::
//         :+:      :+:    :+:     eOperandType.h
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 5/13/16 11:47 AM by alegent
//

#ifndef EOPERANDTYPE_HPP
# define EOPERANDTYPE_HPP
# include <iostream>


class eOperandType {
	//PRIVATE ATTRIBUTS
	const std::string							_type;

	//PRIVAT CONSTRUCTOR
												eOperandType(void);

public:
	//PUBLIC CONSTRUCTOR
												eOperandType(const eOperandType &rhs);
												eOperandType(const std::string type);
												~eOperandType(void);
	eOperandType                       		 	&operator=(const eOperandType &rhs);

	//PUBLIC GETTER
	const std::string							getType(void) const;
};

//OSTREAM OPERATOR OVERLOAD
std::ostream									&operator<<(std::ostream &o, const eOperandType &rhs);


#endif
