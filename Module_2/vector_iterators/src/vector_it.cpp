#include <iostream>
#include <vector>
#include "vector_it.hpp"

// Implement the functions here
std::vector<int> ReadVector () {
    int input = 0;
    std::vector<int> inputarr;

    while(std::cin >> input) {
        inputarr.push_back(input);
    }

    return inputarr;
}

void PrintSum1 (const std::vector<int>& inputarr) {
    int sum1 = 0;
    for (std::vector<int>::const_iterator it = inputarr.begin(); it+1 != inputarr.end(); it++){
        sum1 = *it + *(it+1);
        std::cout << sum1 << " ";
    }
    std::cout << std::endl;
    return ;
}

void PrintSum2 (const std::vector<int>& inputarr) {
    int sum2 = 0;
    int i,j;
    for (i=0, j=inputarr.size()-1; i<j; ++i,--j){
        sum2 = inputarr[i] + inputarr[j];
        std::cout << sum2 << " ";
    }
    std::cout << std::endl;
    return ;
}