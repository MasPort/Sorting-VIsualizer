#pragma once
#include <algorithm>
#include <set>
#include <vector>

class SortAlgorithm {
    public:
        SortAlgorithm(std::vector<float> &array, int &arraySize, std::set<int> &comparingIndices) : array(array), arraySize(arraySize), comparingIndices(comparingIndices) {}

        virtual void sortStep() = 0;
        virtual void Reset() = 0;

        void Swap(int &index1, int &index2) {
            std::iter_swap(array.begin() + index1, array.begin() + index2);
        }

        std::vector<float> &array;
        int &arraySize;
        std::set<int> &comparingIndices;
};
