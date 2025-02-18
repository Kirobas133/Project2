// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Amplitude = 70.0;
	Frequency = 4.0;

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = this->GetActorLocation();
	
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::SinMovement() {
  float NewZLocation =
      sin(Frequency * GetWorld()->TimeSeconds) * Amplitude + InitialLocation.Z;
  FVector NewLocation = InitialLocation;
  NewLocation.Z = NewZLocation;
 
  this->SetActorLocation(NewLocation);
}

