// Copyright 2021 Sozinov Kirill
#include <iostream>
#include "postfix.h"

std::map<char, unsigned int> priority = { {'(', 0}, {')', 1}, {'+', 2},
                                  {'-', 2}, {'*', 3}, {'/', 3} };
MyStack<char> stack(200);

bool isOperation(std::map<char, unsigned int> &pr, char s) {
    bool res = false;
    std::map<char, unsigned int>::iterator it;
    for (it = pr.begin(); it != pr.end(); ++it) {
        if (it->first == s)
            return true;
    }
}

std::string infix2prefix(const std::string inp) {
    std::string out;
    

    for (unsigned int i = 0; i < inp.length(); ++i) {
        if (inp[i] == ' ')
            continue;
        if (inp[i] == ')') {
            while (stack.get() != '(') {
                out.push_back(stack.pop());
                out.push_back(' ');
            }
            stack.pop();
            continue;
        }
        if (isOperation(priority, inp[i])) {
            if ((priority[inp[i]] == 0) || (priority[inp[i]] > priority[stack.get()]) || (stack.isEmpty()))
                stack.push(inp[i]);
            else {
                while (priority[stack.get()] >= priority[inp[i]]) {
                    out.push_back(stack.pop());
                    out.push_back(' ');
                }
                stack.push(inp[i]);
            }

        } else {
            out.push_back(inp[i]);
            out.push_back(' ');
        }
    }

    while (!stack.isEmpty()) {
        out.push_back(stack.pop());
        out.push_back(' ');
    }
    if (out[out.length()-1] == ' ')
        out.pop_back();
    return out;
}
