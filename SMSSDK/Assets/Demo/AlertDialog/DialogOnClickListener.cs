using System.Collections;
using System.Collections.Generic;
using UnityEngine;
/// <summary>
/// Dialog on click listener.
/// CopyRight:MemoryC
/// Time:2017.05.04
/// Original:[url=http://www.manew.com/forum-47-453-1.html]http://www.manew.com/forum-47-453-1.html[/url]
/// </summary>
public class DialogOnClickListener : AndroidJavaProxy
{
    public delegate void OnClickDelegate(AndroidJavaObject dialog, int which);

    public OnClickDelegate onClickDelegate;

    public DialogOnClickListener() : base("android.content.DialogInterface$OnClickListener")
    {

    }

    public void onClick(AndroidJavaObject dialog, int which)
    {
        //
        if (onClickDelegate != null)
        {
            onClickDelegate(dialog, which);
        }
    }
}