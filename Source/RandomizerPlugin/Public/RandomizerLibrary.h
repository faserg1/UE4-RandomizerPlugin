#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RandomizerLibrary.generated.h"

UCLASS()
class URandomizerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static int NextRandomInt(class URStream *rStream);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static int NextRandomIntInRange(class URStream *rStream, int min, int max);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static float NextRandomFloat(class URStream *rStream);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static float NextRandomFloatInRange(class URStream *rStream, float min, float max);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FVector NextRandomVector(class URStream *rStream);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FVector NextRandomVectorInRange(class URStream *rStream, FVector min, FVector max);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FVector NextRandomVectorInFlatRange(class URStream *rStream, float min, float max);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FVector NextRandomVectorCubic(class URStream *rStream);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FVector NextRandomVectorCubicInRange(class URStream *rStream, float min, float max);
	
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static class URStream *CreateRStream();
};
