// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "../TriggerConditionInterface.h"
#include "Components/ActorComponent.h"
#include "CheckGameplayTagsComponent.generated.h"

UENUM(BlueprintType)
enum class ETagsMatching : uint8
{
	AnyMatching,
	AllMatching
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TESTPROJECT_API UCheckGameplayTagsComponent : public UActorComponent, public ITriggerConditionInterface
{
	GENERATED_BODY()

public:
	UCheckGameplayTagsComponent();

protected:
	virtual bool TriggerCondition_Implementation(AActor* OverlappedActor, AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger")
	FGameplayTagContainer TagContainer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger")
	ETagsMatching TagsMatching = ETagsMatching::AnyMatching;
};
