#include "IsWin64.h"

BOOL IsCurrentProcess64bit()
{
#if defined(_WIN64)
    return TRUE;
#else
    return FALSE;
#endif
}

BOOL IsCurrentProcessWow64()
{
    BOOL bIsWow64 = FALSE;
    typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
    LPFN_ISWOW64PROCESS fnIsWow64Process;

    fnIsWow64Process = (LPFN_ISWOW64PROCESS)
                                       GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
    if (!fnIsWow64Process)
        return FALSE;

    return fnIsWow64Process(GetCurrentProcess(), &bIsWow64) && bIsWow64;
}

BOOL Is64BitWindows()
{
    if (IsCurrentProcess64bit())
        return TRUE;

    return IsCurrentProcessWow64();
}