#include "../include/Button.hpp"

Button::Button(Rectangle buttonRect, Color color, int lineThickness, const char *text) :
    buttonRect(buttonRect), color(color), lineThickness(lineThickness), text(text) {}

void Button::Draw() const {
    int padding = 10;
    DrawRectangleLinesEx(buttonRect, lineThickness, isHovered(GetMousePosition()) ? ColorLerp(color, RED, 0.30f) : color);
    DrawText(text, buttonRect.x + padding, buttonRect.y + padding, buttonRect.height - padding, color);
}

void Button::Resize(Rectangle newRect) {
    buttonRect = newRect;
}

bool Button::isHovered(Vector2 mousePos) const {
    return CheckCollisionPointRec(mousePos, buttonRect);
}

bool Button::isPressed(Vector2 mousePos) {
    return isHovered(mousePos);
}
