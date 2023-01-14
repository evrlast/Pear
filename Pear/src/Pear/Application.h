#pragma once

#include "Core.h"
#include "prpch.h"
#include "Events/Event.h"

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


