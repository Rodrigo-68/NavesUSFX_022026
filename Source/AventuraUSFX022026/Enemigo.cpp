#include "Enemigo.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemigo::AEnemigo()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AEnemigo::BeginPlay()
{
    Super::BeginPlay();
    GetCharacterMovement()->MaxWalkSpeed = VelocidadMovimiento;
    IniciarDesaparicion(5.0f); // Se autodestruye 5 segundos después de aparecer, para probar el sistema
}

void AEnemigo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Aquí puede ir un movimiento genérico simple (patrulla, avance, etc.)
}

void AEnemigo::IniciarDesaparicion(float TiempoRetraso)
{
    GetWorldTimerManager().SetTimer(TimerHandle_Desaparicion, this, &AEnemigo::Desaparecer, TiempoRetraso, false);
}

void AEnemigo::Desaparecer()
{
    Destroy(); // Aquí es donde realmente desaparece del escenario
}