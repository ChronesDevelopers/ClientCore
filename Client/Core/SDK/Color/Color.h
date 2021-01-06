#pragma once

#include "../../Cmr/Cmr.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

namespace Core
{
	namespace SDK
	{
		class Color
		{
			Public union
			{
				Public struct
				{
					Public float R, G, B, A;
				};
			};
			Public bool ShouldDelete = true;
			Public Color();
			Public Color(float, float, float);
			Public Color(float, float, float, float);
			Public Color(float, float, float, float, bool);
			Public inline bool Is(Color);
			Public inline bool IsNot(Color);
			Public inline bool operator == (Color);
			Public inline bool operator != (Color);
			Public static Color FromRGB(byte, byte, byte);
			Public static Color FromRGBA(byte, byte, byte, byte);
			Public static Color FromARGB(byte, byte, byte, byte);
		};
	}
}