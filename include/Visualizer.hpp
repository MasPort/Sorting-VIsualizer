#include <vector>
#include <raylib.h>
#include <random>
#include <set>

#include "./sortingAlgorithms/BubbleSort.hpp"

class Visualizer {
    public:
        Visualizer();

        void RandomizeArray();
        void Resize(int size);
        void SortStep();

        bool shouldSorting(bool shuoldSort) const;
        bool isSorted() const;
        int getArraySize() const;
        float getArrayNumber(int index) const;
        bool isComparing(int index) const;

    private:
        std::vector<float> array;
        int arraySize;
        bool sorting;
        std::set<int> comparingIndices;

        SortAlgorithm *sortAlgorithm;
};
