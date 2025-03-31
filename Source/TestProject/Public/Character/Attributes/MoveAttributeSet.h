// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BaseAttributeSet.h"
#include "MoveAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UMoveAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()

public:
	ATTRIBUTE_ACCESSORS(UMoveAttributeSet, WalkSpeed);

private:
	UPROPERTY(BlueprintReadOnly, Category = "AbilitySystem", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData WalkSpeed = 600.f;
};
