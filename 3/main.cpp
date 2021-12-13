#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"
#include <numeric>
int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    // TODO: print the average price and price range
    std::vector<Car> carList = cars;
    std::vector<double> priceCar;

    for (Car i : carList) {
        priceCar.push_back(i.price());
    }
    double averagePriceCar = 0;
    averagePriceCar = std::accumulate(priceCar.begin(), priceCar.end(), 0);
    std::cout << "The average price is: $" << averagePriceCar << "\n";
    double maxPrice = 0;
    maxPrice = *std::max_element(priceCar.begin(), priceCar.end());

    double minPrice = 0;
    minPrice = *std::min_element(priceCar.begin(), priceCar.end());
    double range = 0;

    range = maxPrice - minPrice;

    std::cout << "The range is: $" << range << "\n";
}