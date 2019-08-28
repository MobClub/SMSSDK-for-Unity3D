# SMSSDK-for-Unity3D
### This is UnityPackage base on SMSSDK([iOS](https://github.com/MobClub/SMSSDK-for-iOS),[Android](https://github.com/MobClub/SMSSDK-for-Android)).It supports an unity plugin to use SMSSDK. [中文官网](http://sms.mob.com/).
**supported original SMSSDK version:**

- Android - V3.3.3
- iOS - V3.2.3

**中文集成文档**

- [Android](http://wiki.mob.com/smssdk-android-for-unity3d/)
- [iOS](http://wiki.mob.com/smssdk-ios-for-unity3d/
)

- - - - -

## The notes for fast integration of Unity3D##

### *Integration of general part*

###### Step 1 : Download Unity3D tools of SMSSDK

Open Github and download SMSSDK-for-Unity3D section. Copy ”Unity3dForSMSSDK/Assets/Plugins”catalogue to Assets catalogue, or double click “SMSSDKPackageForUnity.unitypackage” to import relative documents.
Please notice that this operation could cover your original existed documents!

###### Step 2 : Add SMSSDK script and set the platforms’ information

Need to add SMSSDK to GameObject(Like Main Camera). Click”Add Component” from the right-hand side bar, and choose SMSSDK to be added.

![Snip20170527_10.png](http://upload-images.jianshu.io/upload_images/4131265-fe527878a87cd289.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

Config your appkey add appSecret. You could get that from our website when you register an account. 

###### Step 3 : Use SDK

1.Please import Name Space first :

> * using cn.smssdk.unity3d;

> * private SMSSDK smssdk;


2.Implements SMSSDKHandler and set it to SDK

add a class to implement SMSSDKHandler, then set it to SDK to handle callback

class Demo:SMSSDKHandler
....
smssdk.setHandler(demo);

3.now you can use SDK to do something

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
## For Android setting
If you don't want to  use this GUI, you can remove ShortMessageSDKGUI fold under Assets/Plugins/Android. This ShortMessageSDKGUI library is open source at [SMSSDK for Android](https://github.com/MobClub/SMSSDK-for-Android),you can modify whatever you want to do.

## For iOS setting
If you don't want to  use this GUI,you can note the methods in SMSSDK.cs,or do nothing in the method'body in the bridge file of your xcode project.

Until now,the Unity party is everything ok,the next you need to import the SMSSDK to the project.If your want to see the method of importting the SDK,please click here:[The Document of importting SMSSDK for iOS](https://github.com/MobClub/SMSSDK-for-iOS)

**Finally, if you have any other questions, please do not be hesitate to contact us:**

> * Customer Service QQ : 4006852216

> * or Skype:amber

More information About SMSSDK, please visit our website [Mob.com](http://www.mob.com


