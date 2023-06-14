#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PongHUD.generated.h"

UCLASS()
class UEMODES_API APongHUD : public AHUD
{
    GENERATED_BODY()

public:
    APongHUD();

    virtual void DrawHUD() override;

    int32 playerScore;
    int32 aiScore;
};
