#pragma once

#include "../../../Cmr/Cmr.h"

namespace Core
{
	namespace SDK 
	{
		namespace Hooks
		{
			ref class GameMode sealed
			{
				Public static void Install();
				Public static void Uninstall();
			};
		}
	}
}