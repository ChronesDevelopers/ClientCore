#pragma once

#include "../Cmr/Cmr.h"

namespace Core
{
	ref class Loader sealed
	{
		Public static void Load();
		Private static void LoadProcessInfo();
		Private static void LoadHooks();
	};
}