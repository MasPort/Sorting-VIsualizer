#include <raylib.h>

class Slider {
    public:
        Slider(float x, float y, float width, float height, Color color, int lineThicknes, Vector2 range, int startValue);
        Slider(Rectangle rect, Color color, int lineThicknes, Vector2 range, int startValue);

        void Draw();
        void Resize(Rectangle newRect);
        void onSliding(Vector2 mousePos);

    private:
        Rectangle RECT;
        Rectangle handleBox;
        Color color;
        Vector2 range;
        int lineThickness;

        int value;
        bool sliding;

        float getValuePercentage();
        void setValueWithPercentage(double percentage);
        bool isHovered(Vector2 mousePos);
};
