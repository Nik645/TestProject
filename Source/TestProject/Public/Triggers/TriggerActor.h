// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TriggerActivationInterface.h"
#include "GameFramework/Actor.h"
#include "TriggerActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TESTPROJECT_API ATriggerActor : public AActor
{
	GENERATED_BODY()

public:
	ATriggerActor();

protected:
	virtual void BeginPlay() override;
	virtual void GetAllInterfaceImplementations(TSubclassOf<UInterface> Interface, TArray<UObject*>& Array);

	bool CheckTriggerConditions(AActor* OverlappedActor, AActor* OtherActor);
	void CallTriggerActivation(AActor* OverlappedActor, AActor* OtherActor);

public:
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
