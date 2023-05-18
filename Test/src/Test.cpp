#include "HEngine.h"

class MainLayer : public HEngine::Layer
{
public:
	MainLayer()
	{
		Width = HEngine::Application::Get().GetViewportWidth();
		Height = HEngine::Application::Get().GetViewportHeight();
		pixels = new uint32_t[Width*Height];

		for(int i = 0; i < Width*Height; i++)
			pixels[i] = 0xff0000;
	}
	~MainLayer()
	{
		delete pixels;
	}

	void OnResize(int width, int height) override
	{
		Width = width;
		Height = height;
		delete pixels;
		pixels = new uint32_t[Width*Height];
	}

	void OnUpdate(float dt) override
	{
		if(HEngine::Event::IsKeyDown(HEngine::KeyCode::ESCAPE))
			HEngine::Application::Get().ShutDown();
	}

	void OnRender() override
	{
		HEngine::Application::Get().DrawPixels(pixels);
	}

private:
	int Width, Height;
	uint32_t* pixels;
};

HEngine::Application* CreateApplication()
{
	HEngine::Application* app = new HEngine::Application(720, 480);
	app->PushLayer(new MainLayer());
	return app;
}