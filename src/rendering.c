#include "rendering.h"
#include <Windows.h>

HBRUSH bgBrush;
HWND window;

void initRendering(HWND hwnd) {
    bgBrush = CreateSolidBrush(RGB(0, 100, 95));
    window = hwnd;
}

void clear(HDC hdc) {
    RECT rect;
    GetClientRect(window, &rect);
    FillRect(hdc, &rect, bgBrush);
    
}

void render(HDC hdc, int fps) {
    clear(hdc);

    char fpsString[8];
    wsprintf(fpsString, "FPS: %d", fps);

    TextOut(hdc, 100, 100, fpsString, strlen(fpsString));
}