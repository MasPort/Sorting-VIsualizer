#include <raylib.h>

class Button {
    public:
        Button(Rectangle buttonRect, Color color, int lineThickness, const char *text);

        void Draw() const;
        void Resize(Rectangle newRect);
        void SetText(const char *text);

        bool isPressed(Vector2 mousePos);

    private:
        Rectangle buttonRect;
        Color color;
        const char *text;
        int lineThickness;

        bool isHovered(Vector2 mousePos) const;
};
