#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN& other) : stack(other.stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        stack = other.stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperation(char op, int a, int b) const
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: Division by zero.");
            return a / b;
        default:
            throw std::runtime_error("Error: Invalid operator.");
    }
}

int RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.length() == 1 && isOperator(token[0]))
        {
            // Handle operator
            if (stack.size() < 2)
                throw std::runtime_error("Error: Invalid expression.");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = applyOperation(token[0], a, b);
            stack.push(result);
        }
        else if (isdigit(token[0]))
        {
            // Handle number
            int num = token[0] - '0';
            stack.push(num);
        }
        else
            throw std::runtime_error("Error: Invalid token.");
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression.");
    return stack.top();
}
