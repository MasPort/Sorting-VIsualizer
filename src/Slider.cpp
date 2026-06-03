#include "../include/Slider.hpp"
#include <iostream>
#include <raylib.h>

Slider::Slider(float x, float y, float width, float height, Color color, int lineThicknes, Vector2 range, int startValue) :
    RECT({ x, y, width, height }), color(color), range(range), lineThickness(lineThicknes), value(startValue) {}

Slider::Slider(Rectangle rect, Color color, int lineThicknes, Vector2 range, int startValue) : 
    RECT(rect), color(color), lineThickness(lineThicknes), range(range), value(startValue) {}

void Slider::Draw() {
    float handleWidth = lineThickness * 10;
    handleBox = Rectangle{RECT.x + getValuePercentage() * (RECT.width - handleWidth), RECT.y, handleWidth, RECT.height};

    // *|*--------||------*|*
    DrawLine(RECT.x, RECT.y, RECT.x, RECT.y + RECT.height, color);
    DrawLineEx({RECT.x, RECT.y}, {RECT.x, RECT.y + RECT.height}, lineThickness, color);
    DrawLineEx({RECT.x + RECT.width, RECT.y}, {RECT.x + RECT.width, RECT.y + RECT.height}, lineThickness, color);

    // |*---------||------*|
    float middlePoint = RECT.y + RECT.height / 2;
    DrawLineEx({RECT.x, middlePoint}, {RECT.x + RECT.width, middlePoint}, lineThickness, color);

    // |---------*||*------|
    DrawRectanglePro(handleBox, {0.0f, 0.0f} , 0.0f, isHovered(GetMousePosition()) ? ColorLerp(color, RED, 0.30f) : color);
}

void Slider::Resize(Rectangle newRect) {
    RECT = newRect;
}

void Slider::onSliding(Vector2 mousePos) {
    if (isHovered(mousePos)) sliding = true;
    if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) sliding = false;

    if (sliding) {
        float mouseX = mousePos.x;
        if (mouseX < RECT.x) mouseX = RECT.x;
        else if (mouseX > RECT.x + RECT.width) mouseX = RECT.x + RECT.width;

        setValueWithPercentage((mouseX - RECT.x)/RECT.width);
    }
}

float Slider::getValuePercentage() {
    return (value - range.x)/(range.y - range.x);
}

bool Slider::isHovered(Vector2 mousePos) {
    return CheckCollisionPointRec(mousePos, handleBox);
}

void Slider::setValueWithPercentage(double percentage) {
    value = percentage * (range.y - range.x) + range.x;
    std::cout << "Value: " << value << std::endl;
}
