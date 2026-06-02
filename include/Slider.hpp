#include <raylib.h>

class Slider {
    public:
        Slider(float x, float y, float width, float height, Color color, int lineThicknes, Vector2 range, int startValue);
        Slider(Rectangle rect, Color color, int lineThicknes, Vector2 range, int startValue);

        void Draw();
        void Update(int &result);

    private:
        Rectangle RECT;
        Rectangle slideBox;
        Color color;
        Vector2 range;
        int lineThickness;

        int value;

        float getValuePercentage();
        bool isHovered();
};
