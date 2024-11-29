#pragma once

#ifdef KITTY_PLATFORM_WIN

extern Kitty::Application* Kitty::createApplication();


int main(int argc, char** argv) {
	Kitty::Log::init();
	KITTY_CORE_TRACE("Starting Kitty Engine"); 
	auto app = Kitty::createApplication();
	app->run();
	delete app;
}


#endif
