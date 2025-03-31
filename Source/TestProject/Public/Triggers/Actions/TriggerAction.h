// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TriggerAction.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, DefaultToInstanced, EditInlineNew)
class TESTPROJECT_API UTriggerAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "TriggerAction")
	virtual void Execute(AActor* OverlappedActor, AActor* OtherActor)
	{
	};
};
