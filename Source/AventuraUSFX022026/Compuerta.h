// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Compuerta.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026_API ACompuerta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACompuerta();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UStaticMeshComponent* mallaCompuerta;

	FVector PosicionActual;
	FVector PosicionMaxima;
	FVector PosicionMinima;
	FVector Incremento;
	
	float Velocidad;

	float SignoIncremento;

};
