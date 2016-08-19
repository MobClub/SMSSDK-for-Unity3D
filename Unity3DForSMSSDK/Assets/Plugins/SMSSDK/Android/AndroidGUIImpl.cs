﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

namespace cn.SMSSDK.Unity
{
	#if UNITY_ANDROID
	class AndroidGUIImpl : SMSSDKGUIInterface
	{
	private AndroidJavaObject smssdkgui;

	public AndroidGUIImpl(GameObject go)
	{
	Debug.Log("AndroidImpl  ===>>>  AndroidImpl");
	try
	{
	smssdkgui = new AndroidJavaObject("cn.smssdk.unity3d.SMSSDKGUI", go.name, "_callBack");
	}
	catch (Exception e)
	{
	Console.WriteLine("{0} Exception caught.", e);
	}
	}

	public override void init(string appKey, string appsecret, bool isWarn)
	{
	Debug.Log("AndroidImpl ==>>> InitSDK ===" + appKey + ";" + appsecret);
	if (smssdkgui != null)
	{
	smssdkgui.Call("init", appKey, appsecret, isWarn);
	}
	}

	public override void showContactsPage()
	{
	if (smssdkgui != null)
	{
	smssdkgui.Call("showContactsPage");
	}
	}

	public override void showRegisterPage(CodeType getCodeMethodType)
	{
	if (smssdkgui != null)
	{
	smssdkgui.Call("showRegisterPage");
	}
	}
	}
	#endif
}