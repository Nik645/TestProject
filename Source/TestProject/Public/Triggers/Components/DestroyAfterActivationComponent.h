// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TriggerActivationInterface.h"
#include "Components/ActorComponent.h"
#include "DestroyAfterActivationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTPROJECT_API UDestroyAfterActivationComponent : public UActorComponent, public ITriggerActivationInterface
{
	GENERATED_BODY()

public:	
	UDestroyAfterActivationComponent();

protected:
	virtual void TriggerActivation_Implementation(AActor* OverlappedActor, AActor* OtherActor) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger")
	int MaxActivationCount = 0;

	UPROPERTY(SaveGame, BlueprintReadOnly, Category="Trigger")
	int ActivationCounter = 0;
};
