  // Copyright 2021 Sozinov Kirill
#include <iostream>
#include "postfix.h"

int main() {
    std::string input = "2 + 6 * 3 / (4 - 2)";
    std::cout << "Infix expr: " << input << std::endl;
    std::cout << "Postfix expr: " << infix2postfix(input) << std::endl;

    std::string inf = "2 + 2";
    std::string postf = infix2postfix(inf);
    std::cout << postf;
}
