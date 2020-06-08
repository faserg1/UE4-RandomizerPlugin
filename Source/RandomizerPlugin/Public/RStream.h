#pragma once

#include "UObject/NoExportTypes.h"
#include "RStream.generated.h"

UCLASS(notplaceable, Transient, BlueprintType)
class RANDOMIZERPLUGIN_API URStream : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	~URStream();

	struct RStreamData *GetData();

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	void SetSeedByDefault();

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	void SetSeedByTime();

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf, HideSelfPin), Category="Math|Randomizer")
	void SetSeed(int seed);
private:
	// UE4 sucks with pimpl via std::unique_ptr
	struct RStreamData *data;
};
