#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

using LoggerPtr = std::shared_ptr<spdlog::logger>;

namespace meng
{	
	class MENG_API Log
	{
	public:
		Log();
		~Log();

		static void Init();

		inline static LoggerPtr& pCoreLogger() { return msCoreLogger; }
		inline static LoggerPtr& pClientLogger() { return msClientLogger; }

	private:
		static LoggerPtr msCoreLogger;
		static LoggerPtr msClientLogger;

		inline static void setupCoreLogger()
		{
			msCoreLogger = spdlog::stdout_color_mt("Core");
			msCoreLogger->set_level(spdlog::level::trace);
		}

		inline static void setupClientLogger()
		{
			msClientLogger = spdlog::stdout_color_mt("Client");
			msClientLogger->set_level(spdlog::level::trace);
		}

	};
}

#ifndef MENG_DIST //for debug and release builds
	#define MENG_CORE_ERROR(...)	::meng::Log::pCoreLogger()->error(__VA_ARGS__)
	#define MENG_CORE_WARN(...)		::meng::Log::pCoreLogger()->warn(__VA_ARGS__)
	#define MENG_CORE_INFO(...)		::meng::Log::pCoreLogger()->info(__VA_ARGS__)
	#define MENG_CORE_TRACE(...)	::meng::Log::pCoreLogger()->trace(__VA_ARGS__)

	#define MENG_ERROR(...)			::meng::Log::pClientLogger()->error(__VA_ARGS__)
	#define MENG_WARN(...)			::meng::Log::pClientLogger()->warn(__VA_ARGS__)
	#define MENG_INFO(...)			::meng::Log::pClientLogger()->info(__VA_ARGS__)
	#define MENG_TRACE(...)			::meng::Log::pClientLogger()->trace(__VA_ARGS__)
#else//for distribution builds
	#define MENG_CORE_ERROR
	#define MENG_CORE_WARN
	#define MENG_CORE_INFO
	#define MENG_CORE_TRACE
	#define MENG_ERROR
	#define MENG_WARN
	#define MENG_INFO
	#define MENG_TRACE
#endif