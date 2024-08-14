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

    void sortVector(std::vector<int>& data);
    void sortDeque(std::deque<int>& data);

    double getVectorTime() const;
    double getDequeTime() const;


    void parseInput(int argc, char* argv[]);
};

#endif

