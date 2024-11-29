#include "PrecompiledHeaders.h"
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

		KITTY_TRACE("Kitty Engine Running");
		while (true);
	}
}