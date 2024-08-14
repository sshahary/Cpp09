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