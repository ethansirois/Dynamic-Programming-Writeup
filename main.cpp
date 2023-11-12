#include "canPartition.h"
#include "canPartition.cpp"
#include <vector>

#include <iostream>
#include <chrono>



std::vector<int> createVector(int size) {
    std::vector<int> to_return(size);
    for (int i = 0; i < size; ++i) {
        if (i >= size / 2) {
            to_return.at(i) = i;
        } else {
            to_return.at(i) = i + 1;
        }
    }
    return to_return;
}


void time_rec(std::vector<int>& ns) {
    std::cout << "[";
    for (int n : ns) {
        std::vector<int> vect = createVector(n);
        auto start{std::chrono::steady_clock::now()};
        auto end{std::chrono::steady_clock::now()};
        start = std::chrono::steady_clock::now();
        bool res = canPartition(vect, true);
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds_ss{end - start};
        std::cout << elapsed_seconds_ss.count() << ", ";
    }
    std::cout << "]" << std::endl;
}

void time_dp(std::vector<int>& ns) {
    std::cout << "[";
    for (int n : ns) {
        std::vector<int> vect = createVector(n);
        auto start{std::chrono::steady_clock::now()};
        auto end{std::chrono::steady_clock::now()};
        start = std::chrono::steady_clock::now();
        bool res = canPartition(vect, false);
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds_ss{end - start};
        std::cout << elapsed_seconds_ss.count() << ", ";
    }
    std::cout << "]" << std::endl;
}





int main() {
    std::vector<int> ns = {10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98, 106}; // [5, 10, 15, 20, 25, 30]
    
    time_rec(ns);
    std::cout << "now dp times:" << std::endl;
    time_dp(ns);
    return 0;
}