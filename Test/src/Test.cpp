#include "HEngine.h"

class MainLayer : public HEngine::Layer
{
public:
	MainLayer()
	{

	}
	~MainLayer()
	{

	}

	void OnUpdate(float dt)
	{
		std::cout << dt << "\n";
	}
};

HEngine::Application* CreateApplication()
{
	HEngine::Application* app = new HEngine::Application(720, 480);
	app->PushLayer(new MainLayer());
	return app;
}