#pragma once

#include "Event.h"

namespace meng
{
	class MENG_API MouseMoved : public Event
	{
	public:
		MouseMoved(float x, float y) : mX(x), mY(y) {}

		inline float getX() const { return mX; }
		inline float getY() const { return mY; }

		virtual std::string toString() const override 
		{
			std::stringstream ss;
			ss << "Mouse moved at (" << getX() << ", " << getY() << ')';
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float mX;
		float mY;
	};


	class MENG_API MouseScrolled : public Event
	{
	public:
		MouseScrolled(float xOffset, float yOffset) : mXOffset(xOffset), mYOffset(yOffset) {}

		inline float getXOffset() const { return mXOffset; }
		inline float getYOffset() const { return mXOffset; }

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << "Mouse was scrolled at (" << getXOffset() << ", " << getYOffset() << ')';
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float mXOffset;
		float mYOffset;
	};

	class MENG_API MouseButtonEvent :public Event
	{
	public:
		inline int32_t getButton() const { return mButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)
	protected:
		MouseButtonEvent(int32_t button) : mButton(button) {}

		int32_t mButton;
	};

	class MENG_API MouseButtonPressed : public MouseButtonEvent
	{
	public :
		MouseButtonPressed(int32_t button, int32_t pressedCount = 0) :MouseButtonEvent(button), mPressedCount(pressedCount) {}

		inline int32_t getPressedCount() const { return mPressedCount; }

		virtual std::string toString() const 
		{
			std::stringstream ss;
			ss << "Mouse button " << getButton() << " was released (" << getPressedCount() << "times)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	private:
		int32_t mPressedCount;
	};

	class MENG_API MouseButtonReleased : public MouseButtonEvent
	{
	public:
		MouseButtonReleased(int32_t button) :MouseButtonEvent(button) {}

		virtual std::string toString() const
		{
			std::stringstream ss;
			ss << "Mouse button "<< getButton() <<" was released ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
