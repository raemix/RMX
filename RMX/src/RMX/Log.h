#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"



namespace RMX {

	class RMX_API Log
	{
	public:
		

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};

}

//Core Logger
#define RMX_CORE_TRACE(...)   ::RMX::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RMX_CORE_INFO(...)    ::RMX::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RMX_CORE_WARN(...)    ::RMX::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RMX_CORE_ERROR(...)   ::RMX::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RMX_CORE_FATAL(...)   ::RMX::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Logger
#define RMX_TRACE(...)        ::RMX::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RMX_INFO(...)         ::RMX::Log::GetClientLogger()->info(__VA_ARGS__)
#define RMX_WARN(...)         ::RMX::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RMX_ERROR(...)        ::RMX::Log::GetClientLogger()->error(__VA_ARGS__)
#define RMX_FATAL(...)        ::RMX::Log::GetClientLogger()->fatal(__VA_ARGS__)



