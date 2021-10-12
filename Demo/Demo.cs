using UnityEngine;
using System.Collections;
using System;
using cn.SMSSDK.Unity;

public class Demo : MonoBehaviour, SMSSDKHandler
{

    // Use this for initialization
    public GUISkin demoSkin;
    public SMSSDK smssdk;
    //public UserInfo userInfo;
    public AndroidJavaClass UnityPlayer;
    public AndroidJavaObject activity;
    //please add your phone number
    private string phone = "";
    private string zone = "86";
    private string tempCode = "";
    private string code = "";
    private string result = null;


    void Start()
    {
        Debug.Log("[SMSSDK]Demo  ===>>>  Start");
        smssdk = gameObject.GetComponent<SMSSDK>();
        smssdk.setHandler(this);
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            Application.Quit();
        }
    }


    void OnGUI()
    {
        GUI.skin = demoSkin;

        float scale = 1.0f;
        if (Application.platform == RuntimePlatform.IPhonePlayer)
        {
            scale = Screen.width / 320;
        }
        else if (Application.platform == RuntimePlatform.Android)
        {
            if (Screen.orientation == ScreenOrientation.Portrait)
            {
                scale = Screen.width / 320;
            }
            else
            {
                scale = Screen.height / 320;
            }
        }

        float btnWidth = 200 * scale;
        float btnHeight = 30 * scale;
        float btnTop = 50 * scale;
        GUI.skin.button.fontSize = Convert.ToInt32(14 * scale);
        GUI.skin.label.fontSize = Convert.ToInt32(14 * scale);
        GUI.skin.label.alignment = TextAnchor.MiddleCenter;
        GUI.skin.textField.fontSize = Convert.ToInt32(14 * scale);
        GUI.skin.textField.alignment = TextAnchor.MiddleCenter;

        float labelWidth = 60 * scale;
        GUI.Label(new Rect((Screen.width - btnWidth) / 2, btnTop + 5, labelWidth, btnHeight), "手机号");

        phone = GUI.TextField(new Rect((Screen.width - btnWidth) / 2 + labelWidth, btnTop, btnWidth - labelWidth, btnHeight), phone);

        btnTop += btnHeight + 10 * scale;

        GUI.Label(new Rect((Screen.width - btnWidth) / 2, btnTop + 5, labelWidth, btnHeight), "区号");

        zone = GUI.TextField(new Rect((Screen.width - btnWidth) / 2 + labelWidth, btnTop, btnWidth - labelWidth, btnHeight), zone);

        btnTop += btnHeight + 10 * scale;

        GUI.Label(new Rect((Screen.width - btnWidth) / 2, btnTop + 5, labelWidth, btnHeight), "验证码");

        code = GUI.TextField(new Rect((Screen.width - btnWidth) / 2 + labelWidth, btnTop, btnWidth - labelWidth, btnHeight), code);

        btnTop += btnHeight + 10 * scale;

        if (GUI.Button(new Rect((Screen.width - btnWidth) / 2, btnTop, btnWidth, btnHeight), "同意隐私协议"))
        {
            smssdk.submitPolicyGrantResult(true);
        }

        btnTop += btnHeight + 10 * scale;

        if (GUI.Button(new Rect((Screen.width - btnWidth) / 2, btnTop, btnWidth, btnHeight), "获取短信验证码"))
        {
            smssdk.getCode(CodeType.TextCode, phone, zone, tempCode);
        }

        btnTop += btnHeight + 10 * scale;
        if (GUI.Button(new Rect((Screen.width - btnWidth) / 2, btnTop, btnWidth, btnHeight), "提交验证码"))
        {
            smssdk.commitCode (phone, zone, code);
        }

        btnTop += btnHeight + 10 * scale;
        if (GUI.Button(new Rect((Screen.width - btnWidth) / 2, btnTop, btnWidth, btnHeight), "获取语音验证码"))
        {
            smssdk.getCode (CodeType.VoiceCode, phone, zone, tempCode);
        }

        btnTop += btnHeight + 10 * scale;
        if (GUI.Button(new Rect((Screen.width - btnWidth) / 2, btnTop, btnWidth, btnHeight), "获取国家区号"))
        {
            smssdk.getSupportedCountryCode ();
        }


        btnTop += btnHeight + 10 * scale;
        if (GUI.Button(new Rect((Screen.width - btnWidth) / 2, btnTop, btnWidth, btnHeight), "获取SDK版本号"))
        {

            smssdk.getVersion ();
        }


        btnTop += btnHeight + 10 * scale;
        if (GUI.Button(new Rect((Screen.width - btnWidth) / 2, btnTop, btnWidth, btnHeight), "获取本机号认证token"))
        {

            smssdk.getMobileAuthToken();
        }

        btnTop += btnHeight + 10 * scale;
        if (GUI.Button(new Rect((Screen.width - btnWidth) / 2, btnTop, btnWidth, btnHeight), "本机号认证"))
        {
            if (phone == "")
            {
                showDialog("fail VerifyMobile\n" + "请先输入手机号");
            }
            smssdk.verifyMobileWithPhone(phone);
        }


        //展示回调结果
        btnTop += btnHeight + 10 * scale;
        GUIStyle style = new GUIStyle();
        style.normal.textColor = new Color(1, 0, 0);   //字体颜色
                                                       // style.fontSize = 30;
        style.fontSize = (int)(20 * scale);       //字体大小
        GUI.Label(new Rect(20, btnTop, Screen.width - 20 - 20, Screen.height - btnTop), result, style);
    }

	public void onComplete(int action, object resp)
		{
			ActionType act = (ActionType)action;
			if (resp != null){
				result = resp.ToString();
			}if (act == ActionType.GetCode) {
				string responseString = (string)resp;
				Debug.Log ("isSmart :" + responseString);
				showDialog("success GetCode\n" + responseString);
			} else if (act == ActionType.GetVersion) {
				string version = (string)resp;
				Debug.Log ("version :" + version);
				print ("Demo*version*********" + version);
				showDialog("success GetVersion\n" + version);
			} else if (act == ActionType.GetSupportedCountries) {

				string responseString = (string)resp;
				Debug.Log ("zoneString :" + responseString);
				showDialog("success GetSupportedCountries\n" + responseString);
			}  else if (act == ActionType.CommitCode) {

				string responseString = (string)resp;
				Debug.Log ("commitCodeString :" + responseString);
				showDialog("success CommitCode\n" + responseString);
			}  else if (act == ActionType.ShowRegisterView) {

				string responseString = (string)resp;
				Debug.Log ("showRegisterView :" + responseString);
				showDialog("success ShowRegisterView\n" + responseString);
			}else if (act == ActionType.SubmitPolicyGrantResult){
				showDialog("success SubmitPolicyGrantResult\n" + "隐私协议提交成功");
			}
			else if (act == ActionType.GetMobileAuth)
			{
				showDialog("success GetMobileAuthToken\n" + "获取本机号认证token成功");
			}
			else if (act == ActionType.VerifyPhoneNumber)
			{
				showDialog("success VerifyMobile\n" + "本机号认证成功");
			}
	}

		public void onError(int action, object resp)
		{
			Debug.Log("Error :" + resp);
			result = resp.ToString();
			showDialog("onError:\n" + result);
			print ("OnError ******resp"+resp);
		}


    public void showDialog(String msg)
    {
#if UNITY_ANDROID
			UnityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
			activity = UnityPlayer.GetStatic<AndroidJavaObject>("currentActivity");
			//DialogOnClickListener confirmListener = new DialogOnClickListener();
			//confirmListener.onClickDelegate = onConfirm;

			//DialogOnClickListener cancelListener = new DialogOnClickListener();
			//cancelListener.onClickDelegate = onCancel;

			AlertDialog alertDialog = new AlertDialog(activity);
			alertDialog.setTitle("返回结果");
			alertDialog.setMessage(msg);
			alertDialog.setPositiveButton("确定", null);
			//alertDialog.setNegativeButton("取消", cancelListener);//如果不需要取消后的事件处理，把cancelListener换成new DialogOnClickListener ()就行，上面也不用声明cancelListener
			alertDialog.create();
			alertDialog.show();
#endif
    }

}
