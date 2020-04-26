#pragma once

#include "Core.h"

namespace RMX {
	class RMX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();

}