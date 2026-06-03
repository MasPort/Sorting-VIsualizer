#include <vector>
#include <random>

class Visualizer {
    public:
        Visualizer();

        void RandomizeArray();
        void Resize(int size);

        bool isSorting() const;
        bool isSorted() const;
        int getArraySize() const;
        float getArrayNumber(int index) const;

    private:
        std::vector<float> array;
        int arraySize;
        bool sorting;
};
