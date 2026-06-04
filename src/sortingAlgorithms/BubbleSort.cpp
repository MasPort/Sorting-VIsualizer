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
