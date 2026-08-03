package cn.smssdk.unity3d;


public interface SMSSDKInterface {
    
    void getVersion();
    void getSupportedCountryCode();
    void getCode(int method, String phoneNumber, String zone, String tmpCode);
    void commitCode(String phoneNumber, String zone, String code);
    void submitPolicyGrantResult(boolean isAgree);
}
    