// Copyright 2020. All rights reserved. A game prototype by CodingRook.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChronoRPGPlayerController.generated.h"

/**
 * asdfsadfadfd cab tiy see this in good speed? can you follow this in real time speed? is the question hjhjhjhjhjhjhjhjhjhjhjh
 */
UCLASS()
class CHRONORPG_API AChronoRPGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Default constructor
	AChronoRPGPlayerController();
	
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* ControlledPawn) override;

	// Getter for the reference of this controller's character
	UFUNCTION(BlueprintPure, Category = "Character")
	class AChronoRPGCharacter* GetMyChronoRPGCharacter() const { return MyChronoRPGCharacter; }

	void Jump();
	void StopJumping();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Add input (affecting Yaw) to the Controller's ControlRotation, if it is a local PlayerController.
	 * This value is multiplied by the PlayerController's InputYawScale value.
	 * @param Val Amount to add to Yaw. This value is multiplied by the PlayerController's InputYawScale value.
	 * @see PlayerController::InputYawScale
	 */
	void Turn(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Add input (affecting Pitch) to the Controller's ControlRotation, if it is a local PlayerController.
	 * This value is multiplied by the PlayerController's InputPitchScale value.
	 * @param Val Amount to add to Pitch. This value is multiplied by the PlayerController's InputPitchScale value.
	 * @see PlayerController::InputPitchScale
	 */
	void LookUp(float Value);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);
	
	// Interaction execution
	void Interact();

	// Drop Props
	void DropProp();

private:
	// Store pointer to this controller's character
	AChronoRPGCharacter* MyChronoRPGCharacter;
};
