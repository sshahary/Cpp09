#include "PmergeMe.hpp"

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

        sorter.measureTime(&PmergeMe::sortVector, sorter.vectorData, sorter.vectorTime);
        sorter.measureTime(&PmergeMe::sortDeque, sorter.dequeData, sorter.dequeTime);

        sorter.displayAfter();

        std::cout << "Time to process a range of " << sorter.vectorData.size() << " elements with std::vector: "
                  << sorter.getVectorTime() << " us" << std::endl;

        std::cout << "Time to process a range of " << sorter.dequeData.size() << " elements with std::deque: "
                  << sorter.getDequeTime() << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
