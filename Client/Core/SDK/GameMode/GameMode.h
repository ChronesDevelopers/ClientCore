#pragma once

#include "../../Cmr/Cmr.h"
#include "../Player/Player.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

namespace Core
{
	namespace SDK
	{
		class GameMode
		{
		public:
			Player* Player; //0x0008

			virtual void Destructor();
			virtual void StartDestroyBlock(Vector3*, UChar, bool);
			virtual void DestroyBlock(Vector3*, UChar);
			virtual void ContinueDestroyBlock(Vector3*, UChar, bool);
			virtual void StopDestroyBlock(Vector3*);
			virtual void StartBuildBlock(Vector3*, UChar);
			virtual void BuildBlock(Vector3*, UChar);
			virtual void ContinueBuildBlock(Vector3*, UChar);
			virtual void StopBuildBlock(void);
			virtual void Tick(void);
			virtual float GetPickRange();
			virtual void UseItem();
			virtual void UseItemOn();
			virtual void Interact(Actor*, Vector3*);
			virtual void Attack(Actor*);
			virtual void ReleaseUsingItem();
		};
	}
}