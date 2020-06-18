#include "RandomizerLibrary.h"
#include "RStream.h"
#include "Internal/RStreamData.h"
#include <limits>
#include <random>

URandomizerLibrary::URandomizerLibrary(class FObjectInitializer const &objInit) : Super(objInit)
{

}

int32 URandomizerLibrary::NextRandomInt(URStream *rstream)
{
    return NextRandomIntInRange(rstream, std::numeric_limits<int32>::min(), std::numeric_limits<int32>::max());
}

int32 URandomizerLibrary::NextRandomIntInRange(URStream *rstream, int32 min, int32 max)
{
    std::uniform_int_distribution<int32> d(min, max);
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

FVector URandomizerLibrary::NextRandomVectorInRangeOrigin(class URStream *rStream, FVector origin, FVector boxSize)
{
    std::uniform_real_distribution<float>
        dx(origin.X - boxSize.X / 2.f, origin.X + boxSize.X / 2.f),
        dy(origin.Y - boxSize.Y / 2.f, origin.Y + boxSize.Y / 2.f),
        dz(origin.Z - boxSize.Z / 2.f, origin.Z + boxSize.Z / 2.f);
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


FIntVector URandomizerLibrary::NextRandomIntVector(class URStream *rStream)
{
    return NextRandomIntVectorInFlatRange(rStream, std::numeric_limits<int32>::min(), std::numeric_limits<int32>::max());
}

FIntVector URandomizerLibrary::NextRandomIntVectorInRange(class URStream *rStream, FIntVector min, FIntVector max)
{
    std::uniform_int_distribution<int32> dx(min.X, max.X), dy(min.Y, max.Y), dz(min.Z, max.Z);
    return FIntVector(dx(rStream->GetData()->engine), dy(rStream->GetData()->engine), dz(rStream->GetData()->engine));
}

FIntVector URandomizerLibrary::NextRandomIntVectorInRangeOrigin(class URStream *rStream, FIntVector origin, FIntVector boxSize)
{
    std::uniform_int_distribution<int32> 
        dx(origin.X - boxSize.X / 2.f, origin.X + boxSize.X / 2.f),
        dy(origin.Y - boxSize.Y / 2.f, origin.Y + boxSize.Y / 2.f),
        dz(origin.Z - boxSize.Z / 2.f, origin.Z + boxSize.Z / 2.f);
    return FIntVector(dx(rStream->GetData()->engine), dy(rStream->GetData()->engine), dz(rStream->GetData()->engine));
}

FIntVector URandomizerLibrary::NextRandomIntVectorInFlatRange(class URStream *rStream, int32 min, int32 max)
{
    std::uniform_int_distribution<int32> d(min, max);
    return FIntVector(d(rStream->GetData()->engine), d(rStream->GetData()->engine), d(rStream->GetData()->engine));
}

FIntVector URandomizerLibrary::NextRandomIntVectorCubic(class URStream *rStream)
{
    return NextRandomIntVectorCubicInRange(rStream, std::numeric_limits<int32>::min(), std::numeric_limits<int32>::max());
}

FIntVector URandomizerLibrary::NextRandomIntVectorCubicInRange(class URStream *rStream, int32 min, int32 max)
{
    std::uniform_int_distribution<int32> d(min, max);
    int32 temp = d(rStream->GetData()->engine);
    return FIntVector(temp, temp, temp);
}

URStream *URandomizerLibrary::CreateRStream()
{
    return NewObject<URStream>();
}
