#pragma once

#include "../Core.h"


/*
Events are blocking for now, meaning when an event occurs it must be dealt with immidiately.
There are future plans on implementing event buffering
*/

namespace meng
{

	enum class EventType //faster then dynamic casting
	{
		None = 0,
		WindowClose, WindowResize, WindowGainedFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory //for fast filtering
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)  static EventType getStaticType() { return EventType::##type; }\
								virtual EventType getEventType() const override { return getStaticType(); }\
								virtual const char* getName() const { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class MENG_API Event
	{
	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category) { return getCategoryFlags() & category; }

	protected:
		bool mHandled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunction = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) :mEvent(event) {}

		template<typename T>
		bool dispatch(EventFunction<T> f)
		{
			if (mEvent.getEventType() == T::getStaticType())
			{
				mEvent.mHandled = f(*(T*)&mEvent);
				return true;
			}
			return false;
		}

	private:
		Event& mEvent;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}
}


