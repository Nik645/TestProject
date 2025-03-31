// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggers/Actions/PrintStringTriggerAction.h"

void UPrintStringTriggerAction::Execute(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Display, TEXT("%s"), *Text);
}
