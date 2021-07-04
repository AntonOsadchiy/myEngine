workspace "myEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    ouput_dir = "%{cfg.buidcfg}-%{cfg.system}-%{cfg.architecture}"

project "myEngine"
    location "myEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. ouput_dir .. "/%{prj.name}")
    objdir ("bin-int/" .. ouput_dir .. "/%{prj.name}")

    pchheader "mengpch.h"
    pchsource "myEngine/src/mengpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs 
    {
        "%{prj.name}/src",
        "%{wks.location}/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MENG_BUID_DLL",
            "MENG_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ("{COPY}  %{cfg.buildtarget.relpath} ../bin/" .. ouput_dir .. "/Sandbox") 
        }

    filter "configurations:Debug"
        defines "MENG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MENG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MENG_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/".. ouput_dir .. "/%{prj.name}")
    objdir ("bin-int/".. ouput_dir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{wks.location}/spdlog/include",
        "myEngine/src"
    }

    links
    {
        "myEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MENG_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "MENG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MENG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MENG_DIST"
        optimize "On"