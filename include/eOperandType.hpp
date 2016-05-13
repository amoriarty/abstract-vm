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
	std::string									_type;
												eOperandType(void);
												eOperandType(eOperandType &rhs);

public:

												eOperandType(const std::string type);
												~eOperandType(void);
	eOperandType                       		 	&operator=(const eOperandType &rhs);

	const std::string							getType(void) const;
};

std::ostream									&operator<<(std::ostream &o, const eOperandType &rhs);


#endif
