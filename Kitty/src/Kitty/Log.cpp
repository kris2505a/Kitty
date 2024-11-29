#include "PrecompiledHeaders.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Kitty {
	std::shared_ptr <spdlog::logger> Log::coreLog;
	std::shared_ptr <spdlog::logger> Log::clientLog;

	void Log::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		coreLog = spdlog::stdout_color_mt("KITTY");
		coreLog->set_level(spdlog::level::trace);

		clientLog = spdlog::stdout_color_mt("APP");
		clientLog->set_level(spdlog::level::trace);
	}
}