// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSetInterface.h"
#include "Components/ActorComponent.h"
#include "HealthAttributeSetComponent.generated.h"

class UAbilitySystemComponent;
class UHealthAttributeSet;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TESTPROJECT_API UHealthAttributeSetComponent : public UActorComponent, public IAttributeSetInterface
{
	GENERATED_BODY()

public:
	UHealthAttributeSetComponent();

protected:
	virtual void Initialize_Implementation(UAbilitySystemComponent* InAbilitySystemComponent) override;

private:
	UPROPERTY()
	UHealthAttributeSet* HealthAttributeSet = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent = nullptr;
};
