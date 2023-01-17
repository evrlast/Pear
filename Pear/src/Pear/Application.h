#pragma once

#include "Window.h"
#include "Pear/LayerStack.h"
#include "Pear/Events/Event.h"
#include "Pear/Events/ApplicationEvent.h"



namespace Pear {

	class PEAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}


