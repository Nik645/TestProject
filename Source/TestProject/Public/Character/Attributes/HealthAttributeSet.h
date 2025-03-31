// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Character/Attributes/BaseAttributeSet.h"
#include "HealthAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UHealthAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()

public:
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, MaxHealth)

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

private:
	UPROPERTY(BlueprintReadOnly, Category = "AbilitySystem", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health = 100.f;

	UPROPERTY(BlueprintReadOnly, Category = "AbilitySystem", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth = 100.f;
};
