#pragma once

#ifdef KITTY_PLATFORM_WIN

extern Kitty::Application* Kitty::createApplication();


int main(int argc, char** argv) {
	Kitty::Application* app = Kitty::createApplication();
	app->run();
	delete app;
}


#endif
