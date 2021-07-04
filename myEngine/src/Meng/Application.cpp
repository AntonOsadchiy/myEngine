#include "mengpch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace meng
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	

	void Application::Run()
	{
		WindowResized e(1280, 720);
		MENG_TRACE(e);
		while (true)
		{

		}
	}
}