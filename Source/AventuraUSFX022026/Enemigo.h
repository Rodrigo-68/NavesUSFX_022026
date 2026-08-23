#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemigo.generated.h"

UCLASS()
class AVENTURAUSFX022026_API AEnemigo : public ACharacter
{
    GENERATED_BODY()

public:
    AEnemigo();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo")
    float Vida = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo")
    float VelocidadMovimiento = 300.f;

    // Llamar cuando el enemigo "muere" en juego
    UFUNCTION(BlueprintCallable, Category = "Enemigo")
    void IniciarDesaparicion(float TiempoRetraso = 2.0f);

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // El handle que controla la desaparición
    FTimerHandle TimerHandle_Desaparicion;

    UFUNCTION()
    void Desaparecer();
};