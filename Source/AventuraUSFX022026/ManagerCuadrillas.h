#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.h"
#include "ManagerCuadrillas.generated.h"

UCLASS()
class AVENTURAUSFX022026_API AManagerCuadrillas : public AActor
{
	GENERATED_BODY()

public:
	AManagerCuadrillas();

	// Clases hoja que forman la Cuadrilla 1 (asignar en el editor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cuadrillas")
	TArray<TSubclassOf<AEnemigo>> ClasesCuadrilla1;

	// Clases hoja que forman la Cuadrilla 2 (asignar en el editor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cuadrillas")
	TArray<TSubclassOf<AEnemigo>> ClasesCuadrilla2;

	// Puntos de spawn de la Cuadrilla 1 (uno por cada elemento del array de arriba)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cuadrillas")
	TArray<FTransform> PuntosSpawnCuadrilla1;

	// Puntos de spawn de la Cuadrilla 2
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cuadrillas")
	TArray<FTransform> PuntosSpawnCuadrilla2;

	// Segundos de espera entre que desaparece la Cuadrilla 1 y aparece la Cuadrilla 2
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cuadrillas")
	float RetrasoAparicionCuadrilla2 = 2.0f;

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<AEnemigo*> MiembrosCuadrilla1;

	// TimerHandle que revisa peri\u00f3dicamente si la cuadrilla 1 ya desapareci\u00f3
	FTimerHandle TimerHandle_RevisarCuadrilla1;

	// TimerHandle que controla el retraso antes de mostrar la cuadrilla 2
	FTimerHandle TimerHandle_SpawnCuadrilla2;

	void SpawnearCuadrilla1();
	void SpawnearCuadrilla2();
	void RevisarSiCuadrilla1Desaparecio();
};