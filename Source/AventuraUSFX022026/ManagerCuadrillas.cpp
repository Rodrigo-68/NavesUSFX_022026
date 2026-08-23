#include "ManagerCuadrillas.h"
#include "Kismet/GameplayStatics.h"

AManagerCuadrillas::AManagerCuadrillas()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AManagerCuadrillas::BeginPlay()
{
	Super::BeginPlay();

	SpawnearCuadrilla1();

	// Cada 1 segundo revisamos si la Cuadrilla 1 ya no tiene miembros
	GetWorldTimerManager().SetTimer(
		TimerHandle_RevisarCuadrilla1,
		this,
		&AManagerCuadrillas::RevisarSiCuadrilla1Desaparecio,
		1.0f,
		true
	);
}

void AManagerCuadrillas::SpawnearCuadrilla1()
{
	for (int32 i = 0; i < ClasesCuadrilla1.Num(); i++)
	{
		if (ClasesCuadrilla1[i] == nullptr) continue;

		FTransform Transformacion = PuntosSpawnCuadrilla1.IsValidIndex(i) ?
			PuntosSpawnCuadrilla1[i] : GetActorTransform();

		FActorSpawnParameters Parametros;
		Parametros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		AEnemigo* NuevoEnemigo = GetWorld()->SpawnActor<AEnemigo>(ClasesCuadrilla1[i], Transformacion, Parametros);

		if (NuevoEnemigo)
		{
			MiembrosCuadrilla1.Add(NuevoEnemigo);
		}
	}
}

void AManagerCuadrillas::RevisarSiCuadrilla1Desaparecio()
{
	// Quitamos del array las referencias a enemigos ya destruidos
	MiembrosCuadrilla1.RemoveAll([](AEnemigo* E) { return E == nullptr; });

	if (MiembrosCuadrilla1.Num() == 0)
	{
		// Ya no hay nadie vivo en la Cuadrilla 1: detenemos esta revisi\u00f3n peri\u00f3dica
		GetWorldTimerManager().ClearTimer(TimerHandle_RevisarCuadrilla1);

		// Usamos OTRO TimerHandle para esperar antes de mostrar la Cuadrilla 2
		GetWorldTimerManager().SetTimer(
			TimerHandle_SpawnCuadrilla2,
			this,
			&AManagerCuadrillas::SpawnearCuadrilla2,
			RetrasoAparicionCuadrilla2,
			false
		);
	}
}

void AManagerCuadrillas::SpawnearCuadrilla2()
{
	for (int32 i = 0; i < ClasesCuadrilla2.Num(); i++)
	{
		if (ClasesCuadrilla2[i] == nullptr) continue;

		FTransform Transformacion = PuntosSpawnCuadrilla2.IsValidIndex(i) ?
			PuntosSpawnCuadrilla2[i] : GetActorTransform();

		FActorSpawnParameters Parametros;
		Parametros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		GetWorld()->SpawnActor<AEnemigo>(ClasesCuadrilla2[i], Transformacion, Parametros);
	}
}