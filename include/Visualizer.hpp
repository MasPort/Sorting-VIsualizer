#include <string>
#include <vector>
#include <raylib.h>
#include <set>

#include "SortAlgorithm.hpp"

class Visualizer {
    public:
        std::vector<std::string> sortAlgPrettyNames;

        Visualizer();

        void RandomizeArray();
        void Resize(int size);
        void SortStep();
        void SetAlgorithm(int index);

        bool shouldSorting(bool shuoldSort) const;
        bool isSorted() const;
        int getArraySize() const;
        float getArrayNumber(int index) const;
        std::set<int> getComparingIndices() const;
        bool isComparing(int index) const;

    private:
        std::vector<float> array;
        int arraySize;
        bool sorting;

        std::set<int> comparingIndices;
        std::vector<SortAlgorithm*> sortingAlgorithms;
        SortAlgorithm *sortAlgorithm;
        
        int sortAlgIndex;
};
