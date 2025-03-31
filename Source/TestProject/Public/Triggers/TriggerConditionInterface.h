// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TriggerConditionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTriggerConditionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTPROJECT_API ITriggerConditionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool TriggerCondition(AActor* OverlappedActor, AActor* OtherActor);

protected:
	virtual bool TriggerCondition_Implementation(AActor* OverlappedActor, AActor* OtherActor)
	{
		return true;
	};
};
