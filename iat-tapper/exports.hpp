#ifndef _EXPORTS_HPP_
#define _EXPORTS_HPP_

#include <iostream>

namespace exports
{
	bool Initialize(const char* public_key)
	{
		printf("> c0gnito initialized with public key %s\n", public_key); return true;
	}

	int GetExpirationTime()
	{
		printf("> c0gnito GetExpirationTime called returning 1337\n"); return 1337;
	}

	bool Authenticate(const char* license, const char* hwid = "")
	{
		printf("> c0gnito Authenticate called license %s hwid %s\n", license, hwid); return true;
	}

	const char* GetHardwareID()
	{
		printf("> c0gnito GetHardwareID called returning c0gnito\n"); return "c0gnito";
	}

	const char* GetReturnMessage()
	{
		printf("> c0gnito GetReturnMessage called returning c0gnito\n"); return "c0gnito";
	}

	int GetLevel()
	{
		printf("> c0gnito GetLevel called");

		// Initialize a return value
		int ret = 0;

		// Prompt the user to enter a level
		printf("\tEnter level: ");

		// Get the users input
		std::cin >> ret;

		printf("\n");

		return ret;
	}
}

#endif // !_EXPORTS_HPP_