// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggers/Components/ApplyGameplayEffectComponent.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"

UApplyGameplayEffectComponent::UApplyGameplayEffectComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UApplyGameplayEffectComponent::TriggerActivation_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	if (!EffectClass)
	{
		UE_LOG(LogTemp, Error, TEXT("EffectClass is null"));
		return;
	}

	if (!OtherActor->Implements<UAbilitySystemInterface>())
	{
		return;
	}

	const auto AbilitySystemComponent = Cast<IAbilitySystemInterface>(OtherActor)->GetAbilitySystemComponent();
	if (AbilitySystemComponent == nullptr)
	{
		return;
	}

	const FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	const UGameplayEffect* GameplayEffect = EffectClass->GetDefaultObject<UGameplayEffect>();
	AbilitySystemComponent->ApplyGameplayEffectToSelf(GameplayEffect, EffectLevel, EffectContext);
}
