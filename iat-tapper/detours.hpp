#ifndef _DETOURS_HPP_
#define _DETOURS_HPP_

#include <Windows.h>

#if _M_IX86
#define ADRR_OFFSET 0x1
#elif _M_X64
#define ADRR_OFFSET 0x2
#endif



namespace detours
{
	auto Detour(void* address, void* target) -> void
	{
		#if _M_IX86
		unsigned char jmp[7] = {
			0xb8, 0x0, 0x0, 0x0, 0x0,
			0xFF, 0xE0
		};
		#elif _M_X64
		unsigned char jmp[12] =
		{
				0x48, 0xb8, 
				0x0,
				0x0,
				0x0,
				0x0,
				0x0,
				0x0,
				0x0,
				0x0,
				0xff, 0xe0 
		};
		#endif

		DWORD old_protection = 0;

		// Setup the jmp to our target addr
		memcpy(jmp + ADRR_OFFSET, &target, sizeof(target));

		// Change memory protection
		VirtualProtect(address, sizeof(jmp),
			PAGE_READWRITE, &old_protection);

		// Write the jmp to our target to address of the function
		memcpy(address, jmp, sizeof(jmp));

		VirtualProtect(address, sizeof(jmp),
			old_protection, &old_protection);
	}
}

#endif // !_DETOURS_HPP_