workspace "Pear"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pear"

	location "Pear"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputDir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputDir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PR_PLATFORM_WINDOWS",
			"PR_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputDir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "PR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" ..outputDir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputDir.. "/%{prj.name}")

		files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Pear/vendor/spdlog/include",
		"Pear/src"
	}

	links
	{
		"Pear"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "PR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		optimize "On"