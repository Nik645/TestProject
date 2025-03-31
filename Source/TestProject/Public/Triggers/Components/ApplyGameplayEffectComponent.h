// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Triggers/TriggerActivationInterface.h"
#include "ApplyGameplayEffectComponent.generated.h"


class UGameplayEffect;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TESTPROJECT_API UApplyGameplayEffectComponent : public UActorComponent, public ITriggerActivationInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UApplyGameplayEffectComponent();

protected:
	virtual void TriggerActivation_Implementation(AActor* OverlappedActor, AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayEffect> EffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EffectLevel = 1;
};
