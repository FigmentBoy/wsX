#include "pch.h"
#include <Windows.h>
#include <commdlg.h>
#include "Gui.h"

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