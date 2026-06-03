#include <raylib.h>

class ToggleButton {
    public:
        ToggleButton(Rectangle buttonRect, Color color, int lineThickness, const char *textActivated, const char *textDeactivated);

        void Draw() const;
        void Toggle();
        void Resize(Rectangle newRect);

        bool isActivated() const; 
        void onPress(Vector2 mousePos);

    private:
        Rectangle buttonRect;
        Color color;
        const char *textActivated; const char *textDeactivated;
        int lineThickness;

        bool isActive;

        bool isHovered(Vector2 mousePos) const;
};
