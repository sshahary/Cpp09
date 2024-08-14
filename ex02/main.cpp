#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers...>" << std::endl;
        return 1;
    }
    PmergeMe sorter;
    sorter.parseInput(argc, argv);
    sorter.displayBefore();
    sorter.getDequeTime();
    sorter.displayAfter();
    
    return 0;

}