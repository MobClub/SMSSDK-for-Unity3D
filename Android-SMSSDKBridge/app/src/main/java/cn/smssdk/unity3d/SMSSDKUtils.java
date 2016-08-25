package cn.smssdk.unity3d;

import android.content.Context;
import android.os.Looper;
import android.text.TextUtils;
import android.util.Log;

import com.mob.tools.utils.Hashon;
import com.unity3d.player.UnityPlayer;

import java.util.HashMap;

import cn.smssdk.EventHandler;
import cn.smssdk.SMSSDK;
import cn.smssdk.utils.SPHelper;

public class SMSSDKUtils {
    private static boolean DEBUG = true;

    private static Context context;
    private static String u3dGameObject;
    private static String u3dCallback;

    public SMSSDKUtils(final String gameObject,final String callback) {
        if (DEBUG) {
            Log.e("Unity","SMSSDKUtils.prepare");
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
        if(Looper.myLooper() == null) {
            Looper.prepare();
        }
        if (TextUtils.isEmpty(appKey) || TextUtils.isEmpty(appSecret))
            return;
        SMSSDK.initSDK(context,appKey,appSecret,isWarn);
        EventHandler handler = new EventHandler(){
            public void afterEvent(int event, int result, Object data) {
                String resp = JavaTools.javaActionResToCS(event, result, data);
                UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, resp);
            }
        };
        SMSSDK.registerEventHandler(handler);
    }

    public void getTextCode(String zone, String phone) {
        SMSSDK.getVerificationCode(zone,phone);
    }

    public void getVoiceCode(String zone, String phone) {
        SMSSDK.getVoiceVerifyCode(zone,phone);
    }

    public void submitCode(String zone, String phone, String code) {
        SMSSDK.submitVerificationCode(zone,phone,code);
    }

    public void getSupportedCountry() {
        SMSSDK.getSupportedCountries();
    }

    public void getFriendsInApp() {
        SMSSDK.getFriendsInApp();
    }

    public void submitUserInfo(String uid, String nickname, String avatar,
                               String country, String phone) {
        SMSSDK.submitUserInfo(uid,nickname,avatar,country,phone);
    }

    public void getVersion() {
        String version =  SMSSDK.getVersion();
        HashMap<String, Object> map = new HashMap<String, Object>();
        map.put("action", 6);
        map.put("status", 1);
        map.put("res", version);
        Hashon hashon = new Hashon();
        UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, hashon.fromHashMap(map));;
    }

    public void enableWarn(boolean isWarn) {
        SPHelper.getInstance(context).setWarnWhenReadContact(isWarn);
    }
}
