#pragma once

#ifdef KITTY_PLATFORM_WIN
	#ifdef KITTY_BUILD_DLL
		#define KITTY_API __declspec(dllexport)
	#else
		#define KITTY_API __declspec(dllimport)
	#endif
#else
	#error Invalid Platform!
#endif