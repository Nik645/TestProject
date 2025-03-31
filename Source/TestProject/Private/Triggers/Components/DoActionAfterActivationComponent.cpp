// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggers/Components/DoActionAfterActivationComponent.h"

#include "Triggers/Actions/TriggerAction.h"

UDoActionAfterActivationComponent::UDoActionAfterActivationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UDoActionAfterActivationComponent::TriggerActivation_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	for (UTriggerAction* TriggerAction : TriggerActions)
	{
		if (!TriggerAction)
		{
			continue;
		}

		TriggerAction->Execute(OverlappedActor, OtherActor);
	}
}
