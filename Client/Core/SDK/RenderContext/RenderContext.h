#pragma once

#include "../../Cmr/Cmr.h"
#include "../MinecraftUIRenderContext/MinecraftUIRenderContext.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

namespace Core
{
	namespace SDK
	{
		ref class RenderContext
		{
			Private MinecraftUIRenderContext* rx;
			Internal property MinecraftUIRenderContext* MinecraftRenderContext
			{
				MinecraftUIRenderContext* get();
				void set(MinecraftUIRenderContext*);
			}
			Internal property bool CanDraw
			{
				bool get();
			}
			Internal property bool CanNotDraw
			{
				bool get();
			}
			Internal void DrawRectangle(Rectangle Rect, Border BorderThickness, Color BorderColor);
			Internal void DrawFilledRectangle(Rectangle Rect, Color FillColor, Border BorderThickness, Color BorderColor);
			Internal void DrawLine(Point From, Point To, float StrokeThickness, Color StrokeColor);
			Internal void DrawText(string Text, Point TextPosition, float Size, Color TextColor);
			Internal Size2D GetTextSize(string Text, float Size);
			Internal void FlushText();
			Internal Rectangle BoxRectangle(Rectangle Rect, Rectangle ParentRect);
			// From here
			Internal Rectangle ClipRectangle(Rectangle Rect, Rectangle ParentRect); // Won't be used
			Internal Rectangle AlignCenter(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignCenter(Rectangle Rect, float Width, float Height);
			Internal Rectangle AlignLeft(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignLeft(Rectangle Rect, float X);
			Internal Rectangle AlignRight(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignRight(Rectangle Rect, float X);
			Internal Rectangle AlignTop(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignTop(Rectangle Rect, float Y);
			Internal Rectangle AlignBottom(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignBottom(Rectangle Rect, float Y);
			// End
			Internal Rectangle AlignTopLeft(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignTopLeft(Rectangle Rect, float X, float Y);
			Internal Rectangle AlignTopRight(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignTopRight(Rectangle Rect, float X, float Y);
			Internal Rectangle AlignBottomLeft(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignBottomLeft(Rectangle Rect, float X, float Y);
			Internal Rectangle AlignBottomRight(Rectangle Rect, Rectangle ParentRect);
			Internal Rectangle AlignBottomRight(Rectangle Rect, float X, float Y);
		};
	}
}