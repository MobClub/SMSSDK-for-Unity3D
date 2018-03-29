package cn.smssdk.unity3d;

import android.content.Context;
import android.os.Looper;
import android.text.TextUtils;

import com.mob.MobSDK;
import com.unity3d.player.UnityPlayer;

import java.util.HashMap;

import cn.smssdk.EventHandler;
import cn.smssdk.SMSSDK;
import cn.smssdk.gui.ContactsPage;
import cn.smssdk.gui.RegisterPage;
import cn.smssdk.utils.SMSLog;

public class SMSSDKGUI {
    private static boolean DEBUG = true;

    private static Context context;
    private static String u3dGameObject;
    private static String u3dCallback;

    public SMSSDKGUI(final String gameObject,final String callback) {
        if (DEBUG) {
            System.out.println("SMSSDKGUI.prepare");
        }
        if (context == null) {
            context = UnityPlayer.currentActivity.getApplicationContext();
        }

        if(!TextUtils.isEmpty(gameObject)) {
            u3dGameObject = gameObject;
        }

        if(!TextUtils.isEmpty(callback)) {
            u3dCallback = callback;
        }
    }

    public void init(String appKey, String appSecret, boolean isWarn) {
        if (Looper.myLooper() == null)
            Looper.prepare();
        if (TextUtils.isEmpty(appKey) || TextUtils.isEmpty(appSecret))
            return;
		MobSDK.init(context, appKey, appSecret);
		if (isWarn) {
			SMSSDK.setAskPermisionOnReadContact(isWarn);
		}
    }

    //#if def{lang} == cn
    // 打开注册页面
    //#elif def{lang} == en
    // open the page of sign up
    //#endif
    public void showRegisterPage(String tempCode) {
		SMSLog.getInstance().d("=======>showRegisterPage. tempCode= " + tempCode);
        RegisterPage registerPage = new RegisterPage();
        EventHandler handler = new EventHandler(){
            public void afterEvent(int event, int result, Object data) {
                String resp = JavaTools.javaActionResToCS(event, result, data);
                UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, resp);
            }
        };
		registerPage.setTempCode(tempCode);
        registerPage.setRegisterCallback(handler);
        registerPage.show(context);
    }

    //#if def{lang} == cn
    // 打开通信录好友列表页面
    //#elif def{lang} == en
    // open the page of contacts
    //#endif
    public void showContactsPage() {
        ContactsPage contactsPage = new ContactsPage();
        contactsPage.show(context);
    }
}
