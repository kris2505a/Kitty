#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace Kitty {

	class KITTY_API Log {
	private:
		static std::shared_ptr <spdlog::logger> coreLog;
		static std::shared_ptr <spdlog::logger> clientLog;

	public:
		inline static std::shared_ptr<spdlog::logger>& getCoreLog() { return coreLog; }
		inline static std::shared_ptr<spdlog::logger>& getClientLog() { return clientLog; }
		static void init();
	};
}


#define KITTY_CORE_TRACE(...) ::Kitty::Log::getCoreLog()->trace(__VA_ARGS__)
#define KITTY_CORE_INFO(...) ::Kitty::Log::getCoreLog()->info(__VA_ARGS__)
#define KITTY_CORE_WARN(...) ::Kitty::Log::getCoreLog()->warn(__VA_ARGS__)
#define KITTY_CORE_ERROR(...) ::Kitty::Log::getCoreLog()->error(__VA_ARGS__)
#define KITTY_CORE_FATAL(...) ::Kitty::Log::getCoreLog()->critical(__VA_ARGS__)


#define KITTY_TRACE(...) ::Kitty::Log::getClientLog()->trace(__VA_ARGS__)
#define KITTY_INFO(...) ::Kitty::Log::getClientLog()->info(__VA_ARGS__)
#define KITTY_WARN(...) ::Kitty::Log::getClientLog()->warn(__VA_ARGS__)
#define KITTY_ERROR(...) ::Kitty::Log::getClientLog()->error(__VA_ARGS__)
#define KITTY_FATAL(...) ::Kitty::Log::getClientLog()->critical(__VA_ARGS__)
