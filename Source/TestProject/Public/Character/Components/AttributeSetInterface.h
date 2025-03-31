// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AttributeSetInterface.generated.h"

class UAbilitySystemComponent;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAttributeSetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTPROJECT_API IAttributeSetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Initialize(UAbilitySystemComponent* AbilitySystemComponent);

protected:
	virtual void Initialize_Implementation(UAbilitySystemComponent* InAbilitySystemComponent)
	{
	};
};
