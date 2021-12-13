#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

bool getCarTagged(Tag<Car> tag) {
    return tag.isTagged();
}

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<Tag<Car>> taggedCars;
    for (Car i : cars) {
        if (i.price() < 10000 || i.vin().at(0) <= 'F') {
            Tag<Car> carIsTagged = Tag<Car>(true, i);
            taggedCars.push_back(carIsTagged);
        }
        else {
            Tag<Car> carIsTagged = Tag<Car>(false, i);
            taggedCars.push_back(carIsTagged);
        }
    }
    // TODO: populate 'taggedCars' with elements of type Tag<Car> where the tag is set to true
    //  only if the price < 10,000 or if the vin starts with a letter in A...F

    // TODO: arrange `taggedCars` so that the elements tagged `true` are at the beginning
    //  and `false` elements are at the ened
    std::partition(std::begin(taggedCars), std::end(taggedCars), getCarTagged);

    std::cout << "Tagged Cars: " << taggedCars << "\n";
}