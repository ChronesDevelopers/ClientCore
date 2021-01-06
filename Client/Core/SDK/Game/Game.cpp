#include "Game.h"

#include "../Player/Player.h"
#include "../Color/Colors.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

Core::SDK::Player* Core::SDK::Game::LocalPlayerPtr::get()
{
	return nullptr;
}
bool Core::SDK::Game::LocalPlayerExists::get()
{
	Color c = Colors::Cyan;
	return LocalPlayerPtr != nullptr;
}
Core::SDK::Player& Core::SDK::Game::LocalPlayer::get()
{
	if (LocalPlayerPtr == nullptr)
		throw Cmr::NullRefException("Core.SDK.Game.LocalPlayer.get returned null.", "Player", "LocalPlayer.get");
	else
		return AsRef(LocalPlayerPtr);
}