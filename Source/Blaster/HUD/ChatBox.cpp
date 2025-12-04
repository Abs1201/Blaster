// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"

void UChatBox::SetChatText(FString SenderName, FString Message)
{
	FString ChatText = FString::Printf(TEXT("%s: %s"), *SenderName, *Message);
	if (TextBlock_Chat)
	{
		TextBlock_Chat->SetText(FText::FromString(ChatText));
	}
}
