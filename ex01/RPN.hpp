#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>
#include <iostream>

class RPN
{
    private:
    std::stack<int> stack;

    public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    bool isOperator(char c) const;
    int applyOperation(char op, int a, int b) const;

    int evaluate(const std::string& expression);

};
#endif