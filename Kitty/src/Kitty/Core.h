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


#define BIT(x) (1 << x)


/*
Explanation:
	If engine ( KITTY_PLATFORM_WIN and KITTY_BUILD_DLL)
		__declspec(dllexport)
	Else (KITTY_PLATFORM_WIN) 
		__declspec(dllimport)
*/