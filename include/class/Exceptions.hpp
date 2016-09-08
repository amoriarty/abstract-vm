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

		class Syntax: public std::exception {
			public:
				const char				*what(void) const throw();
		};

		class UnknownInstruction: public std::exception {
			public:
				const char				*what(void) const throw();
		};

		class PopOnEmptyStack: public std::exception {
			public:
				const char 				*what(void) const throw();
		};

		class FloatingPointException: public std::exception {
			public:
				const char				*what(void) const throw();
		};

		class MissingExitInstruction: public std::exception {
			public:
				const char				*what(void) const throw();
		};

		class AssertError: public std::exception {
			public:
				const char				*what(void) const throw();
		};

		class OperationOnEmptyStack: public std::exception {
			public:
				const char				*what(void) const throw();
		};
};

#endif
