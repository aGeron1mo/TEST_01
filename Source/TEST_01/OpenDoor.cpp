// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Object = GetOwner();
	CurrentRorartor = Object->GetActorRotation();
	if (!OpenDoorTrigger) {
		UE_LOG(LogTemp, Error, TEXT("TRIGGER FOR OPEN DOOR NOT SETUP!!!"));
	}
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (OpenDoorTrigger) {
		if (OpenDoorTrigger->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn())
			&& !IsOPen) {OpenDoor();}
		if (!OpenDoorTrigger->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn())
			&& IsOPen) {CloseDoor();}
	}
}

void UOpenDoor::OpenDoor()
{
	UE_LOG(LogTemp, Warning, TEXT("Open Door"));
	IsOPen = true;
}

void UOpenDoor::CloseDoor()
{
	UE_LOG(LogTemp, Warning, TEXT("Close Door"));
	IsOPen = false;
}

