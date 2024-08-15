/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:13:54 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/15 15:13:58 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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