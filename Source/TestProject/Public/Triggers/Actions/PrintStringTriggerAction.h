// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Triggers/Actions/TriggerAction.h"
#include "PrintStringTriggerAction.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UPrintStringTriggerAction : public UTriggerAction
{
	GENERATED_BODY()

public:
	virtual void Execute(AActor* OverlappedActor, AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TriggerAction")
	FString Text;
};
