#include "Cmr.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

Core::Cmr::Vector2::Vector2() { }
Core::Cmr::Vector2::Vector2(float x, float y)
{
    X = x;
    Y = y;
}
Core::Cmr::Vector3::Vector3() { }
Core::Cmr::Vector3::Vector3(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}
Core::Cmr::Vector4::Vector4() { }
Core::Cmr::Vector4::Vector4(float x, float y, float z, float w)
{
    X = x;
    Y = y;
    Z = z;
    W = w;
}
Core::Cmr::Point2D::Point2D() { }
Core::Cmr::Point2D::Point2D(float x, float y)
{
    X = x;
    Y = y;
}
Core::Cmr::Point3D::Point3D() { }
Core::Cmr::Point3D::Point3D(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}
Core::Cmr::Point4D::Point4D() { }
Core::Cmr::Point4D::Point4D(float x, float y, float z, float w)
{
    X = x;
    Y = y;
    Z = z;
    W = w;
}
Core::Cmr::Size2D::Size2D() { }
Core::Cmr::Size2D::Size2D(float width, float height)
{
    Width = width;
    Height = height;
}
Core::Cmr::Rectangle Core::Cmr::Size2D::ToRectangle()
{
    return Rectangle(0, 0, Width, Height);
}
Core::Cmr::Size3D::Size3D() { }
Core::Cmr::Size3D::Size3D(float width, float height, float depth)
{
    Width = width;
    Height = height;
    Depth = depth;
}
Core::Cmr::Point::Point() { }
Core::Cmr::Point::Point(float x, float y) : Point2D(x, y) { }
Core::Cmr::Border::Border() { }
Core::Cmr::Border::Border(float b)
{
    Left = b;
    Top = b;
    Right = b;
    Bottom = b;
}
Core::Cmr::Border::Border(float horizontal, float vertical)
{
    Left = horizontal;
    Top = vertical;
    Right = horizontal;
    Bottom = vertical;
}
Core::Cmr::Border::Border(float left, float top, float right, float bottom)
{
    Left = left;
    Top = top;
    Right = right;
    Bottom = bottom;
}
const Core::Cmr::Border Core::Cmr::Border::Empty = Core::Cmr::Border(0);
Core::Cmr::Rectangle::Rectangle() { }
Core::Cmr::Rectangle::Rectangle(float width, float height)
{
    X = 0;
    Y = 0;
    Width = width;
    Height = height;
}
Core::Cmr::Rectangle::Rectangle(float x, float y, float width, float height) 
{ 
    X = x;
    Y = y;
    Width = width;
    Height = height;
}
Core::Cmr::Size2D Core::Cmr::Rectangle::GetSize()
{
    return Size2D(Width, Height);
}
Core::Cmr::NullRefException::NullRefException() : std::exception() { }
Core::Cmr::NullRefException::NullRefException(string Message) : Exception(Message.c_str())
{
    this->Message = Message;
}
Core::Cmr::NullRefException::NullRefException(string Message, string RefType) : Exception(Message.c_str())
{
    this->Message = Message;
    this->RefType = RefType;
}
Core::Cmr::NullRefException::NullRefException(string Message, string RefType, string AtFunction) : Exception(Message.c_str())
{
    this->Message = Message;
    this->RefType = RefType;
    this->AtFunction = AtFunction;
}
bool Core::Cmr::IsInRangeByte(Byte x, Byte min, Byte max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeSByte(SByte x, SByte min, SByte max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeInt8(Int8 x, Int8 min, Int8 max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeInt16(Int16 x, Int16 min, Int16 max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeInt32(Int32 x, Int32 min, Int32 max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeInt64(Int64 x, Int64 min, Int64 max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeUInt8(UInt8 x, UInt8 min, UInt8 max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeUInt16(UInt16 x, UInt16 min, UInt16 max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeUInt32(UInt32 x, UInt32 min, UInt32 max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeUInt64(UInt64 x, UInt64 min, UInt64 max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeSingle(Single x, Single min, Single max) { return x >= min && x <= max; }
bool Core::Cmr::IsInRangeDouble(Double x, Double min, Double max) { return x >= min && x <= max; }
byte Core::Cmr::CharToByteHex(char value)
{
    unsigned char ret = 0;
    if (value >= '0' && value <= '9') 
    {
        ret = value - '0';
        return ret;
    }
    if (value >= 'A' && value <= 'F')
    {
        ret = value - 'A' + 0xA;
        return ret;
    }
    std::string exception_message = "";
    exception_message += "Could not convert ";
    exception_message += value;
    exception_message += " into a byte.";
    throw new std::exception(exception_message.c_str());
}
Vector<byte> Core::Cmr::StringToBytesHex(string value)
{
    std::vector<byte> ret = { };
    for (char& c : value)
    {
        if (c != ' ')
        {
            ret.push_back(Core::Cmr::CharToByteHex(c));
        }
    }
    return ret;
}