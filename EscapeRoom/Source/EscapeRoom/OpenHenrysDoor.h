// Copy this and I'll stab you

#pragma once

#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "OpenHenrysDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UOpenHenrysDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenHenrysDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = 45.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	// Add close pressure plate
	UPROPERTY(EditAnywhere)
	ATriggerVolume* ClosePressurePlate;

	//UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens; // Remember pawn inherits from actor

};
