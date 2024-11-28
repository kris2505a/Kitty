#include "Application.h"
#include "Kitty/Events/Event.h"
#include "Kitty/Events/ApplicationEvent.h"
#include "Kitty/Log.h"
#include <iostream>


namespace Kitty {
	Application::Application() {

	}

	Application:: ~Application() {

	}

	void Application::run() {

		windowReSizeEvent ev(1280, 720);
		KITTY_FATAL(ev);
		while (true);
	}
}