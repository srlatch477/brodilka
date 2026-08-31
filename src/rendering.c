#include "rendering.h"
#include <Windows.h>

void render(HDC* hdc) {
    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
    RECT rect = {0, 0, 100, 100};
    FillRect(*hdc, &rect, brush);
}