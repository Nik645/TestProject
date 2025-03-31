#include "Character/Components/MoveAttributeSetComponent.h"

#include "TestProject/Public/Character/Attributes/MoveAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"

UMoveAttributeSetComponent::UMoveAttributeSetComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	MoveAttributeSet = CreateDefaultSubobject<UMoveAttributeSet>(TEXT("MoveAttributeSet"));
}

void UMoveAttributeSetComponent::Initialize_Implementation(UAbilitySystemComponent* InAbilitySystemComponent)
{
	AbilitySystemComponent = InAbilitySystemComponent;
	CharacterMovementComponent = GetOwner()->GetComponentByClass<UCharacterMovementComponent>();

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->AddSpawnedAttribute(MoveAttributeSet);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MoveAttributeSet->GetWalkSpeedAttribute()).
		                        AddLambda([this](const FOnAttributeChangeData& _)
		                        {
			                        SetWalkSpeed();
		                        });
	}

	SetWalkSpeed();
}

void UMoveAttributeSetComponent::SetWalkSpeed() const
{
	if (CharacterMovementComponent == nullptr)
	{
		return;
	}

	CharacterMovementComponent->MaxWalkSpeed = MoveAttributeSet->GetWalkSpeed();
	UE_LOG(LogTemp, Error, TEXT("Move Attribute Set %f"), MoveAttributeSet->GetWalkSpeed());
}
