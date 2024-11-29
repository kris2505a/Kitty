workspace "Kitty"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kitty"
    location "Kitty"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("binInt/" .. outputdir .. "/%{prj.name}")
    pchheader "PrecompiledHeaders.h"
    pchsource "Kitty/src/PrecompiledHeaders.cpp"


    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "KITTY_PLATFORM_WIN",
            "KITTY_BUILD_DLL"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/SandBox")    
        }


    filter "configurations:Debug"
        defines "KITTY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KITTY_RELEASE"
        optimize "on"
    
    filter "configurations:Dist"
        defines "KITTY_DIST"
        optimize "On"

project "SandBox"
        location "SandBox"
        kind "ConsoleApp"
        language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("binInt/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "Kitty/vendor/spdlog/include",
        "Kitty/src"
    }

    links{
        "Kitty"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "KITTY_PLATFORM_WIN",
            
        }


    filter "configurations:Debug"
        defines "KITTY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KITTY_RELEASE"
        optimize "on"
    
    filter "configurations:Dist"
        defines "KITTY_DIST"
        optimize "On"

