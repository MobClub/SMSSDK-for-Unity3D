using System;
using System.Collections;

namespace cn.SMSSDK.Unity
{
	public interface SMSSDKHandler
	{
		/// <summary>
		/// The success callback method.
		/// <summary>
		void onComplete(int code, object result);

		/// <summary>
		/// he failure callback method.
		/// <summary>
		void onError(int code, object result);

	}
}