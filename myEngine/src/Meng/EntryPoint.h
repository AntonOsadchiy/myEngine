#pragma once


#ifdef MENG_PLATFORM_WINDOWS

extern meng::Application* meng::CreateApplication();

int main(int arhc, char** argv)
{
	auto app = meng::CreateApplication();
	app->Run();
	delete app;
}

#endif