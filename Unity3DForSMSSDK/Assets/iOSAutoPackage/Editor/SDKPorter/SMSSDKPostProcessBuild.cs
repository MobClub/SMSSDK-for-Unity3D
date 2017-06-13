using UnityEngine;
using UnityEditor;
using UnityEditor.Callbacks;
using System;
using System.Collections;
using System.Runtime.Serialization.Formatters.Binary;
using cn.sharesdk.unity3d.sdkporter;
using System.IO;

using cn.SMSSDK.Unity;

public static class SMSSDKPostProcessBuild
{
	//[PostProcessBuild]
	[PostProcessBuildAttribute(88)]
	public static void onPostProcessBuild(BuildTarget target,string targetPath)
	{
		string unityEditorAssetPath = Application.dataPath;

		if (target != BuildTarget.iOS) 
		{
			Debug.LogWarning ("Target is not iPhone. XCodePostProcess will not run");
			return;
		}

		XCProject project = new XCProject (targetPath);
		//var files = System.IO.Directory.GetFiles( unityEditorAssetPath, "*.projmods", System.IO.SearchOption.AllDirectories );
		var files = System.IO.Directory.GetFiles( unityEditorAssetPath + "/iOSAutoPackage/Editor/SDKPorter", "*.projmods", System.IO.SearchOption.AllDirectories);
		foreach( var file in files ) 
		{
			project.ApplyMod( file );
		}

		//如需要预配置Xocode中的URLScheme 和 白名单,请打开下两行代码,并自行配置相关键值
		string projPath = Path.GetFullPath (targetPath);
		EditInfoPlist (projPath);

		//Finally save the xcode project
		project.Save();
	}
	

	private static void EditInfoPlist(string projPath)
	{
		SMSSDKConfig theConfig;

		try
		{
			string filePath = Application.dataPath + "/iOSAutoPackage/Editor/SDKPorter/SMSSDKConfig.bin";
			BinaryFormatter formatter = new BinaryFormatter();
			Stream destream = new FileStream(filePath, FileMode.Open, FileAccess.Read, FileShare.Read);
			SMSSDKConfig config = (SMSSDKConfig)formatter.Deserialize(destream);
			destream.Flush();
			destream.Close();
			theConfig = config;
		}
		catch(Exception)
		{
			theConfig = new SMSSDKConfig ();
		}
						
		XCPlist plist = new XCPlist (projPath);

		string AppKey = @"<key>MOBAppkey</key> <string>" + theConfig.appKey + "</string>";
		string AppSecret = @"<key>MOBAppSecret</key> <string>" + theConfig.appSecret + "</string>";
		string ContactKey = @"<key>NSContactsUsageDescription</key> <string>开启通讯录好友功能</string>";
		//在plist里面增加一行
		plist.AddKey(AppKey);
		plist.AddKey(AppSecret);
		plist.AddKey(ContactKey);

		plist.Save();
	}


}