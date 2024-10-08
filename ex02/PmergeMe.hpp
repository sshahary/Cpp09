/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:58:44 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/15 15:58:51 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <sys/time.h>
#include <algorithm>

class PmergeMe
{
	private:
	std::vector<int> vectorData;
	std::deque<int> dequeData;
	double vectorTime;
	double dequeTime;

	public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	std::vector<int>& getVectorData();
	std::deque<int>& getDequeData();
	void parseInput(int argc, char* argv[]);
	void sortVector(std::vector<int>& data);
	void sortDeque(std::deque<int>& data);
	void displayBefore() const;
	void displayAfter() const;
	double getVectorTime() const;
	double getDequeTime() const;
	void setVectorTime(double time);
	void setDequeTime(double time);

	void mergeInsertSort(std::vector<int>& data);
	void mergeInsertSort(std::deque<int>& data);
	void measureTime(void (PmergeMe::*sortFunc)(std::vector<int>&), std::vector<int>& data, double& time);
	void measureTime(void (PmergeMe::*sortFunc)(std::deque<int>&), std::deque<int>& data, double& time);


};

#endif

