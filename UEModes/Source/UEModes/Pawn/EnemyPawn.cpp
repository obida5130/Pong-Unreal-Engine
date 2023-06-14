#include "EnemyPawn.h"
#include "GameFramework/Actor.h"


#include "CollidingPawn.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"

#include "GameFramework/SpringArmComponent.h"
// A global variable to keep track of the elapsed time
float GlobalTime = 0.0f;

AEnemyPawn::AEnemyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	EnemyRootCollisionBox = CreateDefaultSubobject<UBoxComponent>("SceneRoot");
	EnemyRootCollisionBox->SetBoxExtent(FVector(120, 50, 140));
	EnemyRootCollisionBox->SetSimulatePhysics(true);
	EnemyRootCollisionBox->SetCollisionProfileName("BlockAllDynamic");
	EnemyRootCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	EnemyRootCollisionBox->GetBodyInstance()->bLockRotation = true;
	EnemyRootCollisionBox->GetBodyInstance()->bLockXRotation = true;
	EnemyRootCollisionBox->GetBodyInstance()->bLockYRotation = true;
	EnemyRootCollisionBox->GetBodyInstance()->bLockZRotation = true;
	EnemyRootCollisionBox->GetBodyInstance()->bLockYTranslation = true;
	EnemyRootCollisionBox->SetEnableGravity(false);

	SetRootComponent(EnemyRootCollisionBox);

	PawnSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Sprite");
	PawnSpriteComponent->SetupAttachment(RootComponent);
	PawnSpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DebugTimeAccumulator = 0.0f;
	TimeAccumulator = 0.0f;

	MovementDirection = FVector(0.0f, 0.0f, 0.0f);
	MovementSpeed = 5.0f;
}

void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DebugTimeAccumulator += DeltaTime;
	TimeAccumulator += DeltaTime;

	if (DebugTimeAccumulator >= 1.0f)
	{
		DebugTimeAccumulator -= 1.0f;

		FVector NewLocation = GetActorLocation();
	}

	FVector NewLocation = GetActorLocation();
	NewLocation.Z = StartLocation.Z + FMath::Sin(TimeAccumulator) * 320.0f;

	SetActorLocation(NewLocation);
}

