/*
 * Codewars kata
 * Infix to Postfix Converter (52e864d1ffb6ac25db00017f)
 */

#include <iostream>
#include <stack>
#include <string>

int32_t GetOperatorWeight(const char op) {
    switch (op) {
        case '+':
            return 4;
        case '-':
            return 4;
        case '*':
            return 3;
        case '/':
            return 3;
        case '^':
            return 2;
        case '(':
            return 1;
        default:
            return -1;
    }
}

bool IsRightAssociative(const char op) {
    return op == '^';
}

bool CompOperators(const char op1, const char op2) {
    if (IsRightAssociative(op1) || IsRightAssociative(op2)) {
        return GetOperatorWeight(op1) <= GetOperatorWeight(op2);
    } else {
        return GetOperatorWeight(op1) < GetOperatorWeight(op2);
    }
}

std::string to_postfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operators;
    for (const auto c : infix) {
        // std::cout << "Parsing " << c << std::endl;
        if (c >= 0x30 && c <= 0x39) {
            postfix += c;
        } else if (c == ')') {
            while (operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // pop '('
        } else {
            if (!operators.empty() && !CompOperators(c, operators.top())) {
                while (!operators.empty() && GetOperatorWeight(c) >= GetOperatorWeight(operators.top()) &&
                       operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }
            }
            operators.push(c);
        }
        // std::cout << "postfix: " << postfix << std::endl;
        // std::cout << "Operators in stack: " << operators.size() << std::endl;
    }
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main() {
    // std::cout << "2+7*5: " << to_postfix("2+7*5") << std::endl;
    // std::cout << "5+(6-2)*9+3^(7-1): " << to_postfix("5+(6-2)*9+3^(7-1)") << std::endl;
    // std::cout << "(5-4-1)+9/5/2-7/1/7: " << to_postfix("(5-4-1)+9/5/2-7/1/7") << std::endl;
    std::cout << "((((4^4)^4))): " << to_postfix("((((4^4)^4)))") << std::endl;
    return 0;
}
