# SMSSDK-for-Unity3D
### This is a sample of SMSSDK for Unity3D.
**supported original SMSSDK version:**

- Android - V2.0.0
- iOS - V2.0.0

----------------------------------------------------

##The notes for fast integration of Unity3D##

### *Integration of general part*

###### Step 1 : Download Unity3D tools of SMSSDK

Open Github and download SMSSDK-for-Unity3D section. Copy ”Unity3dForSMSSDK/Assets/Plugins”catalogue to Assets catalogue, or double click “SMSSDKPackageForUnity.unitypackage” to import relative documents.
Please notice that this operation could cover your original existed documents!

###### Step 2 : Add SMSSDK script and set the platforms’ information

Need to add SMSSDK to GameObject(Like Main Camera). Click”Add Component” from the right-hand side bar, and choose SMSSDK to be added.
![image](http://wiki.mob.com/wp-content/uploads/2015/09/step1.jpg)

App Key on first line is appkey from SMSSDK. You could get that from our website when you register an account. 

###### Step 3 : Use SDK

1.Please import Name Space first :

        using cn.smssdk.unity3d;

        private SMSSDK smssdk;
        
2.Use your own  Appkey and AppSecret to initialize SDK

		smssdk = gameObject.GetComponent<SMSSDK>();
		smssdk.init("114d7a34cf7ea","678ff550d7328de446585757c4e5de3f",false);

3.Implements SMSSDKHandler and set it to SDK

add a class to implement SMSSDKHandler, then set it to SDK to handle callback

        class Demo:SMSSDKHandler
		....
		smssdk.setHandler(demo);

4.now you can use SDK to do something

		smssdk.getCode(CodeType.TextCode,"86","18688888888");
		smssdk.getFriends();

#### About Callback data
Some APIs will send data to your SMSSDKHandler.This callback data is a json string.You can use  any JSON library to handle it.The action is what API you call.

	onComplete(int action, object resp)
	onError(int action, object resp)

#### About GUI

This two APIs bellow is GUI APIs.

	showRegisterPage(CodeType getCodeMethodType)
	showContactsPage()

If you dont want to  use this GUI, you can remove ShortMessageSDKGUI fold under Assets/Plugins/Android. This ShortMessageSDKGUI library is open source at [SMSSDK for Android](https://github.com/MobClub/SMSSDK-for-Android),you can modify whatever you want to do.

**Finally, if you have any other questions, please do not be hesitate to contact us:**

- Customer Service QQ : 4006852216

- or Skype:amber

More information About SMSSDK, please visit our website [Mob.com](http://www.mob.com
