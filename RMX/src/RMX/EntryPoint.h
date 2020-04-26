#pragma once

#ifdef RMX_PLATFORM_WINDOWS

extern RMX::Application* RMX::CreateApplication();

int main(int argc, char** argv)
{

	RMX::Log::Init();
	RMX_CORE_WARN("Initialized Log!");
	RMX_TRACE("Initialized APP Log!");


	auto app = RMX::CreateApplication();
	app->Run();
	delete app;

}

#endif