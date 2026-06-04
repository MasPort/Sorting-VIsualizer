#include "../include/ToggleButton.hpp"
#include <iostream>
#include <raylib.h>

ToggleButton::ToggleButton(Rectangle buttonRect, Color color, int lineThickness, const char *textActivated, const char *textDeactivated) :
    buttonRect(buttonRect), color(color), textActivated(textActivated), textDeactivated(textDeactivated), lineThickness(lineThickness), isActive(false) {}

void ToggleButton::Draw() const {
    int padding = 10;
    DrawRectangleLinesEx(buttonRect, lineThickness, isHovered(GetMousePosition()) ? ColorLerp(color, RED, 0.30f) : color);
    DrawText(isActivated() ? textActivated : textDeactivated, buttonRect.x + padding, buttonRect.y + padding, buttonRect.height - padding, color);
}

void ToggleButton::Toggle() {
    isActive = !isActive;
}

void ToggleButton::Resize(Rectangle newRect) {
    buttonRect = newRect;
}

bool ToggleButton::isHovered(Vector2 mousePos) const {
    return CheckCollisionPointRec(mousePos, buttonRect);
}

bool ToggleButton::isActivated() const {
    return isActive;
}

void ToggleButton::onPress(Vector2 mousePos) {
    if (isHovered(mousePos)) Toggle();
}

void ToggleButton::setState(bool state) {
    isActive = state;
}
