#pragma once

#ifdef RMX_PLATFORM_WINDOWS
	#ifdef RMX_BUILD_DLL
		#define RMX_API __declspec(dllexport)
	#else
		#define RMX_API __declspec(dllimport)
	#endif
#else
	#error RMX only supports Windows!
#endif