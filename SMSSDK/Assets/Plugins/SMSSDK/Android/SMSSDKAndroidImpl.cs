using System;
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace cn.SMSSDK.Unity
{
#if UNITY_ANDROID
	public class SMSSDKAndroidImpl : ISMSSDK {
		private AndroidJavaObject sdk;

		public SMSSDKAndroidImpl(GameObject go) {
			try {
				sdk = new AndroidJavaObject("cn.smssdk.unity3d.SMSSDKUtils", go.name, "_callBack");
			} catch(Exception e) {
				Console.WriteLine("{0} Exception caught.", e);
			}
		}

		public override void getVersion() {
			sdk.Call("getVersion");
		}

		public override void getSupportedCountryCode() {
			sdk.Call("getSupportedCountryCode");
		}

		public override void getCode(CodeType method, string phoneNumber, string zone, string tmpCode) {
			sdk.Call("getCode", Convert.ToInt32(method), phoneNumber, zone, tmpCode);
		}

		public override void commitCode(string phoneNumber, string zone, string tmpCode) {
			sdk.Call("commitCode", phoneNumber, zone, tmpCode);
		}

		public override void submitPolicyGrantResult(bool isAgree) {
			sdk.Call("submitPolicyGrantResult", isAgree);
		}
	}
#endif
}
