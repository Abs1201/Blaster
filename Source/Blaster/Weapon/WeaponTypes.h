#pragma once

UENUM(BlueprintType)
enum class EWeaponType : uint8 {

	EWT_AssaultRifle UMETA(DisplayName = "Assault Rifle"),
	EWT_SniperRifle UMETA(DisplayName = "Sniper Rifle"),
	EWT_RocketLauncher UMETA(DisplayName = "Rocket Launcher"),

	EWT_MAX UMETA(DisplayName = "DefaultMAX")
};