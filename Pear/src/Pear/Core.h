#pragma once

#ifdef PR_PLATFORM_WINDOWS
	#ifdef PR_BUILD_DLL
		#define PEAR_API __declspec(dllexport)
	#else
		#define PEAR_API  __declspec(dllimport)
	#endif
#else
	#error Pear only support Windows!

#endif