// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "ProjectileRocket.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API AProjectileRocket : public AProjectile
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float MinDamage = 10.f;

	UPROPERTY(EditAnywhere)
	float InnerRadius = 200.f;
	UPROPERTY(EditAnywhere)
	float OuterRdaius = 500.f;
	UPROPERTY(EditAnywhere)
	float DamageFalloff = 1.f;
	UPROPERTY(EditAnywhere)
	TArray<class AActor*> IgnoredActors;



protected:
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

};
