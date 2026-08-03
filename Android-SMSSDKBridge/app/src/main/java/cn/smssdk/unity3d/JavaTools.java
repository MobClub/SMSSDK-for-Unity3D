package cn.smssdk.unity3d;

import com.mob.tools.utils.Hashon;

import org.json.JSONArray;

import java.util.ArrayList;
import java.util.HashMap;

import cn.smssdk.SMSSDK;

public class JavaTools {
    private static Hashon hashon = new Hashon();
    public static  String javaActionResToCS(int event, int result, Object data) {
        int action = 0;
        if (event == SMSSDK.EVENT_GET_VERIFICATION_CODE || event == SMSSDK.EVENT_GET_VOICE_VERIFICATION_CODE) {
            action = 1;
        } else if(event == SMSSDK.EVENT_SUBMIT_VERIFICATION_CODE) {
            action = 2;
        } else if(event == SMSSDK.EVENT_GET_SUPPORTED_COUNTRIES) {
            action = 3;
        }else if(event == SMSSDK.EVENT_SUBMIT_USER_INFO) {
            action = 4;
        }else if(event == SMSSDK.EVENT_GET_FRIENDS_IN_APP) {
            action = 5;
        }else if(event == 10) {
            action = 7;
        }

        HashMap<String, Object> map = new HashMap<String, Object>();
        map.put("action", action);
        if (result == SMSSDK.RESULT_ERROR) {
            map.put("status", 2); // Success = 1, Fail = 2
            if (data instanceof  Throwable) {
                map.put("res", throwableToMap((Throwable) data).toString());
            } else {
                map.put("res",data.toString());
            }
        } else {
            map.put("status", 1);
            String res = null;
            if (data instanceof HashMap) {
                res = hashon.fromHashMap((HashMap)data);
            } else if (data instanceof ArrayList) {
                res = new JSONArray((ArrayList)data).toString();
            } else if (data != null){
                res = data.toString();
            }
            map.put("res", res);
        }
        return hashon.fromHashMap(map);
    }

    private static String throwableToMap(Throwable t) {
        HashMap<String, Object> map = new HashMap<String, Object>();
        map.put("msg", t.getMessage());
        ArrayList<HashMap<String, Object>> traces = new ArrayList<HashMap<String, Object>>();
        for (StackTraceElement trace : t.getStackTrace()) {
            HashMap<String, Object> element = new HashMap<String, Object>();
            element.put("cls", trace.getClassName());
            element.put("method", trace.getMethodName());
            element.put("file", trace.getFileName());
            element.put("line", trace.getLineNumber());
            traces.add(element);
        }
        map.put("stack", traces);
        Throwable cause = t.getCause();
        if (cause != null) {
            map.put("cause", throwableToMap(cause));
        }
        return hashon.fromHashMap(map);
    }
}
