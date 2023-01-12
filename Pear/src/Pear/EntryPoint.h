#pragma once

#ifdef PR_PLATFORM_WINDOWS

extern Pear::Application* Pear::CreateApplication();

int main(int argc, char** argv)
{
	Pear::Log::Init();
	PR_CORE_WARN("Initialized Log!");
	PR_INFO("Hello!");

	auto app = Pear::CreateApplication();

	app->Run();

	delete app;
}

#endif // PR_PLATFORM_WINDOWS
