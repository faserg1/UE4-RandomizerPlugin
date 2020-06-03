#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RandomizerLibrary.generated.h"

UCLASS()
class URandomizerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static int32 NextRandomInt(class URStream *rStream);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static int32 NextRandomIntInRange(class URStream *rStream, int32 min, int32 max);

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
	static FIntVector NextRandomIntVector(class URStream *rStream);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FIntVector NextRandomIntVectorInRange(class URStream *rStream, FIntVector min, FIntVector max);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FIntVector NextRandomIntVectorInFlatRange(class URStream *rStream, int32 min, int32 max);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FIntVector NextRandomIntVectorCubic(class URStream *rStream);
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static FIntVector NextRandomIntVectorCubicInRange(class URStream *rStream, int32 min, int32 max);
	
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	static class URStream *CreateRStream();
};
