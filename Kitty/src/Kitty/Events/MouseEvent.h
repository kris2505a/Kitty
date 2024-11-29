#pragma once
#include "Event.h"

namespace Kitty {
	class KITTY_API mouseMovedEvent : public Event {
	
	private:
		float mouseX, mouseY;
	
	public:
		mouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) {}
		inline float getX() const { return this->mouseX; }
		inline float getY() const { return this->mouseY; }
		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(mouseMoved)
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput)
	};

	class KITTY_API mouseScrolledEvent : public Event {
	
	private:
		float xOffset, yOffset;
	
	public:
		mouseScrolledEvent(float xOff, float yOff)
			: xOffset(xOff), yOffset(yOff) {}
		inline float getXOffset() const { return this->xOffset; }
		inline float getYOffset() const { return this->yOffset; }
		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
			return ss.str();
		}
		EVENT_CLASS_TYPE(mouseScrolled)
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput)

	};

	class KITTY_API mouseButtonEvent : public Event {
	protected:
		int button;

	public:
		mouseButtonEvent(int but)
			: button(but) {}
		inline int getMouseButton() const { return this->button; }
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput)
	};

	class KITTY_API mouseButtonPressedEvent : public mouseButtonEvent{
	public:
		mouseButtonPressedEvent(int button)
			: mouseButtonEvent(button) {}
		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(mouseButtonPressed)
	};

	class KITTY_API mouseButtonReleasedEvent : public mouseButtonEvent {
	public:
		mouseButtonReleasedEvent(int button)
			: mouseButtonEvent(button) {}
		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(mouseButtonReleased)

	};
}