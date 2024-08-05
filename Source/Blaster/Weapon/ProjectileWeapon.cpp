// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileWeapon.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Projectile.h"

void AProjectileWeapon::Fire(const FVector& HitTarget)
{
	Super::Fire(HitTarget);

	if (!HasAuthority()) return;

	APawn* InstigatorPawn = Cast<APawn>(GetOwner());
	const USkeletalMeshSocket* MuzzleFlashSocket = GetWeaponMesh()->GetSocketByName(FName("MuzzleFlash"));
	if (MuzzleFlashSocket) {
		FTransform SocketTransform = MuzzleFlashSocket->GetSocketTransform(GetWeaponMesh());
		FVector ToTarget = HitTarget - SocketTransform.GetLocation();
		FRotator TargetRotation = ToTarget.Rotation();
		if (ProjectileClass) {
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = GetOwner();
			SpawnParams.Instigator = InstigatorPawn; 
			UWorld* World = GetWorld();
			if (World) {
				World->SpawnActor<AProjectile>(
					ProjectileClass,
					SocketTransform.GetLocation(),
					TargetRotation,
					SpawnParams
				);
			}
		}
	}


}

float AProjectileWeapon::GetZoomedFOV() const
{
	Super::GetZoomedFOV();

	EWeaponType TypeofWeapon = GetWeaponType();
	switch (TypeofWeapon) {
	case EWeaponType::EWT_AssaultRifle:
		UE_LOG(LogTemp, Warning, TEXT("aaa"));
		return 45.f;
	case EWeaponType::EWT_SniperRifle:
		UE_LOG(LogTemp, Warning, TEXT("bbb"));

		return 10.f;
	default:
		return 30.f;
	}
	
}
