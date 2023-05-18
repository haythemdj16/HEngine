#pragma once

#include <iostream>
#include <vector>
#include <windows.h>

#include "Layer.h"

namespace HEngine
{
	class Application
	{
	public:
		Application(int width, int height);
		Application(const Application&) = delete;
		Application operator= (const Application&) = delete;
		~Application();

		static Application& Get();

		void PushLayer(Layer* layer);

		void Resize(int width, int height);

		void Run();

		int GetViewportWidth() const { return ViewportWidth; }
		int GetViewpoerHeight() const { return ViewportHeight; }

	private:
		void Init();
		void Clean();
		bool ProccessMessages();

	private:
		int ViewportWidth = 0;
		int ViewportHeight = 0;

		bool Running = false;

		std::vector<Layer*> LayerStack;

		HINSTANCE hInstance;
		HWND hwnd;
	};
}