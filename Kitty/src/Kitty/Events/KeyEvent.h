#pragma once
#include "Event.h"

#include <sstream>

namespace Kitty {
	class KITTY_API keyEvent : public Event {
		
	protected:
		int keyCode;
		keyEvent(int keyC) : keyCode{ keyC } {}

	public:
		inline int getKeyCode() const { return this->keyCode; }
	};


	class KITTY_API keyPressedEvent : public keyEvent {
	
	private:
		int repeatedCount;
	public:
		keyPressedEvent(int keyC, int repeatedC)
			: keyEvent(keyC), repeatedCount {repeatedC} {}
		inline int getRepeatCount() const { return this->repeatedCount; }
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " {" << repeatedCount << " repeats}";
			return ss.str();
		}
		EVENT_CLASS_TYPE(keyPressed)
	};

	class KITTY_API keyReleasedEvent : public keyEvent {
	public:
		keyReleasedEvent(int keyC)
			: keyEvent(keyC){}
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(keyReleased)

	};

}