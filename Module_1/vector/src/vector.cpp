#include "vector.hpp"

#include <vector>
#include <algorithm>    //std::sort

int GetMin(std::vector<int> v) {
    int small = v[0];
    for (unsigned int i=0; i<v.size(); i++) {
        if (v[i] < small) 
            small = v[i];
    }
    return small;
    // std::sort (v.begin(),v.end(),v);
    // return v[0]; 
}

int GetMax(std::vector<int> v) {
    int large = v[0];
    for (unsigned int i=0; i<v.size(); i++) {
        if (v[i] > large) 
            large = v[i];
    }
    return large; 
}

double GetAvg(std::vector<int> v) {
    double average = 0;
    double sum = 0;

    for (unsigned int i=0; i<v.size(); i++) {
        sum = sum + v[i];
    }

    average = sum / v.size();

    return average; 
}
