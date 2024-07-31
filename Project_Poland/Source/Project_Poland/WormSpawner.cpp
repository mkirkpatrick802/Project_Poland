include "WormSpawner.h"

AWormSpawner::AWormSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWormSpawner::BeginPlay()
{
	Super::BeginPlay();	
}

void AWormSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

