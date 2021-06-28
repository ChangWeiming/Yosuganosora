// Easy Systems

using UnrealBuildTool;
using System.Collections.Generic;

public class EasySurvivalRPGTarget : TargetRules
{
	public EasySurvivalRPGTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "EasySurvivalRPG" } );
	}
}
