/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:58:30 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/15 15:58:31 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <positive integers...>" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe sorter;
		sorter.parseInput(argc, argv);

		sorter.displayBefore();

		double vectorTime;
		sorter.measureTime(&PmergeMe::sortVector, sorter.getVectorData(), vectorTime);
		sorter.setVectorTime(vectorTime);

		double dequeTime;
		sorter.measureTime(&PmergeMe::sortDeque, sorter.getDequeData(), dequeTime);
		sorter.setDequeTime(dequeTime);

		sorter.displayAfter();

		std::cout << "Time to process a range of " << sorter.getVectorData().size() << " elements with std::vector: "
				  << sorter.getVectorTime() << " us" << std::endl;

		std::cout << "Time to process a range of " << sorter.getDequeData().size() << " elements with std::deque: "
				  << sorter.getDequeTime() << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
