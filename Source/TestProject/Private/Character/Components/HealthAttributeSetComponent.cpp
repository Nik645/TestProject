// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Components/HealthAttributeSetComponent.h"

#include "Character/Attributes/HealthAttributeSet.h"

UHealthAttributeSetComponent::UHealthAttributeSetComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	HealthAttributeSet = CreateDefaultSubobject<UHealthAttributeSet>(TEXT("HealthAttributeSet"));
}

void UHealthAttributeSetComponent::Initialize_Implementation(UAbilitySystemComponent* InAbilitySystemComponent)
{
	AbilitySystemComponent = InAbilitySystemComponent;

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->AddSpawnedAttribute(HealthAttributeSet);
	}
}
