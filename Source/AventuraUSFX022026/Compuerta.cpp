// Fill out your copyright notice in the Description page of Project Settings.


#include "Compuerta.h"

// Sets default values
ACompuerta::ACompuerta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CompuertaMallaAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));

	// Create mesh component for the projectile sphere
	mallaCompuerta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CompuertaMalla01"));
	mallaCompuerta->SetStaticMesh(CompuertaMallaAsset.Object);
	mallaCompuerta->SetupAttachment(RootComponent);
	RootComponent = mallaCompuerta;

	PosicionActual = FVector(0.0f, 0.0f, 0.0f);
    PosicionMinima = FVector(200.0f, 200.0f, 200.0f);
    PosicionMaxima = FVector(0.0f, 0.0f, 800.0f);
    Incremento = FVector(10.0f, 10.0f, 10.0f);
    Velocidad = 150.0f;
    SignoIncremento = 1;

}

// Called when the game starts or when spawned
void ACompuerta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACompuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    
	PosicionActual = this->GetActorLocation();
    
    if (PosicionActual.Z >= PosicionMaxima.Z)
        SignoIncremento = -1;
    if (PosicionActual.Z <= PosicionMinima.Z)
        SignoIncremento = 1;

    FVector NuevaPosicion = PosicionActual;
    NuevaPosicion.Y = NuevaPosicion.Y + (SignoIncremento * Incremento.Y * DeltaTime);
    NuevaPosicion.Z = NuevaPosicion.Z + (SignoIncremento * Incremento.Z * DeltaTime);
    
    SetActorLocation(NuevaPosicion);

    /*
    // Crear una dirección aleatoria
    FVector DireccionAleatoria(
        FMath::FRandRange(-50.0f, 50.0f),
        FMath::FRandRange(-50.0f, 50.0f),
        0.0f
    );

    // Normalizar para mantener una velocidad aproximadamente constante
    DireccionAleatoria.Normalize();

    // Calcular nueva posición
    FVector NuevaPosicion =
        PosicionActual +
        DireccionAleatoria * Velocidad * DeltaTime;

    // Mover el actor
    SetActorLocation(NuevaPosicion);
    */
}

