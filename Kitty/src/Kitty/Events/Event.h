#pragma once

#include "Kitty/Core.h"
#include <string>
#include <functional>

namespace Kitty {
	enum class eventType {
		none = 0,
		windowClose, windowResize, windowFocus, windowLostfocus, windowMoved,
		appTick, appUpdate, appRender,
		keyPressed, keyReleased,
		mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseScrolled
	};

	enum eventCategory {
		none = 0,
		eventCategoryApplication = BIT(0),
		eventCategoryInput = BIT(1),
		eventCategoryKeyBoard = BIT(2),
		eventCategoryMouse = BIT(3),
		eventCategoryMouseButton = BIT(4)
	};
#define EVENT_CLASS_TYPE(type) static eventType getStaticType(){ return eventType::type; }\
							   virtual eventType getEventType() const override { return getStaticType(); }\
							   virtual const char* getName() const override { return #type; } 


#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; } 

	class KITTY_API Event {
		friend class eventDispatcher;
	public:
		virtual ~Event() = default;
		virtual eventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		inline bool isInCategory(eventCategory category) {
			return getCategoryFlags() & category;
		}
		virtual std::string toString() const { return getName(); }
		bool handled = false;
	};

	class eventDispatcher {
		
	private:
		Event& event;

	public:
		eventDispatcher(Event& ev) : event{ ev } {}
		template <typename T, typename F>
		bool dispatched(const F& func){
			if (this->event.getEventType() == T::getStatictype()) {
				this->event.handled |= func(static_cast<T&>(event));
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator << (std::ostream& ostr, const Event& e) {
		ostr << e.toString();
		return ostr;
	}
}


