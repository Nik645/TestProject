// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "BaseCharacter.generated.h"

class UGameplayEffect;
class UGameplayAbility;

UCLASS()
class TESTPROJECT_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void PostInitializeComponents() override;

protected:
	void InitializeAttributes() const;
	void GiveAbilities();
	void AddTags() const;

public:	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	TArray<TSubclassOf<UGameplayAbility>> CharacterAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	TSubclassOf<UGameplayEffect> InitEffect;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	FGameplayTagContainer GameplayTags;
	
	const float EffectsLevel = 1.f;
};
