#pragma once

#include "Event.h"


namespace meng
{

	class MENG_API WindowResized : public Event
	{
	public:
		WindowResized(uint32_t width, uint32_t height):mWidth(width), mHeight(height) {}

		inline uint32_t getWidth() const { return mWidth; }
		inline uint32_t getHeight() const { return mHeight; }

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << "Window was resized to (" << getWidth() << ", " << getHeight() << ')';
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		uint32_t mWidth, mHeight;
	};

	class MENG_API WindowClosed : public Event
	{
	public:
		WindowClosed() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MENG_API AppTick : public Event
	{
	public:
		AppTick() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MENG_API AppUpdated : public Event
	{
	public:
		AppUpdated() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MENG_API AppRendered : public Event
	{
	public:
		AppRendered() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}