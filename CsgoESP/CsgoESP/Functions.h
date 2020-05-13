#pragma once
#include "Includes.h"
#include "Offsets.h"

using namespace std;
HWND hwnd = FindWindowA(NULL, "Counter-Strike: Global Offensive");
DWORD getModuleBaseAddress(DWORD pid, const WCHAR* name)
{

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
    MODULEENTRY32 mEntry;
    mEntry.dwSize = sizeof(MODULEENTRY32);
    do
    {
        if (!wcscmp(mEntry.szModule, name))
        {
            CloseHandle(snapshot);
            return (DWORD)mEntry.modBaseAddr;
        }
    } while (Module32Next(snapshot, &mEntry));


}

template <typename T>
T readMem(DWORD address)
{
    T buffer;
    ReadProcessMemory(process, (LPVOID)address, &buffer, sizeof(buffer), 0);
    return buffer;
}


template <typename T>
void writeMem(DWORD address, T value)
{
    WriteProcessMemory(process, (LPVOID)address, &value, sizeof(value), 0);
}
