#include "pch.h"
#include <Windows.h>
#include <commdlg.h>
#include <cstdlib>
#include <cstdio>
#include "Gui.h"
#include "InputBox.h"

void getFileOpenName(bool (*callback)(const char*)) {
    OPENFILENAMEA info;
    ZeroMemory(&info, sizeof info);
    CHAR fileName[MAX_PATH] = "";
    info.lStructSize = sizeof info;
    info.hwndOwner = NULL;
    info.Flags = OFN_EXPLORER | OFN_HIDEREADONLY;
    info.lpstrFile = fileName;
    info.nMaxFile = MAX_PATH;
    info.lpstrDefExt = "xgd";
    if (GetOpenFileNameA(&info)) {
        callback(info.lpstrFile);
    }
}

void getFileSaveName(bool (*callback)(const char*)) {
    OPENFILENAMEA info;
    ZeroMemory(&info, sizeof info);
    CHAR fileName[MAX_PATH] = "";
    info.lStructSize = sizeof info;
    info.hwndOwner = NULL;
    info.Flags = OFN_EXPLORER | OFN_HIDEREADONLY;
    info.lpstrFile = fileName;
    info.nMaxFile = MAX_PATH;
    info.lpstrDefExt = "xgd";
    if (GetSaveFileNameA(&info)) {
        callback(info.lpstrFile);
    }
}

template  <typename T, typename R> 
void inputBoxWrapper(const char* prompt, 
    const char* title, 
    const char* default_input, 
    T(*callback)(R)) {
    const char* out = InputBox((char*)"Change speed", (char*)"wsX", (char*)"1.0");
    char* didWork;
    double num = strtod(out, &didWork);
    if (*didWork)
        printf("invalid number\n");
    else
        callback(num);
}

void getSpeed(void (*callback)(float)) {
    inputBoxWrapper("Change speed", "wsX", "1.0", callback);
}

void getFps(void (*callback)(double)) {
    inputBoxWrapper("Change FPS", "wsX", "60.0", callback);
}