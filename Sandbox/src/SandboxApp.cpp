#include <RMX.h>

class Sandbox : public RMX::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}


};


RMX::Application* RMX::CreateApplication()
{
	return new Sandbox();
}