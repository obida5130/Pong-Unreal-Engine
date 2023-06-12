// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"


ABoard::ABoard()
{
	PrimaryActorTick.bCanEverTick = true;
	SetRootComponent(GetRenderComponent());
	UpBox = CreateDefaultSubobject<UBoxComponent>("UpBox");
	UpBox->SetupAttachment(RootComponent);
	UpBox->SetBoxExtent(FVector(1200.0f, 500.0f, 100.0f));
	UpBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	UpBox->SetCollisionProfileName("BlockAll");
	UpBox->SetRelativeLocation(FVector(0.0f, 0.0f, 670.0f));

	BottomBox = CreateDefaultSubobject<UBoxComponent>("BottomBox");
	BottomBox->SetupAttachment(RootComponent);
	BottomBox->SetBoxExtent(FVector(1200.0f, 500.0f, 100.0f));
	BottomBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BottomBox->SetCollisionProfileName("BlockAll");
	BottomBox->SetRelativeLocation(FVector(0.0f, 0.0f, -670.0f));
	LevelCamera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	LevelCamera->SetRelativeLocation(FVector(0.0f, 1300.0f, 0.0f));
	LevelCamera->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));


}

