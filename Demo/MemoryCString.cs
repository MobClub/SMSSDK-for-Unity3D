using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
/// <summary>
/// Discription:A String Extension Powered byMemoryC
/// Functions: extension a string text to showAsToast, toJavaString, or Speak out
/// CopyRight:MemoryC
/// Time:2017.02.15
/// </>
/// </summary>
public static class MemoryCString
{

#if UNITY_ANDROID
    /// <summary>
    /// Show String as Toast.
    /// </summary>
    /// <param name="text">Text.</param>
    /// <param name="activity">Activity.</param>
    public static void showAsToast(this string text, AndroidJavaObject activity = null)
    {
        Debug.Log(text);
        if (activity == null)
        {
            AndroidJavaClass UnityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
            activity = UnityPlayer.GetStatic<AndroidJavaObject>("currentActivity");
        }
        AndroidJavaClass Toast = new AndroidJavaClass("android.widget.Toast");
        AndroidJavaObject context = activity.Call<AndroidJavaObject>("getApplicationContext");
        activity.Call("runOnUiThread", new AndroidJavaRunnable(() => {
            //AndroidJavaObject javaString = new AndroidJavaObject("java.lang.String", text);
            Toast.CallStatic<AndroidJavaObject>("makeText", context, text.toJavaString(), Toast.GetStatic<int>("LENGTH_SHORT")).Call("show");
        }
        ));
    }

    public static AndroidJavaObject toJavaString(this string CSharpString)
    {
        return new AndroidJavaObject("java.lang.String", CSharpString);
    }

    public static string toCString(this AndroidJavaObject javaString)
    {
        byte[] resultByte = javaString.Call<byte[]>("getBytes");
        return System.Text.Encoding.Default.GetString(resultByte);
    }

#endif

    /// <summary>
    /// The user interface text.
    /// </summary>
    public static Text UIText = null;
    public static void showAtText(this string textString)
    {
        if (UIText != null)
        {
            UIText.text = textString;
        }
        else
        {
            Debug.LogError("Please Pass Value to toShowText First");
        }
    }

}