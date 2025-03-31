// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggers/Components/CheckGameplayTagsComponent.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"

UCheckGameplayTagsComponent::UCheckGameplayTagsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UCheckGameplayTagsComponent::TriggerCondition_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	if (!OtherActor->Implements<UAbilitySystemInterface>())
	{
		return false;
	}

	const auto AbilitySystemComponent = Cast<IAbilitySystemInterface>(OtherActor)->GetAbilitySystemComponent();
	if (AbilitySystemComponent == nullptr)
	{
		return false;
	}

	if (TagContainer.IsEmpty())
	{
		return true;
	}

	if (TagsMatching == ETagsMatching::AnyMatching)
	{
		return AbilitySystemComponent->HasAnyMatchingGameplayTags(TagContainer);
	}

	return AbilitySystemComponent->HasAllMatchingGameplayTags(TagContainer);
}
