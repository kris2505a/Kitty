#pragma once
#include "Event.h"
#include <sstream>

namespace Kitty {
	class KITTY_API windowReSizeEvent : public Event {
	
	private:
		unsigned int width, height;
		
	public:
		windowReSizeEvent(unsigned int wd, unsigned int ht)
			: width{wd}, height{ht} {}
		inline unsigned int getWidth() const { return this->width; }
		inline unsigned int getHeight() const { return this->height; }
		
		std::string toString() const override {
			std::stringstream ss;
			ss << "windowReSizeEvent: " << this->width << ", " << this->height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(windowResize)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};

	class KITTY_API windowCloseEvent : public Event {
	public:
		windowCloseEvent() = default;
		EVENT_CLASS_TYPE(windowClose)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};

	class appTicketEvent : public Event {
	public:
		appTicketEvent() = default;
		EVENT_CLASS_TYPE(appTick)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};

	class appUpdateEvent : public Event {
	public:
		appUpdateEvent() = default;
		EVENT_CLASS_TYPE(appUpdate)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};

	class appRenderEvent : public Event {
	public:
		appRenderEvent() = default;
		EVENT_CLASS_TYPE(appRender)
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};
}