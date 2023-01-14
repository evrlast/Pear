#include "prpch.h"
#include "Application.h"

#include "Pear/Events/ApplicationEvent.h"
#include "Pear/Log.h"

namespace Pear {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			PR_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			PR_TRACE(e);
		}


		while (true);
	}

}