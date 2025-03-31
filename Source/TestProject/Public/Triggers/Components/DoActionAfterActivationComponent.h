// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Triggers/TriggerActivationInterface.h"
#include "DoActionAfterActivationComponent.generated.h"

class UTriggerAction;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TESTPROJECT_API UDoActionAfterActivationComponent : public UActorComponent, public ITriggerActivationInterface
{
	GENERATED_BODY()

public:
	UDoActionAfterActivationComponent();

protected:
	virtual void TriggerActivation_Implementation(AActor* OverlappedActor, AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "TriggerAction")
	TArray<UTriggerAction*> TriggerActions;
};
