#include "../include/Window.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <raylib.h>

Window::Window(int width, int height, const char *title, const float visPercent) : width(width), height(height), title(title), visPercent(visPercent)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, title);

    SetTargetFPS(600);

    SetAudioStreamBufferSizeDefault(2048);
    InitAudioDevice();
    audioStream = LoadAudioStream(44100, 16, 1);
    PlayAudioStream(audioStream);
    phase = 0;

    vis = new Visualizer();
    vis->RandomizeArray();

    sizeSlider = new Slider(Rectangle{0, 0, 0, 0}, WHITE, 3, {10, 1000}, 100);
    startSortingButton = new ToggleButton(Rectangle{0, 0, 0, 0}, WHITE, 3, "Stop", "Start");
    randomizeButton = new Button(Rectangle{0, 0, 0, 0}, WHITE, 3, "Randomize");
    algorithmButtons = {};
}

void Window::Draw()
{
    float rectPercent = 1 - visPercent; int lineThickness = 3;
    optionsRect = Rectangle{ rectPercent * width - lineThickness, 0, visPercent * width, rectPercent * height };

    float xPadding = lineThickness + 10; float yPaddingOptions = lineThickness + optionsRect.height / 4; float yPaddingAlgorithm = lineThickness + 10;
    Rectangle sliderRect{optionsRect.x + xPadding, yPaddingOptions, 400, optionsRect.height - yPaddingOptions * 2}; 
    sizeSlider->Resize(sliderRect); 
    sizeSlider->Draw(); 

    int fontSize = 96;
    Rectangle startButtonRect{sliderRect.x + sliderRect.width + xPadding * 2, yPaddingOptions, (float)MeasureText("Start", fontSize/2), (float)fontSize/2};
    Rectangle randomizeButtonRect{sliderRect.x + sliderRect.width + xPadding * 2, yPaddingOptions + startButtonRect.height, (float)MeasureText("Randomize", fontSize/2), (float)fontSize/2};

    randomizeButton->Resize(randomizeButtonRect);
    randomizeButton->Draw();
    startSortingButton->Resize(startButtonRect);
    startSortingButton->Draw();

    algorithmsRect = Rectangle{ 0, 0, rectPercent * width, (float)height };

    int index = 0; fontSize = fontSize / 2;
    for (std::string sortAlg : vis->sortAlgPrettyNames) {
        Rectangle algorithmButtonRect{xPadding, yPaddingAlgorithm + index * (fontSize + yPaddingAlgorithm), algorithmsRect.width - 2 * xPadding, (float)fontSize};

        if (algorithmButtons.size() <= index) 
            algorithmButtons.insert(algorithmButtons.cbegin() + index, new Button(algorithmButtonRect, WHITE, lineThickness, sortAlg.c_str()));

        algorithmButtons.at(index)->Resize(algorithmButtonRect);
        algorithmButtons.at(index)->Draw();

        ++index;
    }

    DrawRectangleLinesEx(optionsRect, lineThickness, WHITE);
    DrawRectangleLinesEx(algorithmsRect, lineThickness, WHITE);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonUp(MOUSE_BUTTON_LEFT)) 
        sizeSlider->onSliding(GetMousePosition());

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        startSortingButton->onPress(GetMousePosition());
        if (randomizeButton->isPressed(GetMousePosition())) vis->RandomizeArray();

        for (int i = 0; i < algorithmButtons.size(); ++i) {
            if (algorithmButtons.at(i)->isPressed(GetMousePosition())) {
                vis->SetAlgorithm(i);
            }
        }
    }
    
    DrawArray(); 
}

void Window::DrawArray() {
    float x = algorithmsRect.width; float y = optionsRect.height;
    float sortWidth = width - algorithmsRect.width; float sortHeight = height - optionsRect.height;

    if (sizeSlider->getValue() != vis->getArraySize())
        vis->Resize(sizeSlider->getValue()); 

    int maxSize = vis->getArraySize();
    float x_step = sortWidth / maxSize;

    if (startSortingButton->isActivated() && !vis->isSorted()) {
        vis->SortStep();

        for (int value : vis->getComparingIndices()) {
            float freq = 2 * std::lerp(0.5f, 1.0f, ((value - 0.0f) / ((float)vis->getArraySize() - 0.0f)) * (470.0f - 0.0f));
            std::cout << freq << std::endl;
            PlayTone(freq, 1.0f);
        }
    }

    for (int i = 0; i < maxSize; ++i) {
        float rectHeight = sortHeight * vis->getArrayNumber(i);
        Color color = vis->isSorted() ? GREEN : vis->isComparing(i) ? RED : WHITE;
        DrawRectanglePro(
                Rectangle{x + (x_step * i), y + (sortHeight - rectHeight), x_step, rectHeight},
                { 0.0f, 0.0f }, 0.0f, color);
    }
}

void Window::PlayTone(float frequency, float duration) {
    if (!IsAudioStreamProcessed(audioStream)) return;

    int sampleRate = 2048;
    int sampleCount = sampleRate * duration;
    short samples[sampleCount];

    for (int i = 0; i < sampleCount; ++i) {
        float envelope = 1.0f;
        int fadeLength = sampleCount / 2;
        if (i < fadeLength)
            envelope = (float)i / fadeLength;
        else if (i > sampleCount - fadeLength)
            envelope = (float)(sampleCount - i) / fadeLength;

        samples[i] = 32000 * envelope * sinf(2 * PI * frequency * (i + phase) / 44100);
    }
    phase += sampleCount;

    UpdateAudioStream(audioStream, samples, sampleCount);
}

void Window::Resize()
{
    width = GetScreenWidth();
    height = GetScreenHeight();
}
