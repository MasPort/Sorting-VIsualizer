#include "../../include/sortingAlgorithms/SelectionSort.hpp"
#include <iostream>

void SelectionSort::sortStep() {
    int minIndex = startIndex;
    for (int i = startIndex; i < arraySize; ++i) {
        if (array.at(i) < array.at(minIndex))
            minIndex = i;
    }

    comparingIndices.clear();
    comparingIndices.emplace(startIndex);
    comparingIndices.emplace(minIndex);
    Swap(startIndex, minIndex);
    ++startIndex;
}

void SelectionSort::Reset() {
    this->array = array;
    this->arraySize = arraySize;
    this->comparingIndices = comparingIndices;
    startIndex = 0;
}

