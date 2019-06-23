// Copy this and I'll stab you

#include "OpenHenrysDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenHenrysDoor::UOpenHenrysDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenHenrysDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
		
}

void UOpenHenrysDoor::OpenDoor()
{
	// Find Object
	AActor* Owner = GetOwner();

	// Create a rotator
	FRotator NewRotation = FRotator(0.0f, -35.0f, 0.0f);

	// Set the door rotatio
	Owner->SetActorRotation(NewRotation);
}

void UOpenHenrysDoor::CloseDoor()
{
	// Find Object
	AActor* Owner = GetOwner();

	// Rotate shut
	FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);

	// Set it rotation
	Owner->SetActorRotation(NewRotation);
}

// Called every frame
void UOpenHenrysDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger volume
	// If the ActorThatOpens is in the volume 
	// trigger OpenDoor()
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}		

	if (ClosePressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		CloseDoor();
	}
}

