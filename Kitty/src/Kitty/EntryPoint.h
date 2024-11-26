#pragma once

#ifdef KITTY_PLATFORM_WIN

extern Kitty::Application* Kitty::createApplication();


int main(int argc, char** argv) {
	Kitty::Log::init();
	KITTY_CORE_ERROR("Kitty Error");
	KITTY_TRACE("Kitty App LOG");
	auto app = Kitty::createApplication();
	app->run();
	delete app;
}


#endif
