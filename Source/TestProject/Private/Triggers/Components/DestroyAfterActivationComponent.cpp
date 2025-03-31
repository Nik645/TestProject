// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggers/Components/DestroyAfterActivationComponent.h"

UDestroyAfterActivationComponent::UDestroyAfterActivationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UDestroyAfterActivationComponent::TriggerActivation_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	++ActivationCounter;

	if (MaxActivationCount < 1)
	{
		return;
	}

	if (ActivationCounter >= MaxActivationCount)
	{
		GetOwner()->Destroy();
	}
}
