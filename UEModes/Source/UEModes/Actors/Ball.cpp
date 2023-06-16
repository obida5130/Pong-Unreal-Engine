// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "../GameState/UEGameState.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	////1
	//CollisionSphere = CreateDefaultSubobject<USphereComponent>("SceneRoot");
	////2
	//CollisionSphere->SetSphereRadius(75); //100,10,100
	////3
	//CollisionSphere->SetSimulatePhysics(true);
	////4 - Add a Step and show camera .
	//CollisionSphere->SetCollisionProfileName("BlockAll");
	////5	
	//CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	////6
	//CollisionSphere->GetBodyInstance()->bLockXRotation = true;
	//CollisionSphere->GetBodyInstance()->bLockZRotation = true;
	//CollisionSphere->GetBodyInstance()->bLockYTranslation = true;

	////
	//CollisionSphere->SetNotifyRigidBodyCollision(true);

	////7
	//CollisionSphere->OnComponentHit.AddDynamic(this, &ABall::OnHit);
	////8
	//SetRootComponent(CollisionSphere);

	CollisionSphere = CreateDefaultSubobject<USphereComponent>("SceneRoot");
	CollisionSphere->SetSphereRadius(24.0f); 
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionSphere->SetCollisionProfileName("BlockAll");
	//CollisionSphere->SetSimulatePhysics(true);

	RootComponent = CollisionSphere;

	/**  paper sprite component */
	BallSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Paper Sprite Component"));
	BallSprite->SetupAttachment(RootComponent);
	BallSprite->SetCollisionEnabled(ECollisionEnabled::NoCollision);



	BallMovementComponent= CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BallMovementComponent"));
	BallMovementComponent->ProjectileGravityScale = 0.0f;
	BallMovementComponent->InitialSpeed = 1000;
	BallMovementComponent->MaxSpeed = 10000;
	BallMovementComponent->bShouldBounce = true;
	BallMovementComponent->Bounciness = 1.1f;
	BallMovementComponent->Friction = 0;


	CollisionSphere->OnComponentHit.AddDynamic(this, &ABall::OnHit);

	/** set ball sprite asset */
	//static ConstructorHelpers::FObjectFinder<UPaperSprite> PaperSpriteTemplate(TEXT("/Game/Sprites/Ball_Sprite"));
	//if (PaperSpriteTemplate.Succeeded())
	//{
	//	BallSprite->SetSprite(PaperSpriteTemplate.Object);
	//}
	//

	
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector location = GetActorLocation();
	// Define your left and right bounds
	float leftBound = -1400.0f;
	float rightBound = 1000.0f;

	AUEGameState* gameState = GetWorld()->GetGameState<AUEGameState>();//getting core value from UEGameState

	if (location.X < leftBound)
	{

		gameState->NumberOfRightGoals++;

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Out of bounds, Position: %s, Velocity: %s"), *location.ToString(), *BallMovementComponent->Velocity.ToString()));

		BallMovementComponent->StopMovementImmediately();


		location.X = -410.620439f;
		location.Y = 77.314116f;
		location.Z = 1220.0f;
		SetActorLocation(location);

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
			{
				FRotator newDirection(0.f, 183.599526f, 0.f);
				FVector newVelocity = newDirection.Vector() * 1000.f;
				BallMovementComponent->Velocity = newVelocity;
			}, 1.0f, false);


	}
	if (location.X > rightBound)
	{

		gameState->NumberOfLeftGoals++;

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Out of bounds, Position: %s, Velocity: %s"), *location.ToString(), *BallMovementComponent->Velocity.ToString()));

		BallMovementComponent->StopMovementImmediately();


		location.X = -410.620439f;
		location.Y = 77.314116f;
		location.Z = 1220.0f;
		SetActorLocation(location);

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
			{
				FRotator newDirection(0.f, 183.599526f, 0.f);
				FVector newVelocity = newDirection.Vector() * 1000.f;
				BallMovementComponent->Velocity = newVelocity;
			}, 1.0f, false);




	}

	location.Y = 0.0f;
	SetActorLocation(location);
}




void ABall::Destroyed()
{
	Super::Destroyed();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, FString::Printf(TEXT("BALL DESTROYED")));
}

UPrimitiveComponent* ABall::GetPhysicsComponent()
{
	return Cast<UPrimitiveComponent>(CollisionSphere);
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != this)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s has Hit"), *OtherActor->GetName()));
		}
	}
}

