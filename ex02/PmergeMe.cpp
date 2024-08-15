/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:58:39 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/15 15:58:40 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmergeme.hpp"

PmergeMe::PmergeMe() : vectorTime(0), dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : vectorData(other.vectorData), dequeData(other.dequeData),
											vectorTime(other.vectorTime), dequeTime(other.dequeTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vectorData = other.vectorData;
		dequeData = other.dequeData;
		vectorTime = other.vectorTime;
		dequeTime = other.dequeTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		int value;
		std::istringstream iss(argv[i]);
		if (!(iss >> value) || value < 0)
		{
			throw std::runtime_error("Error: invalid input");
		}
		vectorData.push_back(value);
		dequeData.push_back(value);
	}
}

void PmergeMe::sortVector(std::vector<int>& data)
{
	mergeInsertSort(data);
}

void PmergeMe::sortDeque(std::deque<int>& data)
{
	mergeInsertSort(data);
}

void PmergeMe::setVectorTime(double time)
{
	vectorTime = time;
}

void PmergeMe::setDequeTime(double time)
{
	dequeTime = time;
}

double PmergeMe::getVectorTime() const
{
	return vectorTime;
}

double PmergeMe::getDequeTime() const
{
	return dequeTime;
}

std::vector<int>& PmergeMe::getVectorData()
{
	return vectorData;
}

std::deque<int>& PmergeMe::getDequeData()
{
	return dequeData;
}

void PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < vectorData.size(); ++i)
	{
		std::cout << vectorData[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < vectorData.size(); ++i)
	{
		std::cout << vectorData[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int>& data)
{
	if (data.size() <= 1)
		return;

	std::vector<int> left(data.begin(), data.begin() + data.size() / 2);
	std::vector<int> right(data.begin() + data.size() / 2, data.end());

	mergeInsertSort(left);
	mergeInsertSort(right);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), data.begin());
}

void PmergeMe::mergeInsertSort(std::deque<int>& data)
{
	if (data.size() <= 1)
	return;

	std::deque<int> left(data.begin(), data.begin() + data.size() / 2);
	std::deque<int> right(data.begin() + data.size() / 2, data.end());

	mergeInsertSort(left);
	mergeInsertSort(right);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), data.begin());
}
void PmergeMe::measureTime(void (PmergeMe::*sortFunc)(std::vector<int>&), std::vector<int>& data, double& time)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	(this->*sortFunc)(data);
	gettimeofday(&end, NULL);
	time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
}

void PmergeMe::measureTime(void (PmergeMe::*sortFunc)(std::deque<int>&), std::deque<int>& data, double& time)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	(this->*sortFunc)(data);
	gettimeofday(&end, NULL);
	time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
}


// void PmergeMe::measureTime(void (PmergeMe::*sortFunc)(std::vector<int>&), std::vector<int>& data, double& time)
// {
//     clock_t start = clock();
//     (this->*sortFunc)(data);
//     clock_t end = clock();
//     time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;  // Convert to microseconds
// }

// void PmergeMe::measureTime(void (PmergeMe::*sortFunc)(std::deque<int>&), std::deque<int>& data, double& time)
// {
//     clock_t start = clock();
//     (this->*sortFunc)(data);
//     clock_t end = clock();
//     time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;  // Convert to microseconds
// }
