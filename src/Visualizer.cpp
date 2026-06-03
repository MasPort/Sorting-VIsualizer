#include "../include/Visualizer.hpp"

Visualizer::Visualizer() : arraySize(100), sorting(false) {}

void Visualizer::RandomizeArray() {
    std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    array.clear();
    for (int i = 0; i < arraySize; ++i)
        array.push_back(dist(generator));
}

void Visualizer::Resize(int size) {
    arraySize = size;
    RandomizeArray();
}

bool Visualizer::shouldSorting(bool shouldSort) const { return sorting; }

bool Visualizer::isSorted() const {
    for (int i = 1; i < arraySize; ++i) 
        if (array.at(i - 1) > array.at(i)) 
            return false;
    return true;
}

int Visualizer::getArraySize() const { return arraySize; }

float Visualizer::getArrayNumber(int index) const { return array.at(index); }
