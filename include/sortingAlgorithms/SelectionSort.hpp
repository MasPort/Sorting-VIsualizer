#pragma once
#include "../SortAlgorithm.hpp"

class SelectionSort : public SortAlgorithm {
    public:
        SelectionSort(std::vector<float> &array, int &arraySize, std::set<int> &comparingIndices) :
            SortAlgorithm(array, arraySize, comparingIndices), startIndex(0) {}

        void sortStep();
        void Reset();

    private:
        int startIndex;
};
