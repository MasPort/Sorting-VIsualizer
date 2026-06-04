#include "../../include/sortingAlgorithms/InsertionSort.hpp"

void InsertionSort::sortStep() {
    comparingIndices.clear();
    if (previous >= 0 && array.at(previous) > array.at(previous + 1)) {
        comparingIndices.emplace(previous + 1);
        comparingIndices.emplace(previous);

        int next = previous + 1;
        Swap(next, previous);

        --previous;
    } else {
        ++startIndex;
        previous = startIndex - 1;
    }
}

void InsertionSort::Reset() {
    startIndex = 1;
    previous = 0;
}
