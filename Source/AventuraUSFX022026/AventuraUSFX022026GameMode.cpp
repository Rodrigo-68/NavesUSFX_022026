// Copyright Epic Games, Inc. All Rights Reserved.

#include "AventuraUSFX022026GameMode.h"
#include "AventuraUSFX022026Pawn.h"
#include "Compuerta.h"
#include "CustomHUD.h"

AAventuraUSFX022026GameMode::AAventuraUSFX022026GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAventuraUSFX022026Pawn::StaticClass();
	HUDClass = ACustomHUD::StaticClass();
}

void AAventuraUSFX022026GameMode::DestruirCompuerta()
{
	if (objetoSpawneado != nullptr)
	{
		objetoSpawneado->Destroy();
	}
}

void AAventuraUSFX022026GameMode::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Spawning la compuerta"));
	
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(FVector(-790.0f, 150.0f, 250.0f));
	objetoSpawneado = GetWorld()->SpawnActor<ACompuerta>(ACompuerta::StaticClass(), SpawnLocation);

	FTimerHandle Temporizador;
	GetWorldTimerManager().SetTimer(Temporizador, this, &AAventuraUSFX022026GameMode::DestruirCompuerta, 500);

}

