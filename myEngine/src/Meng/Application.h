#pragma once
#include "Core.h"

namespace meng
{
	class MENG_API Application
	{
	private:
	public:
		Application();

		virtual ~Application();

		void Run();

	};

	Application* CreateApplication(); // to be defined by client
}
