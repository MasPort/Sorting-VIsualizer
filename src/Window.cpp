#include "../include/Window.hpp"
#include <iostream>
#include <raylib.h>

Window::Window(int width, int height, const char *title, const float visPercent) : width(width), height(height), title(title), visPercent(visPercent)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, title);

    SetTargetFPS(60);

    vis = new Visualizer();
    vis->RandomizeArray();
    
    sizeSlider = new Slider(Rectangle{0, 0, 0, 0}, WHITE, 3, {10, 1000}, 100);
    startSorting = new ToggleButton(Rectangle{0, 0, 0, 0}, WHITE, 3, "Stop", "Start");
}

void Window::Draw()
{
    float rectPercent = 1 - visPercent; int lineThickness = 3;
    optionsRect = Rectangle{ rectPercent * width - lineThickness, 0, visPercent * width, rectPercent * height };

    float xPadding = lineThickness + 10; float yPadding = lineThickness + optionsRect.height / 4;
    Rectangle sliderRect{optionsRect.x + xPadding, yPadding, 400, optionsRect.height - yPadding * 2}; 
    sizeSlider->Resize(sliderRect); 
    sizeSlider->Draw(); 

    int fontSize = 96;
    Rectangle startButtonRect{sliderRect.x + sliderRect.width + xPadding * 2, yPadding, (float)MeasureText("Start", fontSize), (float)fontSize};

    startSorting->Resize(startButtonRect);
    startSorting->Draw();

    algorithmsRect = Rectangle{ 0, 0, rectPercent * width, (float)height };

    DrawRectangleLinesEx(optionsRect, lineThickness, WHITE);
    DrawRectangleLinesEx(algorithmsRect, lineThickness, WHITE);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonUp(MOUSE_BUTTON_LEFT)) 
        sizeSlider->onSliding(GetMousePosition());

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        startSorting->onPress(GetMousePosition());
    }
    
    DrawArray(); 
}

void Window::DrawArray() {
    float x = algorithmsRect.width; float y = optionsRect.height;
    float sortWidth = width - algorithmsRect.width; float sortHeight = height - optionsRect.height;

    if (sizeSlider->getValue() != vis->getArraySize()) vis->Resize(sizeSlider->getValue());

    if (true) {
        if (startSorting->isActivated()) vis->RandomizeArray();
        int maxSize = vis->getArraySize();
        float x_step = sortWidth / maxSize;

        for (int i = 0; i < maxSize; ++i) {
            float rectHeight = sortHeight * vis->getArrayNumber(i);
            DrawRectanglePro(
                    Rectangle{x + (x_step * i), y + (sortHeight - rectHeight), x_step, rectHeight},
                    { 0.0f, 0.0f }, 0.0f, vis->isSorted() ? GREEN : WHITE);
        }
    }
}

void Window::Resize()
{
    width = GetScreenWidth();
    height = GetScreenHeight();
}
