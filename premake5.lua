workspace "RMX"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "RMX"
	location "RMX"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"RMX_PLATFORM_WINDOWS",
			"RMX_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %P{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RMX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RMX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RMX_DIST"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"RMX/vendor/spdlog/include",
		"RMX/src"
	}

	links
	{
		"RMX"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"RMX_PLATFORM_WINDOWS",
		}

		
	filter "configurations:Debug"
		defines "RMX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RMX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RMX_DIST"
		optimize "On"
