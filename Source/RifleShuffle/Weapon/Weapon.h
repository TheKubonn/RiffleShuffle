// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWS_Initial UMETA(DisplayName = "Initial State"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),

	EWS_MAX UMETA(DisplayName = "DefaultMAX")
};

class USphereComponent;

UCLASS()
class RIFLESHUFFLE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	TObjectPtr <USkeletalMeshComponent> WeaponMesh;

	// Sphere for picking up a weapon
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	TObjectPtr <USphereComponent> AreaSphere;

	UPROPERTY(VisibleAnywhere)
	EWeaponState WeaponState;

public:	
	

};
