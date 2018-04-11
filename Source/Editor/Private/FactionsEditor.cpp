// Copyright 2015-2018 Piperift. All Rights Reserved.

#include "FactionsEditor.h"

#include "Kismet2/KismetEditorUtilities.h"

#include "FactionCustomization.h"


DEFINE_LOG_CATEGORY(LogFactionsEditor)
 
#define LOCTEXT_NAMESPACE "FactionsEditor"
 
void FFactionsEditorModule::StartupModule()
{
    UE_LOG(LogFactionsEditor, Log, TEXT("FactionsEditor: Log Started"));

    RegisterPropertyTypeCustomizations();
    PrepareAutoGeneratedDefaultEvents();
}
 
void FFactionsEditorModule::ShutdownModule()
{
    UE_LOG(LogFactionsEditor, Log, TEXT("FactionsEditor: Log Ended"));

    CreatedAssetTypeActions.Empty();

    // Cleanup all information for auto generated default event nodes by this module
    FKismetEditorUtilities::UnregisterAutoBlueprintNodeCreation(this);
}


void FFactionsEditorModule::RegisterPropertyTypeCustomizations()
{
    RegisterCustomPropertyTypeLayout("Faction", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FFactionCustomization::MakeInstance));
}

void FFactionsEditorModule::PrepareAutoGeneratedDefaultEvents()
{}


void FFactionsEditorModule::RegisterCustomPropertyTypeLayout(FName PropertyTypeName, FOnGetPropertyTypeCustomizationInstance PropertyTypeLayoutDelegate)
{
    check(PropertyTypeName != NAME_None);

    static FName PropertyEditor("PropertyEditor");
    FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PropertyEditor);
    PropertyModule.RegisterCustomPropertyTypeLayout(PropertyTypeName, PropertyTypeLayoutDelegate);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_GAME_MODULE(FFactionsEditorModule, FactionsEditor);