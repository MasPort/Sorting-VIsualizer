#include <raylib.h>

#include "../include/Window.hpp"

int main() {
    const unsigned int WIDTH = 800;
    const unsigned int HEIGHT = 800;
    const char *TITLE = "Sorting Visualizer";
    const float VISUALIZATION_PERCENTAGE = 0.80f;

    Window window(WIDTH, HEIGHT, TITLE, VISUALIZATION_PERCENTAGE);

    while (!WindowShouldClose()) {
        BeginDrawing();

        window.Draw();

        if (IsWindowResized()) window.Resize();

        EndDrawing();

        ClearBackground(BLACK);
    }

    CloseWindow();

    return 0;
}
