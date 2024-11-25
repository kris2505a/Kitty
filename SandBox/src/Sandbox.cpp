#include <Kitty.h>

class SandBox : public Kitty::Application {

public:
	SandBox() = default;
	~SandBox() = default;
};

Kitty::Application* Kitty::createApplication() {
	return new SandBox();
}