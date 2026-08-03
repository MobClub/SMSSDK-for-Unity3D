using System;
using UnityEngine;
using System.Collections;

namespace cn.SMSSDK.Unity {
	public class SMSSDK : MonoBehaviour {
		public static string version = "2.0.0";

		private ISMSSDK smssdkImpl;
		private SMSSDKHandler handler;

		void Awake() {
			#if UNITY_ANDROID
				smssdkImpl = new SMSSDKAndroidImpl(gameObject);
			#elif UNITY_IPHONE
				smssdkImpl = new iOSSMSSDKImpl(gameObject);
			#endif
		}

		/// <summary>
		/// Calls the back.
		/// <summary>
		private void _callBack(string callBackData) {
			if (callBackData == null) {
				return;
			}

			Hashtable res = (Hashtable)MiniJSON.jsonDecode(callBackData);
			SMSSDKResponse response = new SMSSDKResponse(res);
			switch (response.status) {
				case 1: {
					if (handler != null) handler.onComplete(response.action, response.res);
					break;
				}
				case 2: {
					if (handler != null) handler.onError(response.action, response.res);
					break;
				}
			}
		}

		/// <summary>
		/// 上传隐私协议状态
		/// <summary>
		public void submitPolicyGrantResult(bool isAgree) {
			if (smssdkImpl != null) {
				smssdkImpl.submitPolicyGrantResult(isAgree);
			}
		}

		/// <summary>
		/// Sets the handler.
		/// <summary>
		public void setHandler(SMSSDKHandler handler) {
			this.handler = handler;
		}

		/// <summary>
		/// SDK版本号
		/// <summary>
		public void getVersion() {
			if (smssdkImpl != null) {
				smssdkImpl.getVersion();
			}
		}

		/// <summary>
		/// 获取区号
		/// <summary>
		public void getSupportedCountryCode() {
			if (smssdkImpl != null) {
				smssdkImpl.getSupportedCountryCode();
			}
		}

		/// <summary>
		/// 获取验证码
		/// <summary>
		public void getCode(CodeType method, string phoneNumber, string zone, string tmpCode) {
			if (smssdkImpl != null) {
				smssdkImpl.getCode(method, phoneNumber, zone, tmpCode);
			}
		}

		/// <summary>
		/// 提交验证码
		/// <summary>
		public void commitCode(string phoneNumber, string zone, string code) {
			if (smssdkImpl != null) {
				smssdkImpl.commitCode(phoneNumber, zone, code);
			}
		}
	}
}
