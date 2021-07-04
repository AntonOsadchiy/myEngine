#include "mengpch.h"
#include "Log.h"

namespace meng
{

	LoggerPtr Log::msCoreLogger;
	LoggerPtr Log::msClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		setupCoreLogger();
		setupClientLogger();
	}

	meng::Log::Log()
	{
	}

	meng::Log::~Log()
	{
	}

}

