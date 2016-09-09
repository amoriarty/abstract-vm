//
// Created by Alexandre LEGENT on 9/9/16.
//

#include "Parser.hpp"

//CONSTRUCTOR
Parser::Parser(void) {}
Parser::Parser(const Parser &rhs) { static_cast<void>(rhs); }
Parser::~Parser(void) {}
Parser					&Parser::operator=(const Parser &rhs) { return (*new Parser(rhs)); }