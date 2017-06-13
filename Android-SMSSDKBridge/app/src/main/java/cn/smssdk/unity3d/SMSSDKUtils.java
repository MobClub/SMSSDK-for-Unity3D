package cn.smssdk.unity3d;

import android.content.Context;
import android.os.Bundle;
import android.os.Handler.Callback;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;

import com.mob.MobSDK;
import com.mob.tools.utils.Hashon;
import com.mob.tools.utils.UIHandler;
import com.unity3d.player.UnityPlayer;

import java.util.HashMap;

import cn.smssdk.EventHandler;
import cn.smssdk.SMSSDK;
import cn.smssdk.utils.SPHelper;

public class SMSSDKUtils implements Callback {
    private static final int MSG_INITSDK = 1;
    private static final int MSG_TEXT_CODE = 2;
    private static final int MSG_VOICE_CODE = 3;
    private static final int MSG_SUBMIT_CODE = 4;
    private static final int MSG_SUPPORTED_COUNTRY = 5;
    private static final int MSG_FRIENDS_INAPP = 6;
    private static final int MSG_SUBMIT_USERINFO = 7;
    private static final int MSG_VERSION = 8;
    private static final int MSG_ENABLE_WARN = 9;

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
        if (DEBUG) {
            System.out.println("SMSSDKUtils.init");
        }

        Message msg = new Message();
        msg.what = MSG_INITSDK;
        Bundle data = new Bundle();
        data.putString("appKey",appKey);
        data.putString("appSecret",appSecret);
        data.putBoolean("isWarn",isWarn);
        msg.setData(data);
        UIHandler.sendMessage(msg, this);

    }

    public void getTextCode(String zone, String phone) {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getTextCode");
        }

        Message msg = new Message();
        msg.what = MSG_TEXT_CODE;
        Bundle data = new Bundle();
        data.putString("zone",zone);
        data.putString("phone",phone);
        msg.setData(data);
        UIHandler.sendMessage(msg, this);
    }

    public void getVoiceCode(String zone, String phone) {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getVoiceCode");
        }

        Message msg = new Message();
        msg.what = MSG_VOICE_CODE;
        Bundle data = new Bundle();
        data.putString("zone",zone);
        data.putString("phone",phone);
        msg.setData(data);
        UIHandler.sendMessage(msg, this);
    }

    public void submitCode(String zone, String phone, String code) {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.submitCode");
        }

        Message msg = new Message();
        msg.what = MSG_SUBMIT_CODE;
        Bundle data = new Bundle();
        data.putString("zone",zone);
        data.putString("phone",phone);
        data.putString("code",code);
        msg.setData(data);
        UIHandler.sendMessage(msg, this);
    }

    public void getSupportedCountry() {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getSupportedCountry");
        }

        Message msg = new Message();
        msg.what = MSG_SUPPORTED_COUNTRY;
        UIHandler.sendMessage(msg, this);
    }

    public void getFriendsInApp() {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getFriendsInApp");
        }

        Message msg = new Message();
        msg.what = MSG_FRIENDS_INAPP;
        UIHandler.sendMessage(msg, this);
    }

    public void submitUserInfo(String uid, String nickname, String avatar,
                               String country, String phone) {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.submitUserInfo");
        }

        Message msg = new Message();
        msg.what = MSG_SUBMIT_USERINFO;
        Bundle data = new Bundle();
        data.putString("uid",uid);
        data.putString("nickname",nickname);
        data.putString("avatar",avatar);
        data.putString("country",country);
        data.putString("phone",phone);
        msg.setData(data);
        UIHandler.sendMessage(msg, this);
    }

    public void getVersion() {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getVersion");
        }

        Message msg = new Message();
        msg.what = MSG_VERSION;
        UIHandler.sendMessage(msg, this);
    }

    public void enableWarn(boolean isWarn) {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.enableWarn");
        }

        Message msg = new Message();
        msg.what = MSG_ENABLE_WARN;
        Bundle data = new Bundle();
        data.putBoolean("isWarn",isWarn);
        msg.setData(data);
        UIHandler.sendMessage(msg, this);
    }

    public boolean handleMessage(Message msg) {
        switch (msg.what){
            case MSG_INITSDK:{
                String appKey = msg.getData().getString("appKey");
                String appSecret  = msg.getData().getString("appSecret");
                boolean isWarn = msg.getData().getBoolean("isWarn");

                if (TextUtils.isEmpty(appKey) || TextUtils.isEmpty(appSecret))
                    break;
				MobSDK.init(context, appKey, appSecret);
				if (isWarn) {
					SMSSDK.setAskPermisionOnReadContact(isWarn);
				}
                EventHandler handler = new EventHandler(){
                    public void afterEvent(int event, int result, Object data) {
                        String resp = JavaTools.javaActionResToCS(event, result, data);
                        UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, resp);
                    }
                };
                SMSSDK.registerEventHandler(handler);
            }
            break;
            case MSG_TEXT_CODE:{
                String zone = msg.getData().getString("zone");
                String phone  = msg.getData().getString("phone");
                SMSSDK.getVerificationCode(zone,phone);
            }
            break;
            case MSG_VOICE_CODE:{
                String zone = msg.getData().getString("zone");
                String phone  = msg.getData().getString("phone");
                SMSSDK.getVoiceVerifyCode(zone,phone);
            }
            break;
            case MSG_SUBMIT_CODE:{
                String zone = msg.getData().getString("zone");
                String phone  = msg.getData().getString("phone");
                String code  = msg.getData().getString("code");
                SMSSDK.submitVerificationCode(zone,phone,code);
            }
            break;
            case MSG_SUPPORTED_COUNTRY:{
                SMSSDK.getSupportedCountries();
            }
            break;
            case MSG_FRIENDS_INAPP:{
                SMSSDK.getFriendsInApp();
            }
            break;
            case MSG_SUBMIT_USERINFO:{
                String uid = msg.getData().getString("uid");
                String nickname  = msg.getData().getString("nickname");
                String avatar  = msg.getData().getString("avatar");
                String country  = msg.getData().getString("country");
                String phone  = msg.getData().getString("phone");
                SMSSDK.submitUserInfo(uid,nickname,avatar,country,phone);
            }
            break;
            case MSG_VERSION:{
                String version =  SMSSDK.getVersion();
                HashMap<String, Object> map = new HashMap<String, Object>();
                map.put("action", 6);
                map.put("status", 1);
                map.put("res", version);
                Hashon hashon = new Hashon();
                UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, hashon.fromHashMap(map));;
            }
            break;
            case MSG_ENABLE_WARN: {
                boolean isWarn = msg.getData().getBoolean("isWarn");
                SPHelper.getInstance().setWarnWhenReadContact(isWarn);
            }
                break;
        }
        return false;
    }

}
