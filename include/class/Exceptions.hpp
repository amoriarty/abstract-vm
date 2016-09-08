//
// Created by Alexandre LEGENT on 9/8/16.
//

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP
# include <iostream>

class Exceptions {
	Exceptions(void);
	Exceptions(const Exceptions &rhs);
	~Exceptions(void);
	Exceptions				&operator=(const Exceptions &rhs);

	public:
		class Overflow: public std::exception {
			public:
				const char 				*what(void) const throw();
		};

		class Underflow: public std::exception {
			public:
				const char				*what(void) const throw();
		};
};

#endif
