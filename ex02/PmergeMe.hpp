#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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

    void parseInput(int argc, char* argv[]);
};

#endif

