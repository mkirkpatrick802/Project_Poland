#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WormSpawner.generated.h"

UCLASS()
class PROJECT_POLAND_API AWormSpawner : public AActor
{
	GENERATED_BODY()
	
public:	 

	AWormSpawner();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	void SpawnWorm() const;

	// Debug
	void DrawDebug() const;
	
private:

	UPROPERTY(EditAnywhere, Category="Debug")
	bool EnableDebug = true;
	
	UPROPERTY(EditAnywhere, Category="Spawner")
	float SpawnRadius = 20;

	FTimerHandle WormSpawnerTimer;
	
};
