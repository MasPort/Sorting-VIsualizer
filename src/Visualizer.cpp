#include "../include/Visualizer.hpp"

Visualizer::Visualizer() : arraySize(100), sorting(false) {
    sortingAlgorithms = {
        new BubbleSort(array, arraySize, comparingIndices),
    };

    sortAlgPrettyNames = {
        "Bubble",
    };

    sortAlgIndex = 0;
    sortAlgorithm = sortingAlgorithms.at(sortAlgIndex);
}

void Visualizer::RandomizeArray() {
    std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    if (array.empty())
        for (int i = 0; i < arraySize; ++i)
            array.push_back(dist(generator));
    else 
        for (int i = 0; i < arraySize; ++i) 
            array.at(i) = dist(generator);

    Resize(arraySize);
}

void Visualizer::Resize(int size) {
    arraySize = size;
    comparingIndices.clear();
    sortAlgorithm = sortingAlgorithms.at(sortAlgIndex);
    sortAlgorithm->Reset(arraySize);
}

void Visualizer::SortStep() {
    sortAlgorithm->sortStep();
}

void Visualizer::SetAlgorithm(int index) {
    comparingIndices.clear();
    sortAlgIndex = index;
    sortAlgorithm = sortingAlgorithms.at(sortAlgIndex);
    sortAlgorithm->Reset(arraySize);
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

bool Visualizer::isComparing(int index) const {
    return comparingIndices.count(index) > 0;
}
