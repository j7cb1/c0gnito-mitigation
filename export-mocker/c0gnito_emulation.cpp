//
// Simple export emulation of the c0gnito.cc authentication library 
// 
// Usage:
// - compile as x64 dynamic linked library
// - re-name the binary to c0gnito.dll
// - replace the current c0gnito.dll with this one 
// - run the process and you should have full access, just enter a random password
//
//
// discord: randyshanks#1337
//

#include <Windows.h>
#include <iostream>

BOOL APIENTRY DllMain(HMODULE h_module, DWORD ul_reason_for_call, LPVOID lp_reserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        printf("> c0gnito emulation module is active\n");

        return TRUE;
    }
}

extern "C" __declspec(dllexport) const char* GetHardwareID()
{
    printf("\t> GetHardwareID -> called\tret \"c0gnito\" \n");

    return "c0gnito";
}

extern "C" __declspec(dllexport) const char* GetReturnMessage()
{
    printf("\t> GetReturnMessage -> called\tret \"c0gnito\" \n");

    return "c0gnito";
}

extern "C" __declspec(dllexport) bool Authenticate(const char* license, const char* hwid = "")
{
    printf("\t> Authenticate -> called : license=%s, hwid=%s\tret true\n", license, hwid);

    return true;
}

extern "C" __declspec(dllexport) int GetExpirationTime()
{
    printf("\t> GetExpirationTime -> called\n");

    return 1337;
}

extern "C" __declspec(dllexport) int GetLevel()
{
    printf("\t> GetLevel -> called\n");

    // Initialize a return value
    int ret = 0;

    // Prompt the user to enter a level
    printf("\t> Enter level: ");

    // Get the users input
    std::cin >> ret;

    return ret;
}

extern "C" __declspec(dllexport) bool Initialize(const char* public_key)
{
    printf("\t> Initialize -> called : public_key=%s\tret true\n", public_key);

    return true;
}