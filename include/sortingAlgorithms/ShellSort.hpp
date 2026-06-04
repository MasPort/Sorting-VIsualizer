#pragma once
#include "../SortAlgorithm.hpp"

class ShellSort : public SortAlgorithm {
    public:
        ShellSort(std::vector<float> &array, int &arraySize, std::set<int> &comparingIndices) :
            SortAlgorithm(array, arraySize, comparingIndices), gap(arraySize / 2), startIndex(gap), previous(gap) {}

        void sortStep();
        void Reset();

    private:
        int gap;
        int startIndex;
        int previous;
};
