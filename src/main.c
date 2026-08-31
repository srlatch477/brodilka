#include <Windows.h>
#include "print.h"
#include "rendering.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    LPSTR className = "Brodilka";
    
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
        className,
        "Brodilka",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,
        600,
        NULL, // hmenu goes here
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        print("failed to create window!\n");
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;

    HDC hdc = GetWindowDC(hwnd);

    HICON ico = LoadIcon(NULL, IDI_APPLICATION);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);

        render(&hdc);

        DrawIcon(hdc, 20, 20, ico);

        UpdateWindow(hwnd);

        DispatchMessage(&msg);
    }
    return msg.wParam;
}