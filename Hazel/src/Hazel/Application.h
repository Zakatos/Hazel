#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/ApplicationEvent.h"


namespace Hazel 
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* overlay);

		inline static Application& GetApplication() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	//To be defined in a client
	Application* CreateApplication();
}
