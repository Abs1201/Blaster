// Fill out your copyright notice in the Description page of Project Settings.


#include "Flag.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"


AFlag::AFlag()
{


}

//void AFlag::Dropped()
//{
//}
//
//
//void AFlag::OnEquipped()
//{
//
//}
//
void AFlag::OnDropped()
{
	Super::OnDropped();

}
