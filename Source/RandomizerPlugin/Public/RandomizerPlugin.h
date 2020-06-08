// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class RANDOMIZERPLUGIN_API FRandomizerPluginModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
};
