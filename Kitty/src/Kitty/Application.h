#pragma once
#include "Core.h"

namespace Kitty {

	class KITTY_API Application {

	public:
		Application();
		virtual ~Application();
		void run();

	};
	Application *createApplication(); //defined in client

}

