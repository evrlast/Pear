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

#ifdef PR_ENABLE_ASSERTS
	#define PR_ASSERT(x, ...) { if(!(x)) {PR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debigbreak(); } }
	#define PR_CORE_ASSERT(x, ...) { if(!(x)) {PR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debigbreak(); } }
#else
	#define PR_ASSERT(x, ...)
	#define PR_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)