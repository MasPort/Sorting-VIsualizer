#include "../include/Visualizer.hpp"

Visualizer::Visualizer() : arraySize(0), sorting(false) {}

void Visualizer::RandomizeArray() {
    std::mt19937 generator;
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    for (int i = 0; i < arraySize; ++i)
        array.push_back(dist(generator));
}

bool Visualizer::isSorting() const { return sorting; }

int Visualizer::getArraySize() const { return arraySize; }

float Visualizer::getArrayNumber(int index) const { return array.at(index); }
