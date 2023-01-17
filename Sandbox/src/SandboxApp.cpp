#include <Pear.h>

class ExampleLayer : public Pear::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}

	void OnUpdate() override
	{
		PR_INFO("ExampleLayer::Update");
	}


	void OnEvent(Pear::Event& event) override
	{
		PR_TRACE("{0}", event);
	}
	
};

class Sandbox : public Pear::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};


Pear::Application* Pear::CreateApplication()
{
	return new Sandbox();
}