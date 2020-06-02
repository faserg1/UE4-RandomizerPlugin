#include "RStream.h"
#include "Internal/RStreamData.h"
#include <chrono>

URStream::URStream(class FObjectInitializer const &objInit) : Super(objInit), data(new RStreamData)
{
}

URStream::~URStream()
{
    delete data;
}

RStreamData *URStream::GetData()
{
    return data;
}

void URStream::SetSeedByDefault()
{
    data->engine.seed();
}

void URStream::SetSeedByTime()
{
    data->engine.seed(std::chrono::steady_clock::now().time_since_epoch().count());
}

void URStream::SetSeed(int seed)
{
    data->engine.seed(seed);
}