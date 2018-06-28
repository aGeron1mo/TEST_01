// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectReporter.h"


// Sets default values for this component's properties
UObjectReporter::UObjectReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UObjectReporter::BeginPlay()
{
	Super::BeginPlay();

	// ...
	AActor* Object = GetOwner();
	UE_LOG(LogTemp, Warning, TEXT("OBJECT REPORTER NAME - %s"), *Object->GetName());
	
}


// Called every frame
void UObjectReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

