#include <vector>
#include <raylib.h>
#include <random>

class Visualizer {
    public:
        Visualizer();

        void RandomizeArray();
        void Resize(int size);

        bool shouldSorting(bool shuoldSort) const;
        bool isSorted() const;
        int getArraySize() const;
        float getArrayNumber(int index) const;

    private:
        std::vector<float> array;
        int arraySize;
        bool sorting;
};
