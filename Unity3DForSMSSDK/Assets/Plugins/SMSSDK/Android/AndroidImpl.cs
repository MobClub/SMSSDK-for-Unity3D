using System;
using System.Collections;
using UnityEngine; 

namespace cn.SMSSDK.Unity
{
	#if UNITY_ANDROID
	public class AndroidImpl : SMSSDKInterface
	{
	private AndroidJavaObject smssdk;

	public AndroidImpl (GameObject go) 
	{
	Debug.Log("AndroidImpl  ===>>>  AndroidImpl" );
	try{
	smssdk = new AndroidJavaObject("cn.smssdk.unity3d.SMSSDKUtils", go.name, "_callBack");
	} catch(Exception e) {
	Console.WriteLine("{0} Exception caught.", e);
	}
	}

	public override void init(string appKey, string appsecret, bool isWarn)
	{
	Debug.Log("AndroidImpl ==>>> InitSDK ===" + appKey + ";" + appsecret);
	if(smssdk != null) {
	smssdk.Call("init", appKey,appsecret,isWarn);
	}
	}

	public override void getCode(CodeType type, string phoneNumber, string zone)
	{
	Debug.Log("AndroidImpl ==>>> getCode " + zone + ";" + phoneNumber);
	if(smssdk != null) {
	if(type == CodeType.TextCode) {
	smssdk.Call("getTextCode", zone, phoneNumber);
	} else if(type == CodeType.VoiceCode) {
	smssdk.Call("getVoiceCode", zone, phoneNumber);
	}
	}
	}


	public override void commitCode(string zone, string phoneNumber, string code)
	{
	Debug.Log("AndroidImpl ==>>> commitCode" + zone + ";" + phoneNumber + ";" + code);
	if(smssdk != null) {
	smssdk.Call("submitCode", zone,phoneNumber,code);
	}
	}

	public override void getSupportedCountry()
	{
	Debug.Log("AndroidImpl ==>>> getSupportedCountry ===");
	if(smssdk != null) {
	smssdk.Call("getSupportedCountry");
	}
	}

	public override void getFriends()
	{
	Debug.Log("AndroidImpl ==>>> getFriends");
	if(smssdk != null) {
	smssdk.Call("getFriendsInApp");
	}
	}

	public override void submitUserInfo(UserInfo userInfo)
	{
	Debug.Log("AndroidImpl ==>>> submitUserInfo ===");
	if(smssdk != null) {
	smssdk.Call("submitUserInfo", userInfo.uid,userInfo.nickName,userInfo.avatar,userInfo.zone,userInfo.phoneNumber);
	}
	}

	public override void getVersion()
	{
	Debug.Log("AndroidImpl ==>>> getVersion");
	if(smssdk != null) {
	smssdk.Call("getVersion");
	}
	}

	public override void enableWarn(bool isWarn)
	{
	Debug.Log("AndroidImpl ==>>> enableWarn");
	if(smssdk != null) {
	smssdk.Call("enableWarn", isWarn);
	}
	}

	}
	#endif
}
