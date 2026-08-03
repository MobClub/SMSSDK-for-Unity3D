using System;
using System.Collections;

namespace cn.SMSSDK.Unity
{
	public class SMSSDKResponse {
		public int status;
		public int action;
		public object res;

		public SMSSDKResponse(Hashtable dict) {
			if (dict != null || dict.Count != 0) {
				this.status = Convert.ToInt32(dict["status"]);
				this.action = Convert.ToInt32(dict["action"]);
				this.res = dict["res"];
			}
		}


	}
}