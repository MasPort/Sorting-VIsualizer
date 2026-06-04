#include "../SortAlgorithm.hpp"

class BubbleSort : public SortAlgorithm {
    public:
        BubbleSort(std::vector<float> &array, int &arraySize, std::set<int> &comparingIndices) :
            SortAlgorithm(array, arraySize, comparingIndices), lastIndex(arraySize - 1), currentIndex(0) {}
        void sortStep();
        void Reset(int arraySize);

    private:
        int lastIndex;
        int currentIndex;
};
