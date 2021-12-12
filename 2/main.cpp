#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto integers = randomIntegers();
    std::cout << "Initial: " << integers << "\n";

    // TODO: make the sequence a bitonic sequence
    std::vector<int> bitonic = integers;
    int half = (bitonic.size() / 2);
    std::sort(bitonic.begin(), bitonic.begin() + half);
    std::sort(bitonic.begin() + half, bitonic.end());
    std::reverse(bitonic.begin() + half, bitonic.end());
    std::cout << "Bitonic: " << bitonic << "\n";
}