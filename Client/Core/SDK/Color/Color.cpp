#include "Color.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

Core::SDK::Color::Color() { }
Core::SDK::Color::Color(float r, float g, float b)
{
    This.R = r;
    This.G = g;
    This.B = b;
}
Core::SDK::Color::Color(float r, float g, float b, float a)
{
    This.R = r;
    This.G = g;
    This.B = b;
    This.A = a;
}
Core::SDK::Color::Color(float r, float g, float b, float a, bool ShouldDelete)
{
    This.R = r;
    This.G = g;
    This.B = b;
    This.A = a;
    This.ShouldDelete = ShouldDelete;
}
bool Core::SDK::Color::Is(Color other)
{
    return This.R == other.R && This.G == other.G && This.B == other.B && This.A == other.A;
}
bool Core::SDK::Color::IsNot(Color other)
{
    return This.R != other.R || This.G != other.G || This.B != other.B || This.A != other.A;
}
bool Core::SDK::Color::operator==(Color other)
{
    return Is(other);
}
bool Core::SDK::Color::operator!=(Color other)
{
    return IsNot(other);
}
Core::SDK::Color Core::SDK::Color::FromRGB(byte r, byte g, byte b)
{
    return Color(r / 255.0f, g / 255.0f, b / 255.0f);
}
Core::SDK::Color Core::SDK::Color::FromRGBA(byte r, byte g, byte b, byte a)
{
    return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}
Core::SDK::Color Core::SDK::Color::FromARGB(byte a, byte r, byte g, byte b)
{
    return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}