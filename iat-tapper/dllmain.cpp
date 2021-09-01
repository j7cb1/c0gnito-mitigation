//
// Import detouring of the c0gnito.cc authentication library 
// 
// Usage:
// - compile as x64 dynamic linked library
// - Inject this image into what ever process uses c0gnito.cc authentication
//
//
// discord: randyshanks#1337
//

#include <Windows.h>
#include <vector>
#include "detours.hpp"
#include "exports.hpp"

auto SubRoutine() -> void
{
    void* module_base // Get the base address of the c0gnito module
        = GetModuleHandleA("c0gnito.dll");

    // Check if the module base address is valid
    if (!module_base)
    {
        printf("> invalid module base address\n");
        return;
    }

    // Log the module base address
    printf("> c0gnito.dll\t0x%p\n", module_base);
    
    // Create a vector of the exports we need to hook
    std::vector<std::pair<void*, const char*>> queue =
    {
        {exports::GetLevel, "GetLevel"},
        {exports::Authenticate, "Authenticate"},
        {exports::Initialize, "Initialize"},
        {exports::GetExpirationTime, "GetExpirationTime"},
        {exports::GetReturnMessage, "GetReturnMessage"},
        {exports::GetHardwareID, "GetHardwareID"},
    };

    // Traverse the queue vector
    for (const auto& task : queue)
    {
        void* export_address // Get the address to the export
            = GetProcAddress(reinterpret_cast<HMODULE>(module_base), task.second);

        // Check that the export address is valid
        if (!export_address) continue;
              
        printf("> c0gnito detouring\t%s\t\t%p\t->\t%p\n", task.second, export_address, task.first);

        // Detour the export address
        detours::Detour(export_address, task.first);            
    }

    printf("> c0gnito.dll hijack complete...\n");

    return;
}

BOOL APIENTRY DllMain(HMODULE h_module, DWORD ul_reason_for_call, LPVOID lp_reserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        printf("\n> c0gnito emulator\n");

        SubRoutine();
    }

    return TRUE;
}