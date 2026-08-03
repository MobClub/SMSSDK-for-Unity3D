package cn.smssdk.unity3d;

import android.content.Context;
import android.text.TextUtils;
import android.util.Log;

import com.mob.MobSDK;
import com.mob.OperationCallback;
import com.mob.tools.utils.Hashon;
import com.unity3d.player.UnityPlayer;

import java.util.HashMap;

import cn.smssdk.EventHandler;
import cn.smssdk.SMSSDK;
import cn.smssdk.wrapper.TokenVerifyResult;

public class SMSSDKUtils implements SMSSDKInterface{
    private static boolean DEBUG = true;

    private static Context context;
    private static String u3dGameObject;
    private static String u3dCallback;
    private static TokenVerifyResult result;

    public SMSSDKUtils(final String gameObject, final String callback) {
        if (DEBUG) {
            Log.e("Unity", "SMSSDKUtils.prepare");
        }
        if (context == null) {
            context = UnityPlayer.currentActivity.getApplicationContext();
        }

        if (!TextUtils.isEmpty(gameObject)) {
            u3dGameObject = gameObject;
        }

        if (!TextUtils.isEmpty(callback)) {
            u3dCallback = callback;
        }

        EventHandler eh = new EventHandler() {
            @Override
            public void afterEvent(int event, int result, Object data) {
                //status       Success = 1, Fail = 2
                HashMap<String, Object> map = new HashMap<String, Object>();
                if (result == SMSSDK.RESULT_COMPLETE) {
                    map.put("status", 1);
                    if (event == SMSSDK.EVENT_GET_VERIFICATION_CODE) {
                        map.put("action", 1);
                    } else if (event == SMSSDK.EVENT_SUBMIT_VERIFICATION_CODE) {
                        map.put("action", 2);
                    } else if (event == SMSSDK.EVENT_GET_SUPPORTED_COUNTRIES) {
                        map.put("action", 3);
//                        if (data instanceof ArrayList) {
//                            ArrayList a = (ArrayList) data;
                        map.put("res", data.toString());
//                        }
                    } else if (event == SMSSDK.EVENT_GET_VOICE_VERIFICATION_CODE) {
                        map.put("action", 1);
                    }
                } else {
                    map.put("status", 2);
                    map.put("res", ((Throwable) data).getLocalizedMessage());
                }
                Hashon hashon = new Hashon();
                UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, hashon.fromHashMap(map));

            }
        };
        SMSSDK.registerEventHandler(eh); //注册短信回调
    }

    public void getCode(int type, String phone, String zone, String tempCode) {
        if (type == 0) {
            getTextCode(zone, phone, tempCode);
        } else if (type == 1){
            getVoiceCode(zone, phone);
        }
    }
    public void getTextCode(String zone, String phone, String tempCode) {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getTextCode");
        }
        SMSSDK.getVerificationCode(zone, phone, tempCode, null);
    }

    public void submitPolicyGrantResult(boolean isAgree) {
//        if (DEBUG) {
        System.out.println("SMSSDKUtils.submitPolicyGrantResult");
//        }
        final HashMap<String, Object> map = new HashMap<String, Object>();
        map.put("action", 10);
        MobSDK.submitPolicyGrantResult(isAgree, new OperationCallback<Void>() {
            @Override
            public void onComplete(Void aVoid) {
                map.put("status", 1);//Success = 1, Fail = 2
                map.put("res", "success");
                Hashon hashon = new Hashon();
                UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, hashon.fromHashMap(map));
                ;
            }

            @Override
            public void onFailure(Throwable throwable) {
                map.put("status", 2);//Success = 1, Fail = 2
                map.put("res", throwable.getLocalizedMessage());
                Hashon hashon = new Hashon();
                UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, hashon.fromHashMap(map));
                ;
            }
        });

    }

    public void getVoiceCode(String zone, String phone) {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getVoiceCode");
        }
        SMSSDK.getVoiceVerifyCode(zone, phone);
    }

    @Override
    public void getVersion() {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getVersion");
        }
        String version = SMSSDK.getVersion();
        HashMap<String, Object> map = new HashMap<String, Object>();
        map.put("action", 6);
        map.put("status", 1);
        map.put("res", version);
        Hashon hashon = new Hashon();
        UnityPlayer.UnitySendMessage(u3dGameObject, u3dCallback, hashon.fromHashMap(map));

    }

    @Override
    public void getSupportedCountryCode() {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.getSupportedCountry");
        }
        SMSSDK.getSupportedCountries();
    }


    @Override
    public void commitCode(String phoneNumber, String zone, String code) {
        if (DEBUG) {
            System.out.println("SMSSDKUtils.submitCode");
        }
        SMSSDK.submitVerificationCode(zone, phoneNumber, code);
    }


//    public void enableWarn(boolean isWarn) {
//        if (DEBUG) {
//            System.out.println("SMSSDKUtils.enableWarn");
//        }
//
//        Message msg = new Message();
//        msg.what = MSG_ENABLE_WARN;
//        Bundle data = new Bundle();
//        data.putBoolean("isWarn", isWarn);
//        msg.setData(data);
//        UIHandler.sendMessage(msg, this);
//    }
}
