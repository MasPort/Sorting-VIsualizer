#include <vector>
#include <random>

class Visualizer {
    public:
        Visualizer();

        void RandomizeArray();
        bool isSorting() const;
        int getArraySize() const;
        float getArrayNumber(int index) const;

    private:
        std::vector<float> array;
        int arraySize;
        bool sorting;
};
