// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "Board.generated.h"

/**
 * 
 */
UCLASS()
class UEMODES_API ABoard : public APaperSpriteActor
{
	GENERATED_BODY()

public :
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UCameraComponent* LevelCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UBoxComponent* UpBox;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UBoxComponent* BottomBox;
	ABoard();


};
