#pragma once


#ifdef MENG_PLATFORM_WINDOWS

extern meng::Application* meng::CreateApplication();

int main(int arhc, char** argv)
{
	meng::Log::Init();
	MENG_CORE_WARN("Initialized");
	MENG_INFO("initialized");

	auto app = meng::CreateApplication();
	app->Run();
	delete app;
}

#endif