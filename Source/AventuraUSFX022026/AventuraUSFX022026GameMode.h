// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AventuraUSFX022026GameMode.generated.h"


class ACompuerta;

UCLASS(MinimalAPI)
class AAventuraUSFX022026GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAventuraUSFX022026GameMode();

public: 
	ACompuerta* objetoSpawneado;

	void DestruirCompuerta();

protected:
	virtual void BeginPlay() override;
};



