#pragma once

#include "../../Cmr/Cmr.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

namespace Core
{
	namespace SDK
	{
		class Actor
		{
		public:
			char _pad_0008[280]; //0x0008
			Vector2 BodyRot; //0x0120
			char _pad_0128[152]; //0x0128
			bool OnGround; //0x01C0
			char _pad_01C1[95]; //0x01C1
			float StepHeight; //0x0220 | Default = 0.5625
			char _pad_0224[308]; //0x0224
			class MultiPlayerLevel* MultiPlayerLevel; //0x0358
			char _pad_0360[340]; //0x0360
			Vector2 Collision; //0x04B4
			char _pad_04BC[24]; //0x04BC
			Vector3 Velocity; //0x04D4
			char _pad_04E0[880]; //0x04E0

			virtual void _func0();
			virtual void _func1();
			virtual void _func2();
			virtual void _func3();
			virtual void _func4();
			virtual void _func5();
			virtual void _func6();
			virtual void _func7();
			virtual void Reset(void);
			virtual void GetOnDeathExperience(void);
			virtual enum ActorType GetOwnerEntityType(void);
			virtual void Remove(void);
			virtual void SetPos(Vector3 const&);
			virtual void _func13();
			virtual Vector3* GetPos();
			virtual Vector3* GetPosOld();
			virtual Vector3* GetPosExtrapolated(float);
			virtual void _func17();
			virtual Vector3* GetFiringPos(void);
			virtual void SetRot(Vector3 const&);
			virtual void _func20();
			virtual void Move(Vector3 const&);
			virtual void _func22();
			virtual float GetInterpolatedBodyRot(float);
			virtual float GetShadowHeightOffs(void);
			virtual void _func25();
			virtual float GetYawSpeedInDegreesPerSecond(void);
			virtual float GetInterpolatedWalkAnimSpeed(float);
			virtual void _func28();
			virtual void CheckBlockCollisions(void);
			virtual void _func30();
			virtual bool IsFireImmune(void);
			virtual void _func32();
			virtual void _func33();
			virtual void TeleportTo(Vector3 const&, bool, int, int, uint64_t); //Last param is ActorUniqueID
			virtual void TryTeleportTo(Vector3 const&, bool, bool, int, int);
			virtual void ChorusFruitTeleport(Vector3&);
			virtual void LerpTo(Vector3 const&, Vector2 const&, int);
			virtual void LerpMotion(Vector3 const&);
			virtual void _func39();
			virtual void NormalTick(void);
			virtual void BaseTick(void);
			virtual void RideTick(void);
			virtual void PositionRider(Actor&, float);
			virtual float GetRidingHeight(void);
			virtual void StartRiding(Actor&);
			virtual void AddRider(Actor&);
			virtual void FlagRiderToRemove(Actor&);
			virtual void _func48();
			virtual bool Intersects(Vector3 const&, Vector3 const&);
			virtual bool IsFree(Vector3 const&);
			virtual void _func51();
			virtual bool IsInWall(void);
			virtual bool IsInvisible(void);
			virtual bool CanShowNameTag(void);
			virtual void _func55();
			virtual void SetNameTagVisible(bool);
			virtual void _func57();
			virtual __int64 GetNameTagAsHash(void);
			virtual std::string GetFormattedNameTag(void);
			virtual void _func60();
			virtual void SetNameTag(std::string const&);
			virtual void _func62();
			virtual void _func63();
			virtual void _func64();
			virtual bool IsInWater(void);
			virtual bool HasEnteredWater(void);
			virtual bool IsImmersedInWater(void);
			virtual bool IsInWaterOrRain(void);
			virtual bool IsInLava(void);
			virtual bool IsUnderLiquid(class MaterialType);
			virtual bool IsOverWater(void);
			virtual void MakeStuckInBlock(Vector3 const&);
			virtual void _func73();
			virtual void _func74();
			virtual float GetShadowRadius(void);
			virtual Vector3* GetHeadLookVector(float);
			virtual void _func77();
			virtual bool CanSee(Vector3 const&);
			virtual bool CanSee(Actor const&);
			virtual bool IsSkyLit(float);
			virtual float GetBrightness(float);
			virtual void _func82();
			virtual void _func83();
			virtual void OnAboveBubbleColumn(bool);
			virtual void OnInsideBubbleColumn(bool);
			virtual bool IsImmobile(void);
			virtual bool IsSilent(void);
			virtual bool IsPickable();
			virtual void _func89();
			virtual bool IsSleeping(void);
			virtual void _func91();
			virtual void SetSneaking(bool);
			virtual bool IsBlocking(void);
			virtual void _func94();
			virtual bool IsAlive(void);
			virtual bool IsOnFire(void);
			virtual bool IsOnHotBlock(void);
			virtual void _func98();
			virtual bool IsSurfaceMob(void);
			virtual void _func100();
			virtual void _func101();
			virtual void _func102();
			virtual bool CanAttack(Actor*, bool);
			virtual void SetTarget(Actor*);
			virtual void _func105();
			virtual void _func106();
			virtual void Attack(Actor&);
			virtual void PerformRangedAttack(Actor&, float);
			virtual void AdjustDamageAmount(int&);
			virtual int GetEquipmentCount(void);
			virtual void SetOwner(uint64_t); //Param is ActorUniqueID
			virtual void SetSitting(bool);
			virtual void _func113();
			virtual void _func114();
			virtual int GetInventorySize(void);
			virtual int GetEquipSlots(void);
			virtual int GetChestSlots(void);
			virtual void GetStanding(bool);
			virtual bool CanPowerJump(void);
			virtual void SetCanPowerJump(bool);
			virtual bool IsJumping(void);
			virtual bool IsEnchanted(void);
			virtual void _func123();
			virtual void _func124();
			virtual bool ShouldRender(void);
			virtual void _func126();
			virtual void _func127();
			virtual void _func128();
			virtual void AnimateHurt(void);
			virtual void DoFireHurt(void);
			virtual void OnLightningHit(void);
			virtual void OnBounceStarted(void);
			virtual void Feed(int);
			virtual void HandleEntityEvent(class ActorEvent, int);
			virtual float GetPickRadius(void);
			virtual void GetActorRendererId(void);
			virtual void SpawnAtLocation(class ItemStack const&, float);
			virtual void SpawnAtLocation(class Block const&, int, float);
			virtual void SpawnAtLocation(class Block const&, int);
			virtual void SpawnAtLocation(int, int, float);
			virtual void SpawnAtLocation(int, int);
			virtual void Despawn(void);
			virtual void Killed(Actor&);
			virtual void _func144();
			virtual void SetArmor(int, class ItemStack const&);
			virtual class ItemStack GetArmor(int);
			virtual void _func147();
			virtual void _func148();
			virtual float GetModelScale(void);
			virtual class ItemStack GetEquippedSlot(int);
			virtual void GetEquippedSlot(int, class ItemStack const&);
			virtual class ItemStack GetSelectedItem(void);
			virtual void SetCarriedItem(class ItemStack const&);
			virtual void SetOffhandSlot(class ItemStack const&);
			virtual class ItemStack GetEquippedTotem(void);
			virtual void ConsumeTotem(void);
			virtual void _func157();
			virtual void _func158();
			virtual void _func159();
			virtual void _func160();
			virtual int GetEntityTypeId(void);
			virtual void QueryEntityRenderer(void);
			virtual __int64 GetSourceUniqueID(void);
			virtual void SetOnFire(int);
			virtual void GetHandleWaterAABB(void);
			virtual void HandleInsidePortal(Vector3 const&);
			virtual void _func167();
			virtual __int64 GetPortalCooldown(void);
			virtual int GetDimensionId(void);
			virtual void _func170();
			virtual void _func171();
			virtual void ChangeDimension(int, bool);
			virtual void _func173();
			virtual void CheckFallDamage(float, bool);
			virtual void CauseFallDamage(float);
			virtual void HandleFallDistanceOnServer(float, bool);
			virtual void _func177();
			virtual void _func178();
			virtual void OnSynchedDataUpdate(int);
			virtual bool CanAddRider(Actor&);
			virtual void _func181();
			virtual void _func182();
			virtual bool IsInCaravan(void);
			virtual void _func184();
			virtual void TickLeash(void);
			virtual void SendMotionPacketIfNeeded(void);
			virtual void _func187();
			virtual void StopRiding(bool, bool, bool);
			virtual void StartSwimming(void);
			virtual void StopSwimming(void);
			virtual void _func191();
			virtual int GetCommandPermissionLevel(void);
			virtual void _func193();
			virtual void _func194();
			virtual int GetDeathTime(void);
			virtual void Heal(int);
			virtual bool IsInvertedHealAndHarm(void);
			virtual void _func198();
			virtual bool CanBeAffected(int);
			virtual void _func200();
			virtual void _func201();
			virtual void _func202();
			virtual void _func203();
			virtual void _func204();
			virtual void _func205();
			virtual void Swing(void);
			virtual void _func206();
			virtual void _func207();
			virtual void _func208();
			virtual void _func209();
			virtual float GetMapDecorationRotation(void);
			virtual float GetRiderYRotation(Actor const&);
			virtual void _func212();
			virtual void _func213();
			virtual bool IsCreative(void);
			virtual bool IsAdventure(void);
			virtual void Add(class ItemStack&);
			virtual void Drop(class ItemStack const&, bool);
			virtual void _func218();
			virtual void _func219();
			virtual void _func220();
			virtual void SetSize(float, float);
			virtual int GetLifeSpan(void);
			virtual void OnOrphan(void);
			virtual void Wobble(void);
			virtual bool WasHurt(void);
			virtual void StartSpinAttack(void);
			virtual void StopSpinAttack(void);
			virtual void SetDamageNearbyMobs(bool);
			virtual void _func229();
			virtual void _func230();
			virtual void ReloadLootTable(void);
			virtual void _func232();
			virtual void Kill(void);
			virtual void Die(void);
			virtual bool ShouldTick(void);
			virtual void CreateMovementProxy(void);
			virtual void _func237();
			virtual void ShouldTryMakeStepSound(void);
			virtual float GetNextStep(float);
			virtual void _func240();
			virtual bool OutOfWorld(void);
			virtual void _func242();
			virtual void MarkHurt(void);
			virtual void _func244();
			virtual void _func245();
			virtual void _func246();
			virtual void _func247();
			virtual void _func248();
			virtual void CheckInsideBlocks(float);
			virtual void PushOutOfBlocks(Vector3 const&);
			virtual void UpdateWaterState(void);
			virtual void DoWaterSplashEffect(void);
			virtual void SpawnTrailBubbles(void);
			virtual void UpdateInsideBlock(void);
			virtual struct LootTable GetLootTable(void);
			virtual void _func256();
			virtual void _func257();
			virtual void _func258();
			virtual void _func259();
			virtual void Knockback(Actor*, int, float, float, float, float, float);
		};
	}
}