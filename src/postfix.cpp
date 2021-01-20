// Copyright 2021 Sozinov Kirill
#include <iostream>
#include "postfix.h"



bool isOperation(std::map<const char, const unsigned int> *pr, char s) {
    bool res = false;
    for (auto& kv : *pr) {
        if (kv.first == s)
            return true;
    }
}

std::string infix2postfix(const std::string inp) {
    std::string out;
    MyStack<char> stack(200);
    std::map<const char, const unsigned int> priority =
    { {'(', 0}, {')', 1},
    {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3} };
    std::map<const char, const unsigned int> *pr_ptr = &priority;

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
        if (isOperation(pr_ptr, inp[i])) {
            if ((priority[inp[i]] == 0) ||
                (priority[inp[i]] > priority[stack.get()])
                || (stack.isEmpty())) {
                stack.push(inp[i]);
            } else {
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
