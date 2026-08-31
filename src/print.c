#include <Windows.h>
#include "print.h"


void print(char buffer[]) { // my implementation of printing function using windows api
    DWORD written = 0;
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), buffer, strlen(buffer), &written, NULL);
}