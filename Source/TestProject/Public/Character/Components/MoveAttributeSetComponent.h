// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSetInterface.h"
#include "Components/ActorComponent.h"
#include "MoveAttributeSetComponent.generated.h"

class UAbilitySystemComponent;
class UCharacterMovementComponent;
class UMoveAttributeSet;
class IAbilitySystemInterface;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TESTPROJECT_API UMoveAttributeSetComponent : public UActorComponent, public IAttributeSetInterface
{
	GENERATED_BODY()

public:
	UMoveAttributeSetComponent();

protected:
	virtual void Initialize_Implementation(UAbilitySystemComponent* InAbilitySystemComponent) override;
	void SetWalkSpeed() const;

private:
	UPROPERTY()
	UMoveAttributeSet* MoveAttributeSet = nullptr;

	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent = nullptr;
};
