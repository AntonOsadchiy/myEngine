#pragma once
#include "../Core.h"
#include "Event.h"

namespace meng
{

	class MENG_API KeyboardEvent:public Event
	{
	public:
		inline int32_t getKeycode() const { return mKeycode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyboardEvent(int32_t keycode) : mKeycode(keycode) {}

		int32_t mKeycode;
	};


	class MENG_API KeyPressed : public KeyboardEvent
	{
	public:
		KeyPressed(int32_t keycode, int32_t repeatedCount) : KeyboardEvent(keycode), mRepeatedCount(repeatedCount) {}

		inline int32_t getRepeatedCount() const { return mRepeatedCount; }

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << "Key pressed" << getKeycode() << " (" << getRepeatedCount() << "repeats)";
			return ss.str();
		} 

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int32_t mRepeatedCount;
	};

	class MENG_API KeyReleased : public KeyboardEvent
	{
	public:
		KeyReleased(int32_t keycode):KeyboardEvent(keycode) {}

		virtual std::string toString() const override 
		{
			std::stringstream ss;
			ss << "Key released" << getKeycode();
			return ss.str();
		}

	};

}
