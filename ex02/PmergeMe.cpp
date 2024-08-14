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

double PmergeMe::getVectorTime() const
{
    return vectorTime;
}

double PmergeMe::getDequeTime() const
{
    return dequeTime;
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