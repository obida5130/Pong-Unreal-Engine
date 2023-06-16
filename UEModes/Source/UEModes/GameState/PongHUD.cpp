#include "PongHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"

APongHUD::APongHUD()
{
    playerScore = 0;
    aiScore = 0;
}


void APongHUD::DrawHUD()
{
    Super::DrawHUD();

    if (Canvas && GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player Score: %d"), playerScore), true, FVector2D(1.5f, 1.5f));

        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("AI Score: %d"), aiScore), true, FVector2D(1.5f, 1.5f));
    }
}
