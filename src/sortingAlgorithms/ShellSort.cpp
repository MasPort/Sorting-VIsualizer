#include "../../include/sortingAlgorithms/ShellSort.hpp"

void ShellSort::sortStep() {
    comparingIndices.clear();

    if (previous >= gap && array.at(previous - gap) > array.at(previous)) {
        comparingIndices.emplace(previous - gap);
        comparingIndices.emplace(previous);

        int next = previous - gap;
        Swap(next, previous);

        previous = previous - gap;
    } else {
        ++startIndex;
        previous = startIndex;
    }

    if (startIndex == arraySize) {
        gap = gap / 2;
        startIndex = gap;
        previous = gap;
    }
}

void ShellSort::Reset() {
    gap = arraySize / 2;
    startIndex = gap;
    previous = gap;
}
