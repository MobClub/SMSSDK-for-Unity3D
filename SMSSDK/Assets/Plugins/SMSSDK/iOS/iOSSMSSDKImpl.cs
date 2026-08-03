using System;
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace cn.SMSSDK.Unity
{
#if UNITY_IPHONE || UNITY_IOS
	public class iOSSMSSDKImpl : ISMSSDK {
		private string _callbackObjectName = "Default ID";

		[DllImport("__Internal")]
		private static extern void __iosGetversion(string observer);

		[DllImport("__Internal")]
		private static extern void __iosGetsupportedcountrycode(string observer);

		[DllImport("__Internal")]
		private static extern void __iosGetcode(CodeType method, string phoneNumber, string zone, string tmpCode, string observer);

		[DllImport("__Internal")]
		private static extern void __iosCommitcode(string phoneNumber, string zone, string tmpCode, string observer);

		[DllImport("__Internal")]
		private static extern void __iosSubmitpolicygrantresult(bool isAgree, string observer);

		public iOSSMSSDKImpl(GameObject go) {
			try {
				_callbackObjectName = go.name;
			} catch(Exception e) {
				Console.WriteLine("{0} Exception caught.", e);
			}
		}

		public override void getVersion() {
			__iosGetversion(_callbackObjectName);
		}

		public override void getSupportedCountryCode() {
			__iosGetsupportedcountrycode(_callbackObjectName);
		}

		public override void getCode(CodeType method, string phoneNumber, string zone, string tmpCode) {
			__iosGetcode(method, phoneNumber, zone, tmpCode, _callbackObjectName);
		}

		public override void commitCode(string phoneNumber, string zone, string tmpCode) {
			__iosCommitcode(phoneNumber, zone, tmpCode, _callbackObjectName);
		}

		public override void submitPolicyGrantResult(bool isAgree) {
			__iosSubmitpolicygrantresult(isAgree, _callbackObjectName);
		}
	}
#endif
}
