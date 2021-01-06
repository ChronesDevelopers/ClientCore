#pragma once

#include "../Player/Player.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

namespace Core
{
	namespace SDK
	{
		ref class Game sealed
		{
			Internal Ptr BaseAddress;
			Internal property Player* LocalPlayerPtr
			{
				Player* get();
			}
			Internal property bool LocalPlayerExists
			{
				bool get();
			}
			Internal property Player& LocalPlayer
			{
				Player& get();
			}
		};
	}
}