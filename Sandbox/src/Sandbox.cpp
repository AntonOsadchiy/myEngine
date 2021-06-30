#include <iostream>
#include <Meng.h>

class Sandbox :public meng::Application
{
public:

	Sandbox()
	{

	}

	~Sandbox()
	{

	}

private:

};

meng::Application* meng::CreateApplication()
{
	return new Sandbox();
}
