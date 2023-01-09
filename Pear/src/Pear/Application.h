#pragma once

#include "Core.h"

namespace Pear {

	class PEAR_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	Application* CreateApplication();
}


