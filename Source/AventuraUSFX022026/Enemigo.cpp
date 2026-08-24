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

	// Cada enemigo elige su propia direccion aleatoria (independiente de los demas)
	float AnguloAleatorio = FMath::FRandRange(0.f, 360.f);
	DireccionMovimiento = FVector(
		FMath::Cos(FMath::DegreesToRadians(AnguloAleatorio)),
		FMath::Sin(FMath::DegreesToRadians(AnguloAleatorio)),
		0.f
	);

	// Se autodestruye 5 segundos despues de aparecer (para probar el TimerHandle)
	IniciarDesaparicion(5.0f);
}

void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Se mueve continuamente en su propia direccion
	AddMovementInput(DireccionMovimiento, 1.0f);
}

void AEnemigo::IniciarDesaparicion(float TiempoRetraso)
{
    GetWorldTimerManager().SetTimer(TimerHandle_Desaparicion, this, &AEnemigo::Desaparecer, TiempoRetraso, false);
}

void AEnemigo::Desaparecer()
{
    Destroy(); // Aquí es donde realmente desaparece del escenario
}