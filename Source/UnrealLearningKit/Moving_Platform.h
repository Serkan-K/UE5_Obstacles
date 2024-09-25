// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moving_Platform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMoving_Platform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMoving_Platform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;







private:

	//UPROPERTY(EditAnywhere)
	//int32 _int_first = 99;

	UPROPERTY(EditAnywhere, Category = "Moving values ")
	FVector platform_Velocity = FVector();
	FVector initial_pos;

	UPROPERTY(EditAnywhere, Category = "Moving values ")
	float moved_dist;


	UPROPERTY(EditAnywhere, Category = "Rotating Values")
	FRotator Rotation_velocity;



	/*UPROPERTY(VisibleAnywhere)
	float distance_moved;*/

	//UPROPERTY(EditAnywhere)
	//FVector _vector = FVector(2, -27440, 7820);



	void Move_Platform(float DeltaTime_);
	void Rotate_Platform(float Delta_Time);


	bool Should_Platform_return() const;
	float Get_Distance_Moved() const;

};
