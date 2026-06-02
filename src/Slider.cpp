#include "../include/Slider.hpp"
#include <raylib.h>

Slider::Slider(float x, float y, float width, float height, Color color, int lineThicknes, Vector2 range, int startValue) :
    RECT({ x, y, width, height }), color(color), range(range), lineThickness(lineThicknes), value(startValue) {}

Slider::Slider(Rectangle rect, Color color, int lineThicknes, Vector2 range, int startValue) : 
    RECT(rect), color(color), lineThickness(lineThicknes), range(range), value(startValue) {}

void Slider::Draw() {
    Rectangle slideBox{RECT.x + getValuePercentage() * RECT.width, RECT.y, (float)lineThickness * 10, RECT.height};

    // *|*--------||------*|*
    DrawLine(RECT.x, RECT.y, RECT.x, RECT.y + RECT.height, color);
    DrawLineEx({RECT.x, RECT.y}, {RECT.x, RECT.y + RECT.height}, lineThickness, color);
    DrawLineEx({RECT.x + RECT.width, RECT.y}, {RECT.x + RECT.width, RECT.y + RECT.height}, lineThickness, color);

    // |*---------||------*|
    float middlePoint = RECT.y + RECT.height / 2;
    DrawLineEx({RECT.x, middlePoint}, {RECT.x + RECT.width, middlePoint}, lineThickness, color);

    // |---------*||*------|
    DrawRectanglePro(slideBox, {0.0f, 0.0f} , 0.0f, isHovered() ? ColorLerp(color, RED, 0.30f) : color);
}

float Slider::getValuePercentage() {
    return static_cast<float>(value)/(range.y - range.x);
}

bool Slider::isHovered() {
    return CheckCollisionPointRec(GetMousePosition(), slideBox);
}
