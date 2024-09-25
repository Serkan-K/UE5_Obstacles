// Fill out your copyright notice in the Description page of Project Settings.


#include "Moving_Platform.h"

// Sets default values
AMoving_Platform::AMoving_Platform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned -------------------------- Start
void AMoving_Platform::BeginPlay()
{
	Super::BeginPlay();

	//_vector.X = _int_first;
	initial_pos = GetActorLocation();

	FString _string = GetName();

	UE_LOG(LogTemp, Warning, TEXT(" Moved Distance:  %f"), moved_dist);
	UE_LOG(LogTemp, Display, TEXT("Obje: %s"), *_string);

}

// Called every frame ---------------------------------------------------- Update
void AMoving_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move_Platform(DeltaTime);
	Rotate_Platform(DeltaTime);

}









void AMoving_Platform::Move_Platform(float DeltaTime_)
{
	if (Should_Platform_return())
	{
		FVector move_Dir = platform_Velocity.GetSafeNormal();
		initial_pos += move_Dir * moved_dist;

		SetActorLocation(initial_pos);
		platform_Velocity = -platform_Velocity;
	}
	else
	{
		FVector current_Loc = GetActorLocation();
		current_Loc += platform_Velocity * DeltaTime_;

		SetActorLocation(current_Loc);
	}
}

void AMoving_Platform::Rotate_Platform(float Delta_Time)
{
	//	UE_LOG(LogTemp, Display, TEXT("%s Rotating "), *GetName());

	AddActorLocalRotation(Rotation_velocity * Delta_Time);
}





bool AMoving_Platform::Should_Platform_return() const
{
	return Get_Distance_Moved() > moved_dist;
}

float AMoving_Platform::Get_Distance_Moved() const
{
	return FVector::Dist(initial_pos, GetActorLocation());
}