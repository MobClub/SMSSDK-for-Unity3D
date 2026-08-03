using System.Collections;
using System.Collections.Generic;
using UnityEngine;

#if UNITY_ANDROID
/// <summary>
/// Alert dialog.
/// CopyRight:MemoryC
/// Time:2017.05.04
/// Original:[url=http://www.manew.com/forum-47-453-1.html]http://www.manew.com/forum-47-453-1.html[/url]
/// </summary>
public class AlertDialog : MonoBehaviour
{

    public AndroidJavaObject activity;

    private AndroidJavaObject builder;

    private bool isTitleSet = false;
    private bool isMessageSet = false;
    private bool isPositiveButtonSet = false;
    private bool isNegativeButtonSet = false;
    private bool isCreated = false;

    public AlertDialog(AndroidJavaObject context)
    {
        activity = context;
        builder = new AndroidJavaObject("android.app.AlertDialog$Builder", activity);
    }

    public void setTitle(string title)
    {
        builder = builder.Call<AndroidJavaObject>("setTitle", title.toJavaString());
        isTitleSet = true;
    }

    public void setMessage(string message)
    {
        builder = builder.Call<AndroidJavaObject>("setMessage", message.toJavaString());
        isMessageSet = true;
    }

    public void setPositiveButton(string name, DialogOnClickListener confirmListener)
    {
        builder = builder.Call<AndroidJavaObject>("setPositiveButton", name.toJavaString(), confirmListener);
        isPositiveButtonSet = true;
    }

    public void setNegativeButton(string name, DialogOnClickListener cancelListener)
    {
        builder = builder.Call<AndroidJavaObject>("setNegativeButton", name.toJavaString(), cancelListener);
        isNegativeButtonSet = true;
    }
    public void create()
    {
        builder = builder.Call<AndroidJavaObject>("create");
        isCreated = true;
    }

    public void show()
    {

        if (!isTitleSet)
        {
            ("isTitleSet=" + isTitleSet).showAsToast();
            return;
        }
        else if (!isMessageSet)
        {
            ("isMessageSet=" + isMessageSet).showAsToast();
            return;
        }
        //else if (!isPositiveButtonSet)
        //{
        //    ("isPositiveButtonSet=" + isPositiveButtonSet).showAsToast();
        //    return;
        //}
        //else if (!isNegativeButtonSet)
        //{
        //    ("isNegativeButtonSet=" + isNegativeButtonSet).showAsToast();
        //    return;
        //}
        else if (!isCreated)
        {
            ("isCreated=" + isCreated).showAsToast();
            return;
        }

        builder.Call("show");

    }
}
#endif