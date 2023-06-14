// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

UCLASS()
class UEMODES_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	AEnemyPawn();

	UPROPERTY(EditAnywhere, Category = "Pawn Visual")
		class UPaperSpriteComponent* PawnSpriteComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom")
		class UBoxComponent* EnemyRootCollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector MovementDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float MovementSpeed;
	FVector BallLocation;

protected:
	virtual void BeginPlay() override;
	

public:
	virtual void Tick(float DeltaTime) override;

private:
	FVector StartLocation;
	float DebugTime;
	float DebugTimeAccumulator;
	float TimeAccumulator;


};
