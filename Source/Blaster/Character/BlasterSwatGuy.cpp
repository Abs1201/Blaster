// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterSwatGuy.h"
#include "Components/BoxComponent.h"
#include <Blaster/Blaster.h>

ABlasterSwatGuy::ABlasterSwatGuy()
{
	/*
	* Hit boxes for server-side rewind
	*/

	head = CreateDefaultSubobject<UBoxComponent>(TEXT("head"));
	head->SetupAttachment(GetMesh(), FName("Head"));
	HitCollisionBoxes.Add(FName("Head"), head);

	pelvis = CreateDefaultSubobject<UBoxComponent>(TEXT("pelvis"));
	pelvis->SetupAttachment(GetMesh(), FName("Hips"));
	HitCollisionBoxes.Add(FName("Hips"), pelvis);

	spine_02 = CreateDefaultSubobject<UBoxComponent>(TEXT("spine_02"));
	spine_02->SetupAttachment(GetMesh(), FName("Spine1"));
	HitCollisionBoxes.Add(FName("Spine1"), spine_02);

	spine_03 = CreateDefaultSubobject<UBoxComponent>(TEXT("spine_03"));
	spine_03->SetupAttachment(GetMesh(), FName("Spine2"));
	HitCollisionBoxes.Add(FName("Spine2"), spine_03);

	upperarm_l = CreateDefaultSubobject<UBoxComponent>(TEXT("upperarm_l"));
	upperarm_l->SetupAttachment(GetMesh(), FName("LeftArm"));
	HitCollisionBoxes.Add(FName("LeftArm"), upperarm_l);

	upperarm_r = CreateDefaultSubobject<UBoxComponent>(TEXT("upperarm_r"));
	upperarm_r->SetupAttachment(GetMesh(), FName("RightArm"));
	HitCollisionBoxes.Add(FName("RightArm"), upperarm_r);

	lowerarm_l = CreateDefaultSubobject<UBoxComponent>(TEXT("lowerarm_l"));
	lowerarm_l->SetupAttachment(GetMesh(), FName("LeftForeArm"));
	HitCollisionBoxes.Add(FName("LeftForeArm"), lowerarm_l);

	lowerarm_r = CreateDefaultSubobject<UBoxComponent>(TEXT("lowerarm_r"));
	lowerarm_r->SetupAttachment(GetMesh(), FName("RightForeArm"));
	HitCollisionBoxes.Add(FName("RightForeArm"), lowerarm_r);

	hand_l = CreateDefaultSubobject<UBoxComponent>(TEXT("hand_l"));
	hand_l->SetupAttachment(GetMesh(), FName("LeftHand"));
	HitCollisionBoxes.Add(FName("LeftHand"), hand_l);

	hand_r = CreateDefaultSubobject<UBoxComponent>(TEXT("hand_r"));
	hand_r->SetupAttachment(GetMesh(), FName("RightHand"));
	HitCollisionBoxes.Add(FName("RightHand"), hand_r);

	//blanket = CreateDefaultSubobject<UBoxComponent>(TEXT("blanket"));
	//blanket->SetupAttachment(GetMesh(), FName("Spine"));
	//HitCollisionBoxes.Add(FName("Spine"), blanket);

	backpack = CreateDefaultSubobject<UBoxComponent>(TEXT("backpack"));
	backpack->SetupAttachment(GetMesh(), FName("Spine"));
	HitCollisionBoxes.Add(FName("Spine"), backpack);

	thigh_l = CreateDefaultSubobject<UBoxComponent>(TEXT("thigh_l"));
	thigh_l->SetupAttachment(GetMesh(), FName("LeftUpLeg"));
	HitCollisionBoxes.Add(FName("LeftUpLeg"), thigh_l);

	thigh_r = CreateDefaultSubobject<UBoxComponent>(TEXT("thigh_r"));
	thigh_r->SetupAttachment(GetMesh(), FName("RightUpLeg"));
	HitCollisionBoxes.Add(FName("RightUpLeg"), thigh_r);

	calf_l = CreateDefaultSubobject<UBoxComponent>(TEXT("calf_l"));
	calf_l->SetupAttachment(GetMesh(), FName("LeftLeg"));
	HitCollisionBoxes.Add(FName("LeftLeg"), calf_l);

	calf_r = CreateDefaultSubobject<UBoxComponent>(TEXT("calf_r"));
	calf_r->SetupAttachment(GetMesh(), FName("RightLeg"));
	HitCollisionBoxes.Add(FName("RightLeg"), calf_r);

	foot_l = CreateDefaultSubobject<UBoxComponent>(TEXT("foot_l"));
	foot_l->SetupAttachment(GetMesh(), FName("LeftFoot"));
	HitCollisionBoxes.Add(FName("LeftFoot"), foot_l);

	foot_r = CreateDefaultSubobject<UBoxComponent>(TEXT("foot_r"));
	foot_r->SetupAttachment(GetMesh(), FName("RightFoot"));
	HitCollisionBoxes.Add(FName("RightFoot"), foot_r);

	for (auto& Box : HitCollisionBoxes) {
		if (Box.Value) {
			Box.Value->SetCollisionObjectType(ECC_HitBox);
			Box.Value->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
			Box.Value->SetCollisionResponseToChannel(ECC_HitBox, ECollisionResponse::ECR_Block);
			Box.Value->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}

