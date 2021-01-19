// Copyright 2021 Sozinov Kirill
#ifndef INCLUDE_POSTFIX_H_
#define INCLUDE_POSTFIX_H_

#include "MyStack.h"
#include <string>
#include <map>

std::string infix2prefix(const std::string);
bool isOperation(std::map<char, unsigned int> &pr, char s);

#endif  // INCLUDE_POSTFIX_H_
