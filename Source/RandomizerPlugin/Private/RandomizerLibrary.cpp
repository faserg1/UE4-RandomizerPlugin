#include "RandomizerLibrary.h"
#include "RStream.h"
#include "Internal/RStreamData.h"
#include <limits>
#include <random>

URandomizerLibrary::URandomizerLibrary(class FObjectInitializer const &objInit) : Super(objInit)
{

}

int URandomizerLibrary::NextRandomInt(URStream *rstream)
{
    return NextRandomIntInRange(rstream, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

int URandomizerLibrary::NextRandomIntInRange(URStream *rstream, int min, int max)
{
    std::uniform_int_distribution<int> d(min, max);
    return d(rstream->GetData()->engine);
}

float URandomizerLibrary::NextRandomFloat(URStream *rstream)
{
    return NextRandomFloatInRange(rstream, std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
}

float URandomizerLibrary::NextRandomFloatInRange(URStream *rstream, float min, float max)
{
    std::uniform_real_distribution<float> d(min, max);
    return d(rstream->GetData()->engine);
}


FVector URandomizerLibrary::NextRandomVector(class URStream *rStream)
{
    return NextRandomVectorInFlatRange(rStream, std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
}

FVector URandomizerLibrary::NextRandomVectorInRange(class URStream *rStream, FVector min, FVector max)
{
    std::uniform_real_distribution<float> dx(min.X, max.X), dy(min.Y, max.Y), dz(min.Z, max.Z);
    return FVector(dx(rStream->GetData()->engine), dy(rStream->GetData()->engine), dz(rStream->GetData()->engine));
}

FVector URandomizerLibrary::NextRandomVectorInFlatRange(class URStream *rStream, float min, float max)
{
    std::uniform_real_distribution<float> d(min, max);
    return FVector(d(rStream->GetData()->engine), d(rStream->GetData()->engine), d(rStream->GetData()->engine));
}

FVector URandomizerLibrary::NextRandomVectorCubic(class URStream *rStream)
{
    return NextRandomVectorCubicInRange(rStream, std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
}

FVector URandomizerLibrary::NextRandomVectorCubicInRange(class URStream *rStream, float min, float max)
{
    std::uniform_real_distribution<float> d(min, max);
    float temp = d(rStream->GetData()->engine);
    return FVector(temp, temp, temp);
}

URStream *URandomizerLibrary::CreateRStream()
{
    return NewObject<URStream>();
}
