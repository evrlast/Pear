#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Pear {
	
	class PEAR_API Log
	{
	public: 
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	
	private: 
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define PR_CORE_TRACE(...)    ::Pear::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PR_CORE_INFO(...)     ::Pear::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PR_CORE_WARN(...)     ::Pear::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PR_CORE_ERROR(...)    ::Pear::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PR_CORE_FATAL(...)    ::Pear::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Core log macros
#define PR_TRACE(...)		  ::Pear::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PR_INFO(...)		  ::Pear::Log::GetClientLogger()->info(__VA_ARGS__)
#define PR_WARN(...)		  ::Pear::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PR_ERROR(...)		  ::Pear::Log::GetClientLogger()->error(__VA_ARGS__)
#define PR_FATAL(...)		  ::Pear::Log::GetClientLogger()->critical(__VA_ARGS__)
