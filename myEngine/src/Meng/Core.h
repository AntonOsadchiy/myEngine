#pragma once

#ifdef MENG_PLATFORM_WINDOWS
	#ifdef MENG_BUID_DLL
		#define MENG_API __declspec(dllexport) //only a Windiws thing, therefore platform specific
	#else
		#define MENG_API __declspec(dllimport) //only a Windiws thing, therefore platform specific
	#endif
#else
	#error  my engine only supports Windows for now
#endif
