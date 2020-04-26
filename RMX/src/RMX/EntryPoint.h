#pragma once

#ifdef RMX_PLATFORM_WINDOWS

extern RMX::Application* RMX::CreateApplication();

int main(int argc, char** argv)
{

	auto app = RMX::CreateApplication();
	app->Run();
	delete app;

}

#endif