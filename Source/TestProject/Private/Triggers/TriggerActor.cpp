// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggers/TriggerActor.h"

#include "Triggers/TriggerConditionInterface.h"

ATriggerActor::ATriggerActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATriggerActor::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ATriggerActor::OnBeginOverlap);
}

void ATriggerActor::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (!CheckTriggerConditions(OverlappedActor, OtherActor))
	{
		return;
	}

	CallTriggerActivation(OverlappedActor, OtherActor);
}

void ATriggerActor::CallTriggerActivation(AActor* OverlappedActor, AActor* OtherActor)
{
	TArray<UObject*> ActivationObjects;
	GetAllInterfaceImplementations(UTriggerActivationInterface::StaticClass(), ActivationObjects);
	for (UObject* Object : ActivationObjects)
	{
		ITriggerActivationInterface::Execute_TriggerActivation(Object, OverlappedActor, OtherActor);
	}
}

bool ATriggerActor::CheckTriggerConditions(AActor* OverlappedActor, AActor* OtherActor)
{
	TArray<UObject*> Conditions;
	GetAllInterfaceImplementations(UTriggerConditionInterface::StaticClass(), Conditions);

	for (UObject* Condition : Conditions)
	{
		if (!ITriggerConditionInterface::Execute_TriggerCondition(Condition, OverlappedActor, OtherActor))
		{
			return false;
		}
	}

	return true;
}

void ATriggerActor::GetAllInterfaceImplementations(const TSubclassOf<UInterface> Interface, TArray<UObject*>& Array)
{
	if (const auto MyClass = GetClass(); MyClass->ImplementsInterface(Interface))
	{
		Array.Add(this);
	}

	for (UActorComponent* ComponentsByInterface : GetComponentsByInterface(Interface))
	{
		Array.Add(ComponentsByInterface);
	}
}
