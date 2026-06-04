#pragma once
#include "../SortAlgorithm.hpp"

class InsertionSort : public SortAlgorithm {
    public:
        InsertionSort(std::vector<float> &array, int &arraySize, std::set<int> &comparingIndices) :
            SortAlgorithm(array, arraySize, comparingIndices), startIndex(1), previous(0) {}

        void sortStep();
        void Reset();

    private:
        int startIndex;
        int previous;
};
