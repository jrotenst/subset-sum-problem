#pragma once
#include <vector>

template <class T>
class SubsetToSum {

public:
    T sum;
    std::vector<T> subset;

    SubsetToSum(T sum, std::vector<T> subset) : sum(sum), subset(subset) {}
};