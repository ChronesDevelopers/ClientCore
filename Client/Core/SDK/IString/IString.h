#pragma once

#include <string>
#include "../../Cmr/Cmr.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

namespace Core
{
	namespace SDK
	{
		class IString
		{
			public: union
			{
				char InlineText[16];
				char* TextPointer;
			};
			public: UInt64 Length;
			public: UInt64 AllocatedLength;
			public: void SetText(string);
			public: char* GetText();
			public: UInt64 GetLength();
			public: UInt64 GetAllocatedLength();
			public: void Reset();
			public: void Clear();
			public: bool IsEmpty();
			public: bool IsPointer();
			public: IString();
			public: IString(string);
			public: IString(void*, UInt64);
			public: ~IString();
		};
	}
}