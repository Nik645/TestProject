// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "Character/Components/AttributeSetInterface.h"

ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void ABaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	for (auto AttributeSetComponents = GetComponentsByInterface(UAttributeSetInterface::StaticClass());
	     UActorComponent* AttributeSetComponent : AttributeSetComponents)
	{
		IAttributeSetInterface::Execute_Initialize(AttributeSetComponent, AbilitySystemComponent);
	}

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
	AddTags();
	InitializeAttributes();
	GiveAbilities();
}

void ABaseCharacter::InitializeAttributes() const
{
	if (AbilitySystemComponent == nullptr)
	{
		return;
	}

	if (InitEffect == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing DefaultAttributes for %s. Please fill in the character's Blueprint."),
		       *FString(__FUNCTION__), *GetName());
		return;
	}

	const FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	const UGameplayEffect* GameplayEffect = InitEffect->GetDefaultObject<UGameplayEffect>();
	AbilitySystemComponent->ApplyGameplayEffectToSelf(GameplayEffect, EffectsLevel, EffectContext);
}

void ABaseCharacter::GiveAbilities()
{
	if (AbilitySystemComponent == nullptr)
	{
		return;
	}

	for (const TSubclassOf<UGameplayAbility>& StartupAbility : CharacterAbilities)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1, INDEX_NONE, this));
	}
}

void ABaseCharacter::AddTags() const
{
	if (AbilitySystemComponent == nullptr)
	{
		return;
	}

	AbilitySystemComponent->AddLooseGameplayTags(GameplayTags);
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
