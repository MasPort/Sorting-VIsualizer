#include "../../include/sortingAlgorithms/BubbleSort.hpp"
#include <iostream>

void BubbleSort::sortStep() {
    comparingIndices.clear();
    comparingIndices.emplace(currentIndex);
    comparingIndices.emplace(currentIndex + 1);

    if (array.at(currentIndex) > array.at(currentIndex + 1)) {
        int nextIndex = currentIndex + 1;
        Swap(currentIndex, nextIndex);
    }

    ++currentIndex;

    if (currentIndex == lastIndex) {
        currentIndex = 0;
        --lastIndex;
    }
}

void BubbleSort::Reset(int arraySize) {
    this->arraySize = arraySize;
    lastIndex = this->arraySize - 1;
    currentIndex = 0;
}
