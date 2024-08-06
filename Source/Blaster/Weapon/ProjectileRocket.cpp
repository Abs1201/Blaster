// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileRocket.h"
#include "Kismet/GameplayStatics.h"

void AProjectileRocket::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	APawn* FiringPawn = GetInstigator();
	if (FiringPawn) {
		AController* FiringController = FiringPawn->GetController();
		if (FiringController) {

			//IgnoredActors.AddUnique(this);

			UGameplayStatics::ApplyRadialDamageWithFalloff(
				this,
				Damage,
				MinDamage,
				GetActorLocation(),
				InnerRadius,
				OuterRdaius,
				DamageFalloff,
				UDamageType::StaticClass(),
				IgnoredActors,
				this,
				FiringController
			);
		}
	}

	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
}
