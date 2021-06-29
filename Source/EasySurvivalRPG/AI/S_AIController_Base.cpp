// Easy Systems


#include "S_AIController_Base.h"

AS_AIController_Base::AS_AIController_Base()
{
	S_TransformComponent = CreateDefaultSubobject<USceneComponent>(TEXT("S_TransformComponent"));
	S_PathFollowingComponent = CreateDefaultSubobject<UPathFollowingComponent>(TEXT("S_PathFollowingComponent"));
	S_ActionsComp = CreateDefaultSubobject<UPawnActionsComponent>(TEXT("S_ActionsComp"));
}


void AS_AIController_Base::S_EventBeginPlay_Implementation()
{

}