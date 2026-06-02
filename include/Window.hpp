#include <raylib.h>
#include "Visualizer.hpp"
#include "Slider.hpp"

class Window {
    public:
        Window(int width, int heigh, const char *title, const float visPercent);

        void Draw();
        void Resize();

    private:
        int width;
        int height;
        const char *title;
        const float visPercent;

        Rectangle optionsRect, algorithmsRect, sortingRect;

        Visualizer *vis;
        Slider *sizeSlider;

        void DrawArray();
};
