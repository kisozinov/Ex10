// Copyright 2021 Sozinov Kirill
#ifndef INCLUDE_POSTFIX_H_
#define INCLUDE_POSTFIX_H_

#include "MyStack.h"
#include <string>
#include <map>

std::string infix2postfix(const std::string);
bool isOperation(std::map<const char, const unsigned int> *pr, char s);

#endif  // INCLUDE_POSTFIX_H_
