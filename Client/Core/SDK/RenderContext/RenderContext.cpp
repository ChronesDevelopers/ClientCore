#include "RenderContext.h"

#include <math.h>

Core::SDK::MinecraftUIRenderContext* Core::SDK::RenderContext::MinecraftRenderContext::get()
{
	return This.rx;
}
void Core::SDK::RenderContext::MinecraftRenderContext::set(Core::SDK::MinecraftUIRenderContext* rx)
{
	This.rx = rx;
}
bool Core::SDK::RenderContext::CanDraw::get()
{
	return rx != nullptr;
}
bool Core::SDK::RenderContext::CanNotDraw::get()
{
	return rx == nullptr;
}
void Core::SDK::RenderContext::DrawRectangle(Rectangle Rect, Border BorderThickness, Color BorderColor)
{
	if (CanNotDraw) return;
}
void Core::SDK::RenderContext::DrawFilledRectangle(Rectangle Rect, Color FillColor, Border BorderThickness = Border::Empty, Color BorderColor = Colors::Transparent)
{
	if (CanNotDraw) return;
}
void Core::SDK::RenderContext::DrawLine(Point From, Point To, float StrokeThickness, Color StrokeColor)
{
	if (CanNotDraw) return;
}
void Core::SDK::RenderContext::DrawText(string Text, Point TextPosition, float Size, Color TextColor)
{
	if (CanNotDraw) return;
}
Core::Cmr::Size2D Core::SDK::RenderContext::GetTextSize(string Text, float Size)
{
	if (CanNotDraw) return Size2D(0, 0);
	throw Exception("Not Implemented");
}
Core::Cmr::Rectangle Core::SDK::RenderContext::BoxRectangle(Rectangle Rect, Rectangle ParentRect)
{
	return Rectangle(ParentRect.X, ParentRect.Y, fminf(Rect.Width, ParentRect.Width), fminf(Rect.Height, ParentRect.Height));
}
///
// Add stuff here

///
Core::Cmr::Rectangle Core::SDK::RenderContext::AlignTopLeft(Rectangle Rect, Rectangle ParentRect)
{
	return AlignLeft(Rect, AlignTop(Rect, ParentRect));
}
Core::Cmr::Rectangle Core::SDK::RenderContext::AlignTopRight(Rectangle Rect, Rectangle ParentRect)
{
	return AlignRight(Rect, AlignTop(Rect, ParentRect));
}
Core::Cmr::Rectangle Core::SDK::RenderContext::AlignBottomLeft(Rectangle Rect, Rectangle ParentRect)
{
	return AlignLeft(Rect, AlignBottom(Rect, ParentRect));
}
Core::Cmr::Rectangle Core::SDK::RenderContext::AlignBottomRight(Rectangle Rect, Rectangle ParentRect)
{
	return AlignRight(Rect, AlignBottom(Rect, ParentRect));
}