using System;
using System.Collections;

namespace cn.SMSSDK.Unity
{
	public enum CodeType {
		TextCode = 0,
		VoiceCode = 1
	}

	public enum ActionType {
		GetCode = 1,
		CommitCode = 2,
		GetSupportedCountries = 3,
		GetVersion = 6,
		ShowRegisterView = 7,
		SubmitPolicyGrantResult = 10
	}
}
