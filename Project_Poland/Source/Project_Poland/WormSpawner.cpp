#include "WormSpawner.h"

#include "Kismet/KismetSystemLibrary.h"

#define ECC_Landscape ECC_GameTraceChannel1

AWormSpawner::AWormSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWormSpawner::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	DrawDebug();
}

void AWormSpawner::BeginPlay()
{
	Super::BeginPlay();

	if(GetWorld())
		GetWorld()->GetTimerManager().SetTimer(WormSpawnerTimer, this, &AWormSpawner::SpawnWorm, 5, true, 0);
}

void AWormSpawner::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(EnableDebug)
		DrawDebug();
}

void AWormSpawner::DrawDebug() const
{
	if(GetWorld())
	{
		DrawDebugSphere(GetWorld(), GetActorLocation(), SpawnRadius, 12, FColor::Red, false, 0, 0, 2);
	}
}

void AWormSpawner::SpawnWorm() const
{
	// Generate a random angle between 0 and 2π
	const float Angle = FMath::RandRange(0.0f, 2 * PI);

	// Generate a random radius within the circle's radius
	const float RandomRadius = FMath::RandRange(0.0f, SpawnRadius);
	
	// Convert polar coordinates to Cartesian coordinates
	const float X = RandomRadius * FMath::Cos(Angle) + GetActorLocation().X;
	const float Y = RandomRadius * FMath::Sin(Angle) + GetActorLocation().Y;
	
	const FVector Start = FVector(X,Y,4000);
	const FVector End = FVector(X,Y,-1000);
	if (FHitResult HitResult; GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Landscape))
	{
		if (HitResult.GetActor())
			UE_LOG(LogTemp, Warning, TEXT("Trace hit actor: %s"), *HitResult.GetActor()->GetName());

		DrawDebugSphere(GetWorld(), HitResult.Location, 30, 12, FColor::Blue, true, -1, 0, 2);
	}
}

