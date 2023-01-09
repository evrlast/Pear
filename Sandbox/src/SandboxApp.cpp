#include <Pear.h>

class Sandbox : public Pear::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Pear::Application* Pear::CreateApplication()
{
	return new Sandbox();
}