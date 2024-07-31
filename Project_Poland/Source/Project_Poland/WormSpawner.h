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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
