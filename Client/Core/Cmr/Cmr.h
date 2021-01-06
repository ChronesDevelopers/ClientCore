#pragma once

#include <list>
#include <vector>
#include <string>

#ifndef CMR_DEFINITIONS

#define CMR_DEFINITIONS

// NULL
#define null 0

// This
#define This (*this)

// References
#define Ref(type, name, ptr) type& name = *(ptr)
#define AsRef(ptr) *(ptr);
#define NewRef(type) *(new type);

// Public, Private, Protected
#define Public public:
#define Private private:
#define Protected protected:
#define Internal internal:

// Pointer Casts
#define c_byte *(Core::Cmr::Byte*)
#define c_sbyte *(Core::Cmr::SByte*)
#define c_ubyte *(Core::Cmr::UByte*)
#define c_char *(Core::Cmr::Char*)
#define c_uchar *(Core::Cmr::UChar*)
#define c_wchar *(Core::Cmr::WChar*)
#define c_int8 *(Core::Cmr::Int8*)
#define c_int16 *(Core::Cmr::Int16*)
#define c_int32 *(Core::Cmr::Int32*)
#define c_int64 *(Core::Cmr::Int64*)
#define c_uint8 *(Core::Cmr::UInt8*)
#define c_uint16 *(Core::Cmr::UInt16*)
#define c_uint32 *(Core::Cmr::UInt32*)
#define c_uint64 *(Core::Cmr::UInt64*)
#define c_single *(Core::Cmr::Single*)
#define c_double *(Core::Cmr::Double*)
#define c_short *(Core::Cmr::Short*)
#define c_int *(Core::Cmr::Int*)
#define c_long *(Core::Cmr::Long*)
#define c_ushort *(Core::Cmr::UShort*)
#define c_uint *(Core::Cmr::UInt*)
#define c_ulong *(Core::Cmr::ULong*)
#define c_float *(Core::Cmr::Float*)
#define c_void *(Core::Cmr::Void*)
#define c_ptr *(Core::Cmr::Ptr*)
#define c_sptr *(Core::Cmr::SPtr*)
#define c_uptr *(Core::Cmr::UPtr*)
#define c_address *(Core::Cmr::Ptr*)

#endif

namespace Core
{
	// Properties
	namespace Cmr
	{
		
	}
	// Types
	namespace Cmr
	{
		namespace Types
		{
			typedef __int8 Int8;
			typedef __int16 Int16;
			typedef __int32 Int32;
			typedef __int32 Int64;
			typedef unsigned __int8 UInt8;
			typedef unsigned __int16 UInt16;
			typedef unsigned __int32 UInt32;
			typedef unsigned __int32 UInt64;

			typedef short Short;
			typedef int Int;
			typedef long long Long;
			typedef unsigned short UShort;
			typedef unsigned int UInt;
			typedef unsigned long long ULong;

			typedef float Single;
			typedef double Double;
			typedef Single Float;

			typedef unsigned char Byte;
			typedef char SByte;
			typedef unsigned char UByte;
			typedef char Char;
			typedef unsigned char UChar;
			typedef wchar_t WChar;

			typedef unsigned long long Ptr;
			typedef signed long long SPtr;
			typedef unsigned long long UPtr;

			typedef Int8 int8;
			typedef Int16 int16;
			typedef Int32 int32;
			typedef Int64 int64;
			typedef UInt8 uint8;
			typedef UInt16 uint16;
			typedef UInt32 uint32;
			typedef UInt64 uint64;

			typedef Byte byte;
			typedef SByte sbyte;
			typedef UByte ubyte;
			typedef UChar uchar;
			typedef WChar wchar;

			typedef void Void;
		}
	}
	// Vectors
	namespace Cmr
	{
		struct Vector2
		{
			Public float X, Y;
			Public Vector2();
			Public Vector2(float, float);
		};
		struct Vector3
		{
			Public float X, Y, Z;
			Public Vector3();
			Public Vector3(float, float, float);
		};
		struct Vector4
		{
			Public float X, Y, Z, W;
			Public Vector4();
			Public Vector4(float, float, float, float);
		};
	}
	// Points, Sizes, Rectangles
	namespace Cmr
	{
		struct Point2D;
		struct Point3D;
		struct Point4D;
		struct Size2D;
		struct Size3D;
		struct Point;
		struct Rectangle;
		struct Point2D
		{
			Public float X, Y;
			Public Point2D();
			Public Point2D(float, float);
		};
		struct Point3D
		{
			Public float X, Y, Z;
			Public Point3D();
			Public Point3D(float, float, float);
		};
		struct Point4D
		{
			Public float X, Y, Z, W;
			Public Point4D();
			Public Point4D(float, float, float, float);
		};
		struct Size2D
		{
			Public float Width, Height;
			Public Size2D();
			Public Size2D(float, float);
			Public Rectangle ToRectangle();
		};
		struct Size3D
		{
			Public float Width, Height, Depth;
			Public Size3D();
			Public Size3D(float, float, float);
		};
		struct Point : public Point2D
		{
			Public Point();
			Public Point(float, float);
		};
		struct Border
		{
			Public float Left, Top, Right, Bottom;
			Public Border();
			Public Border(float);
			Public Border(float, float);
			Public Border(float, float, float, float);
			Public static const Border Empty;
		};
		struct Rectangle
		{
			Public float X, Y, Width, Height;
			Public Rectangle();
			Public Rectangle(float, float);
			Public Rectangle(float, float, float, float);
			Public Size2D GetSize();
		};
	}
	// Exceptions
	namespace Cmr
	{
		class NullRefException : public std::exception
		{
			Public std::string Message;
			Public std::string RefType;
			Public std::string AtFunction;
			Public NullRefException();
			Public NullRefException(std::string Message);
			Public NullRefException(std::string Message, std::string RefType);
			Public NullRefException(std::string Message, std::string RefType, std::string AtFunction);
		};
	}
	// Extended Types
	namespace Cmr
	{
		namespace Types
		{
			namespace ExtendedTypes
			{
				typedef std::string string;
				typedef std::wstring wstring;
				template<typename T>
				using Vector = std::vector<T>;
				template<typename T>
				using List = std::list<T>;
				typedef std::exception Exception;
				typedef Core::Cmr::Vector2 Vector2;
				typedef Core::Cmr::Vector3 Vector3;
				typedef Core::Cmr::Vector4 Vector4;
				typedef Core::Cmr::Point2D Point2D;
				typedef Core::Cmr::Point3D Point3D;
				typedef Core::Cmr::Point4D Point4D;
				typedef Core::Cmr::Size2D Size2D;
				typedef Core::Cmr::Size3D Size3D;
				typedef Core::Cmr::Point Point;
				typedef Core::Cmr::Border Border;
				typedef Core::Cmr::Rectangle Rectangle;
			}
		}
	}
	// Cmr
	namespace Cmr
	{
		using namespace Core::Cmr::Types;
		using namespace Core::Cmr::ExtendedTypes;

		inline bool IsInRangeByte(Byte, Byte, Byte);
		inline bool IsInRangeSByte(SByte, SByte, SByte);
		inline bool IsInRangeInt8(Int8, Int8, Int8);
		inline bool IsInRangeInt16(Int16, Int16, Int16);
		inline bool IsInRangeInt32(Int32, Int32, Int32);
		inline bool IsInRangeInt64(Int64, Int64, Int64);
		inline bool IsInRangeUInt8(UInt8, UInt8, UInt8);
		inline bool IsInRangeUInt16(UInt16, UInt16, UInt16);
		inline bool IsInRangeUInt32(UInt32, UInt32, UInt32);
		inline bool IsInRangeUInt64(UInt64, UInt64, UInt64);
		inline bool IsInRangeSingle(Single, Single, Single);
		inline bool IsInRangeDouble(Double, Double, Double);
		inline byte CharToByteHex(char);
		inline Vector<byte> StringToBytesHex(string);
	}
}