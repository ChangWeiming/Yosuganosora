// Easy Systems


#include "Character/Character_Undead.h"
//#include "EasySurvivalRPG.h"

#include "GeneratedCodeHelpers.h"
#include "Runtime/Engine/Classes/Engine/SimpleConstructionScript.h"
#include "Runtime/Engine/Classes/Engine/SCS_Node.h"
//#include "BP_FoliageCheckerComponent.h"
//#include "BP_FootstepComponent.h"
#include "Runtime/Engine/Classes/Sound/SoundCue.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceConstant.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineBaseTypes.h"
#include "Runtime/Engine/Classes/Engine/AssetUserData.h"
#include "Runtime/Engine/Public/ComponentInstanceDataCache.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphPin.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/NetSerialization.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/Info.h"
#include "Runtime/Engine/Classes/Components/BillboardComponent.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/Engine/Classes/Engine/StreamableRenderAsset.h"
#include "Runtime/Engine/Classes/Engine/TextureDefines.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_AssetUserData.h"
#include "Runtime/Engine/Classes/GameFramework/LocalMessage.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineReplStructs.h"
#include "Runtime/CoreUObject/Public/UObject/CoreOnline.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Volume.h"
#include "Runtime/Engine/Classes/Engine/Brush.h"
#include "Runtime/Engine/Classes/Components/BrushComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Runtime/Engine/Classes/PhysicsEngine/AggregateGeom.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphereElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ShapeElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BoxElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphylElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConvexElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/TaperedCapsuleElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetupEnums.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterial.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsSettingsEnums.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialPropertyBase.h"
#include "Runtime/Engine/Classes/Vehicles/TireType.h"
#include "Runtime/Engine/Classes/Engine/DataAsset.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodyInstance.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationData.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationDataInterface.h"
#include "Runtime/AIModule/Classes/AIResourceInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/PathFollowingAgentInterface.h"
#include "Runtime/AIModule/Classes/BrainComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardData.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig.h"
#include "Runtime/AIModule/Classes/Perception/AISense.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "Runtime/AIModule/Classes/AISubsystem.h"
#include "Runtime/AIModule/Classes/AISystem.h"
#include "Runtime/Engine/Classes/AI/AISystemBase.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeManager.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTCompositeNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTNode.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskOwnerInterface.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTTaskNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTService.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTAuxiliaryNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTDecorator.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryManager.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQuery.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryOption.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryGenerator.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryNode.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/Items/EnvQueryItemType.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryTest.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryTypes.h"
#include "Runtime/AIModule/Classes/DataProviders/AIDataProvider.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryContext.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryInstanceBlueprintWrapper.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EQSQueryResultSourceInterface.h"
#include "Runtime/AIModule/Classes/Blueprint/AIAsyncTaskBlueprintProxy.h"
#include "Runtime/AIModule/Classes/AITypes.h"
#include "Runtime/AIModule/Classes/HotSpots/AIHotSpotManager.h"
#include "Runtime/AIModule/Classes/Navigation/NavLocalGridManager.h"
#include "Runtime/AIModule/Classes/Perception/AISenseEvent.h"
#include "Runtime/AIModule/Classes/Actions/PawnActionsComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnAction.h"
#include "Runtime/GameplayTasks/Classes/GameplayTasksComponent.h"
#include "Runtime/GameplayTasks/Classes/GameplayTask.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskResource.h"
#include "Runtime/NavigationSystem/Public/NavFilters/NavigationQueryFilter.h"
#include "Runtime/NavigationSystem/Public/NavAreas/NavArea.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreaBase.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionListenerInterface.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"
#include "Runtime/Engine/Public/VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "Runtime/Engine/Classes/GameFramework/EngineMessage.h"
#include "Runtime/Engine/Classes/GameFramework/DamageType.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationAvoidanceTypes.h"
#include "Runtime/Engine/Classes/GameFramework/RootMotionSource.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Public/AI/RVOAvoidanceInterface.h"
#include "Runtime/Engine/Classes/Interfaces/NetworkPredictionInterface.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Animation/AnimCompositeBase.h"
#include "Runtime/Engine/Classes/Animation/AnimSequenceBase.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSocket.h"
#include "Runtime/Engine/Classes/Animation/SmartName.h"
#include "Runtime/Engine/Classes/Animation/BlendProfile.h"
#include "Runtime/Engine/Public/BoneContainer.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_PreviewMeshProvider.h"
#include "Runtime/Engine/Classes/Animation/AnimMetaData.h"
#include "Runtime/Engine/Public/Animation/AnimTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimLinkableElement.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "Runtime/Engine/Public/Animation/AnimCurveTypes.h"
#include "Runtime/Engine/Classes/Curves/RichCurve.h"
#include "Runtime/Engine/Classes/Curves/RealCurve.h"
#include "Runtime/Engine/Classes/Curves/IndexedCurve.h"
#include "Runtime/Engine/Classes/Curves/KeyHandle.h"
#include "Runtime/Engine/Public/AlphaBlend.h"
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "Runtime/Engine/Classes/Curves/CurveBase.h"
#include "Runtime/Engine/Classes/Animation/AnimEnums.h"
#include "Runtime/Engine/Classes/Animation/TimeStretchCurve.h"
#include "Runtime/Engine/Classes/Engine/Player.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstDirector.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInst.h"
#include "Runtime/Engine/Classes/GameFramework/HUD.h"
#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "Runtime/Engine/Classes/Debug/ReporterGraph.h"
#include "Runtime/Engine/Classes/Debug/ReporterBase.h"
#include "Runtime/Engine/Classes/Engine/Font.h"
#include "Runtime/Engine/Classes/Engine/FontImportOptions.h"
#include "Runtime/SlateCore/Public/Fonts/CompositeFont.h"
#include "Runtime/SlateCore/Public/Fonts/FontProviderInterface.h"
#include "Runtime/Engine/Classes/Materials/MaterialInterface.h"
#include "Runtime/Engine/Classes/Engine/SubsurfaceProfile.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Public/MaterialShared.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpression.h"
#include "Runtime/Engine/Classes/Materials/MaterialFunction.h"
#include "Runtime/Engine/Classes/Materials/MaterialFunctionInterface.h"
#include "Runtime/Engine/Classes/Materials/MaterialParameterCollection.h"
#include "Runtime/Engine/Classes/Engine/BlendableInterface.h"
#include "Runtime/Engine/Classes/GameFramework/DebugTextInfo.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Runtime/Engine/Classes/Engine/TextureCube.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier.h"
#include "Runtime/Engine/Classes/Particles/EmitterCameraLensEffectBase.h"
#include "Runtime/Engine/Classes/Particles/Emitter.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleEmitter.h"
#include "Runtime/Engine/Public/ParticleHelper.h"
#include "Runtime/Engine/Classes/Particles/ParticleLODLevel.h"
#include "Runtime/Engine/Classes/Particles/ParticleModuleRequired.h"
#include "Runtime/Engine/Classes/Particles/ParticleModule.h"
#include "Runtime/Engine/Classes/Particles/ParticleSpriteEmitter.h"
#include "Runtime/Engine/Classes/Distributions/DistributionFloat.h"
#include "Runtime/Engine/Classes/Distributions/Distribution.h"
#include "Runtime/Engine/Classes/Particles/SubUVAnimation.h"
#include "Runtime/Engine/Classes/Particles/TypeData/ParticleModuleTypeDataBase.h"
#include "Runtime/Engine/Classes/Particles/Spawn/ParticleModuleSpawn.h"
#include "Runtime/Engine/Classes/Particles/Spawn/ParticleModuleSpawnBase.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventGenerator.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventBase.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventSendToGame.h"
#include "Runtime/Engine/Classes/Particles/Orbit/ParticleModuleOrbit.h"
#include "Runtime/Engine/Classes/Particles/Orbit/ParticleModuleOrbitBase.h"
#include "Runtime/Engine/Classes/Distributions/DistributionVector.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventReceiverBase.h"
#include "Runtime/Engine/Classes/Engine/InterpCurveEdSetup.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemReplay.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/MaterialLayersFunctions.h"
#include "Runtime/Engine/Classes/VT/RuntimeVirtualTexture.h"
#include "Runtime/Engine/Public/VT/RuntimeVirtualTextureEnum.h"
#include "Runtime/Engine/Classes/VT/RuntimeVirtualTextureStreamingProxy.h"
#include "Runtime/Engine/Classes/VT/VirtualTextureBuildSettings.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceBasePropertyOverrides.h"
#include "Runtime/Engine/Public/StaticParameterSet.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier_CameraShake.h"
#include "Runtime/Engine/Classes/Camera/CameraShake.h"
#include "Runtime/Engine/Classes/Camera/CameraAnim.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroup.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrack.h"
#include "Runtime/Engine/Classes/Camera/CameraAnimInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstMove.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CheatManager.h"
#include "Runtime/Engine/Classes/Engine/DebugCameraController.h"
#include "Runtime/Engine/Classes/Components/DrawFrustumComponent.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackEffect.h"
#include "Runtime/Engine/Classes/Engine/NetConnection.h"
#include "Runtime/Engine/Classes/Engine/ChildConnection.h"
#include "Runtime/Engine/Classes/Engine/PackageMapClient.h"
#include "Runtime/Engine/Classes/Engine/NetDriver.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Engine/Level.h"
#include "Runtime/Engine/Classes/Components/ModelComponent.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_CollisionDataProvider.h"
#include "Runtime/Engine/Classes/Engine/LevelActorContainer.h"
#include "Runtime/Engine/Classes/Engine/LevelScriptActor.h"
#include "Runtime/Engine/Classes/Engine/NavigationObjectBase.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationDataChunk.h"
#include "Runtime/Engine/Classes/Engine/MapBuildDataRegistry.h"
#include "Runtime/Engine/Classes/GameFramework/WorldSettings.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemConfig.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPhysicsVolume.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsCollisionHandler.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Runtime/Engine/Classes/Sound/SoundClass.h"
#include "Runtime/Engine/Classes/Sound/SoundMix.h"
#include "Runtime/Engine/Public/IAudioExtensionPlugin.h"
#include "Runtime/Engine/Classes/Sound/SoundConcurrency.h"
#include "Runtime/Engine/Classes/Sound/SoundAttenuation.h"
#include "Runtime/Engine/Classes/Engine/Attenuation.h"
#include "Runtime/Engine/Classes/Sound/SoundSubmix.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectSubmix.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectPreset.h"
#include "Runtime/Engine/Public/IAmbisonicsMixer.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Runtime/AudioPlatformConfiguration/Public/AudioCompressionSettings.h"
#include "Runtime/Engine/Classes/Sound/SoundGroups.h"
#include "Runtime/Engine/Classes/Engine/CurveTable.h"
#include "Runtime/Engine/Classes/Sound/SoundSubmixSend.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectSource.h"
#include "Runtime/Engine/Classes/Sound/SoundSourceBusSend.h"
#include "Runtime/Engine/Classes/Sound/SoundSourceBus.h"
#include "Runtime/Engine/Classes/GameFramework/GameModeBase.h"
#include "Runtime/Engine/Classes/GameFramework/GameSession.h"
#include "Runtime/Engine/Classes/GameFramework/GameStateBase.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawn.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPawn.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Public/PerPlatformProperties.h"
#include "Runtime/Engine/Public/Components.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshSocket.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavCollisionBase.h"
#include "Runtime/StaticMeshDescription/Public/StaticMeshDescription.h"
#include "Runtime/MeshDescription/Public/MeshDescriptionBase.h"
#include "Runtime/MeshDescription/Public/MeshTypes.h"
#include "Runtime/Engine/Classes/Engine/TextureStreamingTypes.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawnMovement.h"
#include "Runtime/Engine/Classes/Engine/ServerStatReplicator.h"
#include "Runtime/Engine/Classes/GameFramework/GameNetworkManager.h"
#include "Runtime/Engine/Classes/Sound/AudioVolume.h"
#include "Runtime/Engine/Classes/Sound/ReverbEffect.h"
#include "Runtime/Engine/Classes/Engine/BookmarkBase.h"
//#include "DmgTypeBP_Environmental.h"
#include "Runtime/Engine/Classes/Engine/BookMark.h"
#include "Runtime/Engine/Classes/Components/LineBatchComponent.h"
#include "Runtime/Engine/Classes/Engine/LevelStreaming.h"
#include "Runtime/Engine/Classes/Engine/LevelStreamingVolume.h"
#include "Runtime/Engine/Classes/Engine/DemoNetDriver.h"
#include "Runtime/Engine/Classes/Particles/ParticleEventManager.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemBase.h"
#include "Runtime/Engine/Classes/AI/Navigation/AvoidanceManager.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/Engine/Classes/Engine/ScriptViewportClient.h"
#include "Runtime/Engine/Classes/Engine/Console.h"
#include "Runtime/Engine/Classes/Engine/DebugDisplayProperty.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/GameFramework/GameUserSettings.h"
#include "Runtime/Engine/Classes/Engine/AssetManager.h"
#include "Runtime/Engine/Classes/Engine/EngineCustomTimeStep.h"
#include "Runtime/Engine/Classes/Engine/TimecodeProvider.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineSession.h"
#include "Runtime/Engine/Classes/Materials/MaterialParameterCollectionInstance.h"
#include "Runtime/Engine/Classes/Engine/WorldComposition.h"
#include "Runtime/Engine/Classes/Particles/WorldPSCPool.h"
#include "Runtime/Engine/Classes/Engine/Channel.h"
#include "Runtime/Engine/Classes/Engine/ReplicationDriver.h"
#include "Runtime/Engine/Classes/GameFramework/TouchInterface.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Widget.h"
#include "Runtime/UMG/Public/Components/Visual.h"
#include "Runtime/UMG/Public/Components/PanelSlot.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/SlateWrapperTypes.h"
#include "Runtime/UMG/Public/Slate/WidgetTransform.h"
#include "Runtime/SlateCore/Public/Layout/Clipping.h"
#include "Runtime/UMG/Public/Blueprint/WidgetNavigation.h"
#include "Runtime/SlateCore/Public/Input/NavigationReply.h"
#include "Runtime/SlateCore/Public/Types/SlateEnums.h"
#include "Runtime/SlateCore/Public/Layout/FlowDirection.h"
#include "Runtime/UMG/Public/Binding/PropertyBinding.h"
#include "Runtime/UMG/Public/Binding/DynamicPropertyPath.h"
#include "Runtime/PropertyPath/Public/PropertyPathHelpers.h"
#include "Runtime/SlateCore/Public/Layout/Geometry.h"
#include "Runtime/SlateCore/Public/Input/Events.h"
#include "Runtime/SlateCore/Public/Styling/SlateColor.h"
#include "Runtime/SlateCore/Public/Styling/SlateBrush.h"
#include "Runtime/SlateCore/Public/Layout/Margin.h"
#include "Runtime/SlateCore/Public/Styling/SlateTypes.h"
#include "Runtime/UMG/Public/Animation/UMGSequencePlayer.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimation.h"
#include "Runtime/MovieScene/Public/MovieSceneSequence.h"
#include "Runtime/MovieScene/Public/MovieSceneSignedObject.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTemplate.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTrackIdentifier.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTrack.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSegment.h"
#include "Runtime/MovieScene/Public/MovieSceneTrack.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvalTemplate.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTrackImplementation.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationField.h"
#include "Runtime/MovieScene/Public/MovieSceneFrameMigration.h"
#include "Runtime/MovieScene/Public/MovieSceneSequenceID.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationKey.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceHierarchy.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceTransform.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceInstanceData.h"
#include "Runtime/MovieScene/Public/MovieSceneSection.h"
#include "Runtime/MovieScene/Public/MovieSceneObjectBindingID.h"
#include "Runtime/MovieScene/Public/MovieScene.h"
#include "Runtime/MovieScene/Public/MovieSceneSpawnable.h"
#include "Runtime/MovieScene/Public/MovieScenePossessable.h"
#include "Runtime/MovieScene/Public/MovieSceneBinding.h"
#include "Runtime/MovieScene/Public/MovieSceneFwd.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimationBinding.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/Slate/Public/Widgets/Layout/Anchors.h"
#include "Runtime/UMG/Public/Blueprint/DragDropOperation.h"
#include "Runtime/UMG/Public/Components/NamedSlotInterface.h"
#include "Runtime/Engine/Classes/Haptics/HapticFeedbackEffect_Base.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h"
#include "Runtime/Engine/Classes/Matinee/MatineeActor.h"
#include "Runtime/Engine/Classes/Matinee/InterpData.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupDirector.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "Runtime/Engine/Public/SceneTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Public/SkeletalMeshReductionSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionCodec.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionCodec_CompressedRichCurve.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsAsset.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicalAnimationComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintTemplate.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintInstance.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintTypes.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintDrives.h"
#include "Runtime/Engine/Classes/EditorFramework/ThumbnailInfo.h"
#include "Runtime/Engine/Public/Animation/NodeMappingContainer.h"
#include "Runtime/Engine/Public/Animation/NodeMappingProviderInterface.h"
#include "Runtime/Engine/Classes/Animation/MorphTarget.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Public/Animation/AnimNotifyQueue.h"
#include "Runtime/Engine/Public/Animation/PoseSnapshot.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingAssetBase.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSampling.h"
#include "Runtime/Engine/Public/Animation/SkinWeightProfile.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshLODSettings.h"
#include "Runtime/Engine/Classes/Engine/Blueprint.h"
#include "Runtime/Engine/Classes/Engine/BlueprintCore.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Engine/TimelineTemplate.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Curves/CurveVector.h"
#include "Runtime/Engine/Classes/Curves/CurveLinearColor.h"
#include "Runtime/Engine/Classes/Engine/InheritableComponentHandler.h"
#include "Runtime/Engine/Classes/Animation/AnimBlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Engine/DynamicBlueprintBinding.h"
#include "Runtime/Engine/Classes/Animation/AnimStateMachineTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimClassInterface.h"
#include "Runtime/Engine/Classes/Animation/AnimNodeBase.h"
#include "Runtime/Engine/Public/SingleAnimationPlayData.h"
//#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingSimulationFactory.h"
//#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingSimulationInteractor.h"
//#include "Runtime/ClothingSystemRuntimeNv/Public/ClothingSimulationFactoryNv.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "Runtime/AIModule/Classes/Perception/AISense_Sight.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Hearing.h"
#include "Runtime/AIModule/Classes/Perception/AISense_Hearing.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Damage.h"
#include "Runtime/AIModule/Classes/Perception/AISense_Damage.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"
#include "Runtime/Engine/Classes/Engine/TextureRenderTarget.h"
//#include "UI_WorldCharacterState.h"
//#include "BP_AttributesComponent.h"
#include "Runtime/NavigationSystem/Public/NavAreas/NavArea_Obstacle.h"
#include "Runtime/NavigationSystem/Public/NavigationInvokerComponent.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetArrayLibrary.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/Engine/ComponentDelegateBinding.h"
//#include "E_InteractionState.h"
//#include "STR_Attribute.h"
#include "Runtime/Engine/Classes/Sound/DialogueWave.h"
#include "Runtime/Engine/Classes/Sound/DialogueVoice.h"
#include "Runtime/Engine/Classes/Sound/DialogueSoundWaveProxy.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackAttenuation.h"
#include "Runtime/Engine/Classes/Components/ForceFeedbackComponent.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SaveGame.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStaticsTypes.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"
#include "Runtime/Engine/Public/Slate/SGameLayerManager.h"
#include "Runtime/SlateCore/Public/Rendering/RenderingCommon.h"
#include "Runtime/Engine/Classes/Slate/SlateBrushAsset.h"
//#include "E_Fraction.h"
//#include "STR_AttributeSettings.h"
//#include "STR_AttributeDependence.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Kismet/DataTableFunctionLibrary.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
//#include "E_AttributeValueType.h"
//#include "BP_GameLibrary.h"
#include "Runtime/GameplayTags/Classes/BlueprintGameplayTagLibrary.h"
#include "Runtime/GameplayTags/Classes/GameplayTagAssetInterface.h"
//#include "BPI_Player.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"
//#include "STR_DialogueReplyHandle.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/NavigationSystem/Public/NavigationPath.h"
//#include "BP_PatrolPoint.h"
//#include "BPI_Character.h"
//#include "STR_Relationships.h"
//#include "BPI_GameInstance.h"
//#include "E_AutosaveMode.h"
#include "Runtime/Engine/Classes/Kismet/KismetTextLibrary.h"
//#include "E_FloatingTextType.h"
//#include "BPI_InteractionObject.h"
//#include "BP_Mark.h"
#include "Item/ItemsLibrary.h"
//#include "BP_LootContainer.h"
#include "Item/STR_ItemInstance.h"
//#include "E_WeaponType.h"
#include "Item/Item.h"
//#include "STR_CostValue.h"
//#include "BP_Ability_Base.h"
//#include "BP_CriticalDamage.h"
//#include "ABP_Undead.h"
//#include "BP_AIController_Base.h"
#include "Runtime/Engine/Classes/Components/ArrowComponent.h"

// Sets default values

ACharacter_Undead::ACharacter_Undead(const FObjectInitializer& ObjectInitializer)
{
	Super();
	
}

void ACharacter_Undead::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	if (FoliageCheckerComponent)
	{
		FoliageCheckerComponent->CreationMethod = EComponentCreationMethod::Native;
	}
	if (FootstepComponent)
	{
		FootstepComponent->CreationMethod = EComponentCreationMethod::Native;
	}
	if (HeadMesh)
	{
		HeadMesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PantsMesh)
	{
		PantsMesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (HandsMesh)
	{
		HandsMesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (BodyMesh)
	{
		BodyMesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (WeaponMesh)
	{
		WeaponMesh->CreationMethod = EComponentCreationMethod::Native;
	}
}

/*
void ACharacter_Undead::UserConstructionScript()
{
	Super::UserConstructionScript();

	if (::IsValid(BodyMesh))
	{
		BodyMesh->USkinnedMeshComponent::SetMasterPoseComponent((*(AccessPrivateProperty<USkeletalMeshComponent* >((this), ACharacter::__PPO__Mesh()))), false);
	}
	if (::IsValid(HeadMesh))
	{
		HeadMesh->USkinnedMeshComponent::SetMasterPoseComponent((*(AccessPrivateProperty<USkeletalMeshComponent* >((this), ACharacter::__PPO__Mesh()))), false);
	}
	if (::IsValid(PantsMesh))
	{
		PantsMesh->USkinnedMeshComponent::SetMasterPoseComponent((*(AccessPrivateProperty<USkeletalMeshComponent* >((this), ACharacter::__PPO__Mesh()))), false);
	}
	if (::IsValid(HandsMesh))
	{
		HandsMesh->USkinnedMeshComponent::SetMasterPoseComponent((*(AccessPrivateProperty<USkeletalMeshComponent* >((this), ACharacter::__PPO__Mesh()))), false);
	}

	if (AActor::HasAuthority())
	{
		if (ShouldRandomizeWeapon)
			RandomizeWeapon();
		else
			UpdateWeapon();

		if (ShouldRandomizeMeshes)
			RandomizeMeshes();
		else
			UpdateMeshes();
	}
}
*/

void ACharacter_Undead::UpdateMeshes()
{
	AActor::FlushNetDormancy();
	FCustomThunkTemplates::Array_Get(BodyMeshes, BodyMeshIndex, /*out*/ BodySkeletalMesh);
	OnRep_BodySkeletalMesh();

	AActor::FlushNetDormancy();
	FCustomThunkTemplates::Array_Get(HeadMeshes, HeadMeshIndex, /*out*/ HeadSkeletalMesh);
	OnRep_HeadSkeletalMesh();

	AActor::FlushNetDormancy();
	FCustomThunkTemplates::Array_Get(PantsMeshes, PantsMeshIndex, /*out*/ PantsSkeletalMesh);
	OnRep_PantsSkeletalMesh();

	AActor::FlushNetDormancy();
	FCustomThunkTemplates::Array_Get(HandsMeshes, HandsMeshIndex, /*out*/ HandsSkeletalMesh);
	OnRep_HandsSkeletalMesh();

	AActor::FlushNetDormancy();
	FCustomThunkTemplates::Array_Get(MeshMaterials, MaterialIndex, /*out*/ SkeletalMeshMaterial);
	OnRep_SkeletalMeshMaterial();
}

void ACharacter_Undead::RandomizeMeshes()
{
	int Array_Length;
	AActor::FlushNetDormancy();
	Array_Length = FCustomThunkTemplates::Array_Length(BodyMeshes);
	Array_Length = UKismetMathLibrary::Subtract_IntInt(Array_Length, 1);
	BodyMeshIndex = UKismetMathLibrary::RandomIntegerInRange(0, Array_Length);

	AActor::FlushNetDormancy();
	Array_Length = FCustomThunkTemplates::Array_Length(HeadMeshes);
	Array_Length = UKismetMathLibrary::Subtract_IntInt(Array_Length, 1);
	HeadMeshIndex = UKismetMathLibrary::RandomIntegerInRange(0, Array_Length);

	AActor::FlushNetDormancy();
	Array_Length = FCustomThunkTemplates::Array_Length(PantsMeshes);
	Array_Length = UKismetMathLibrary::Subtract_IntInt(Array_Length, 1);
	PantsMeshIndex = UKismetMathLibrary::RandomIntegerInRange(0, Array_Length);

	AActor::FlushNetDormancy();
	Array_Length = FCustomThunkTemplates::Array_Length(HandsMeshes);
	Array_Length = UKismetMathLibrary::Subtract_IntInt(Array_Length, 1);
	HandsMeshIndex = UKismetMathLibrary::RandomIntegerInRange(0, Array_Length);

	AActor::FlushNetDormancy();
	Array_Length = FCustomThunkTemplates::Array_Length(MeshMaterials);
	Array_Length = UKismetMathLibrary::Subtract_IntInt(Array_Length, 1);
	MaterialIndex = UKismetMathLibrary::RandomIntegerInRange(0, Array_Length);

	UpdateMeshes();
}

void ACharacter_Undead::DisableRandomizing()
{
	ShouldRandomizeMeshes = false; 
	ShouldRandomizeWeapon = false;
}

void ACharacter_Undead::RandomizeWeapon()
{
	int Array_Length;
	int LocalWeaponIndex = 0;
	FSTR_ItemInstance ItemInstance;
	FSTR_ItemData Item;
	bool IsWeapon = true;
	//E_WeaponType WeaponType;

	AActor::FlushNetDormancy();
	Array_Length = FCustomThunkTemplates::Array_Length(WeaponItems);
	Array_Length = UKismetMathLibrary::Subtract_IntInt(Array_Length, 1);
	LocalWeaponIndex = UKismetMathLibrary::RandomIntegerInRange(0, Array_Length);

	UItemsLibrary::MakeItemInstance(WeaponItems[LocalWeaponIndex].ItemHandle, this, /*out*/ ItemInstance);
	UItemsLibrary::MakeItem(ItemInstance, 1, -1, -1.000000, -1.000000, this, /*out*/ Item);
	//UItemsLibrary::ItemIsWeapon(Item, this, /*out*/ IsWeapon, /*out*/ WeaponType);
	if (IsWeapon)
	{
		AActor::FlushNetDormancy(); 
		WeaponIndex = LocalWeaponIndex;
		UpdateWeapon();
	}
}

void ACharacter_Undead::UpdateWeapon()
{
	//TArray<FSTR_Attribute> EquipmentAttributes{};
	FSTR_ItemInstance ItemInstance;
	FSTR_ItemData Item;
	bool IsWeapon = true;
	//bool Success;
	//E_WeaponType WeaponType;

	UItemsLibrary::MakeItemInstance(WeaponItems[WeaponIndex].ItemHandle, this, /*out*/ ItemInstance);
	UItemsLibrary::MakeItem(ItemInstance, 1, -1, -1.000000, -1.000000, this, /*out*/ Item);
	//UItemsLibrary::ItemIsWeapon(Item, this, /*out*/ IsWeapon, /*out*/ WeaponType);
	if (IsWeapon)
	{
		WeaponItemData = Item;

		AActor::FlushNetDormancy();
		//UItemsLibrary::GetItemUsableMesh(WeaponItemData, this, /*out*/ Success, /*out*/ WeaponStaticMesh);
		OnRep_WeaponStaticMesh();

		//UItemsLibrary::GetItemEquipmentAttributes(WeaponItemData, this, /*out*/ EquipmentAttributes);
		//if (::IsValid(AttributesComponent))
		{
		//	AttributesComponent->UpdateSelectedItemAttributes(/*out*/ EquipmentAttributes);
		}
	}
}

void ACharacter_Undead::CreateMark()
{
	FText text{};
	FName name{};
	FTransform Transform{};
	AActor* BeginDeferredActorSpawnFromClass{};
	ABP_Mark_C* FinishSpawningActor{};
	Transform = AActor::GetTransform();
	//BeginDeferredActorSpawnFromClass_ReturnValue = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ABP_Mark_C::StaticClass(),GetTransform_ReturnValue, ESpawnActorCollisionHandlingMethod::Undefined, ((AActor*)nullptr));
	name = FName(TEXT("Undead"));
	UKismetSystemLibrary::SetNamePropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("MarkTag")), name);
	text = FTextStringHelper::CreateFromBuffer(
		TEXT("NSLOCTEXT(\"[DF5D457B4CBA6CBFFB03C8BDE86F0139]\", \"C5996F61489174E5FF7F2FBDB53FC605\", \"Undead\")"));
	UKismetSystemLibrary::SetTextPropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("MarkName")), text);
	UKismetSystemLibrary::SetObjectPropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("Icon")), CastChecked<UObject>(CastChecked<UDynamicClass>(ACharacter_Undead::StaticClass())->UsedAssets[29], ECastCheckedType::NullAllowed));
	UKismetSystemLibrary::SetBoolPropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("ShowWorldMark")), false);
	UKismetSystemLibrary::SetBoolPropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("ShowMapMark")), false);
	UKismetSystemLibrary::SetBoolPropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("ShowDistance")), false);
	UKismetSystemLibrary::SetObjectPropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("TargetActor")), this);
	UKismetSystemLibrary::SetFloatPropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("TargetHeight")), 200.000000);
	UKismetSystemLibrary::SetBoolPropertyByName(BeginDeferredActorSpawnFromClass, FName(TEXT("RotateMark")), true);
	Transform = AActor::GetTransform();
	FinishSpawningActor = CastChecked<ABP_Mark_C>(UGameplayStatics::FinishSpawningActor(BeginDeferredActorSpawnFromClass, Transform), ECastCheckedType::NullAllowed);
	Mark = FinishSpawningActor;
}

void ACharacter_Undead::TraceDealDamage()
{
	FRotator ActorRotation;
	FVector ActorLocation;
	FVector ForwardVector;
	FVector EndActorLocation;

	if (IsLocallyControlled())
	{
		ActorRotation = AActor::K2_GetActorRotation();
		ActorLocation = AActor::K2_GetActorLocation();
		ForwardVector = UKismetMathLibrary::GetForwardVector(ActorRotation);
		ForwardVector = UKismetMathLibrary::Multiply_VectorFloat(ForwardVector, 1000.000000);
		EndActorLocation = UKismetMathLibrary::Add_VectorVector(ActorLocation, ForwardVector);
		TraceDealDamagexxServerx(ActorLocation, EndActorLocation);
	}
}

void ACharacter_Undead::PlayItemSound_Server(FName SoundName)
{
	FVector ActorLocation;
	USoundBase* ItemSound;
//	UItemsLibrary::GetItemSound(WeaponItemData, SoundName, this, /*out*/ ItemSound);
	if (UKismetSystemLibrary::IsValid(ItemSound))
	{
		ActorLocation = AActor::K2_GetActorLocation();
		PlaySoundAtLocationxxMulticastx(ItemSound, ActorLocation);
	}
}

void ACharacter_Undead::PlaySound(FName SoundName)
{
	if (IsLocallyControlled())
	{
		PlayItemSoundxxServerx(SoundName);
	}
}
/*
void ACharacter_Undead::DeleteMark()
{
	if (UKismetSystemLibrary::IsValid(Mark))
	{
		Mark->K2_DestroyActor();
	}
}
*/

void ACharacter_Undead::OnRep_BodySkeletalMesh()
{
	if (::IsValid(BodyMesh))
	{
		BodyMesh->SetSkeletalMesh(BodySkeletalMesh, true);
	}
}

void ACharacter_Undead::OnRep_HeadSkeletalMesh()
{
	if (::IsValid(HeadMesh))
	{
		HeadMesh->SetSkeletalMesh(HeadSkeletalMesh, true);
	}
}

void ACharacter_Undead::OnRep_PantsSkeletalMesh()
{
	if (::IsValid(PantsMesh))
	{
		PantsMesh->SetSkeletalMesh(PantsSkeletalMesh, true);
	}
}

void ACharacter_Undead::OnRep_HandsSkeletalMesh()
{
	if (::IsValid(HandsMesh))
	{
		HandsMesh->SetSkeletalMesh(HandsSkeletalMesh, true);
	}
}

void ACharacter_Undead::OnRep_SkeletalMeshMaterial()
{
	if (::IsValid((*(AccessPrivateProperty<USkeletalMeshComponent* >((this), ACharacter::__PPO__Mesh())))))
	{
		(*(AccessPrivateProperty<USkeletalMeshComponent* >((this), ACharacter::__PPO__Mesh())))->SetMaterialByName(FName(TEXT("MI_Character_Undead")), SkeletalMeshMaterial);
	}
	if (::IsValid(HeadMesh))
	{
		HeadMesh->SetMaterialByName(FName(TEXT("MI_Character_Undead")), SkeletalMeshMaterial);
	}
	if (::IsValid(PantsMesh))
	{
		PantsMesh->SetMaterialByName(FName(TEXT("MI_Character_Undead")), SkeletalMeshMaterial);
	}
	if (::IsValid(HandsMesh))
	{
		HandsMesh->SetMaterialByName(FName(TEXT("MI_Character_Undead")), SkeletalMeshMaterial);
	}
	if (::IsValid(BodyMesh))
	{
		BodyMesh->SetMaterialByName(FName(TEXT("MI_Character_Undead")), SkeletalMeshMaterial);
	}
}

void ACharacter_Undead::OnRep_WeaponStaticMesh()
{
	if (::IsValid(WeaponMesh))
	{
		WeaponMesh->SetStaticMesh(WeaponStaticMesh);
	}
}

//void ACharacter_Undead::InitCharacter(/*out*/ bool& Success)
//{
	//Super::InitCharacter(/*out*/Success);
	/*
	CreateMark();
	if (IsAlive != true)
	{
		EnableRagdoll();
		DeleteMark();
	}

	Success = true;
}*/

//void ACharacter_Undead::UpdateTick(float DeltaSeconds, /*out*/ bool& Success)
//{
	//Super::UpdateTick(DeltaSeconds, /*out*/ Success)

//}


// Called when the game starts or when spawned
void ACharacter_Undead::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacter_Undead::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter_Undead::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

