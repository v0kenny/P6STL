#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool isPrime(int i) {
    if (i == 0 || i == 1) {
        return false;
    }
    else {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                return false;
            }
        }
    }
    return true;
}

bool anyPrime(const std::vector<int>& values) {
    // TODO: return true if any of the values are prime numbers

    auto result = std::any_of(values.begin(), values.end(), isPrime);

    return result;
}