// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChatBox.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UChatBox : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetChatText(FString SenderName, FString Message);

	UPROPERTY(meta = (BindWidget))
	class UScrollBox* ScrollBox_Chat;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock_Chat;
};
