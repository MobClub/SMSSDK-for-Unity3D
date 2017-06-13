using System;
using System.IO;
using System.Collections;
using System.Runtime.Serialization.Formatters.Binary;
using UnityEditor;
using UnityEngine;

namespace cn.SMSSDK.Unity
{
	[CustomEditor(typeof(SMSSDK))]
		[ExecuteInEditMode]
		public class SMSSDKConfigEditor : Editor {

				SMSSDKConfig config;

				void Awake()
				{
					Prepare ();
				}
						
				public override void OnInspectorGUI()
				{
						EditorGUILayout.Space ();
						config.appKey = EditorGUILayout.TextField ("MobAppKey", config.appKey);
						config.appSecret = EditorGUILayout.TextField ("MobAppSecret", config.appSecret);
						Save ();
				}

				private void Prepare()
				{
						string filePath = Application.dataPath + "/iOSAutoPackage/Editor/SDKPorter/SMSSDKConfig.bin";
						try
						{
								BinaryFormatter formatter = new BinaryFormatter();
								Stream destream = new FileStream(filePath, FileMode.Open, FileAccess.Read, FileShare.Read);
								SMSSDKConfig config = (SMSSDKConfig)formatter.Deserialize(destream);
								destream.Flush();
								destream.Close();
								this.config = config;
						}
						catch(Exception)
						{
								this.config = new SMSSDKConfig ();
						}
				}

				private void Save()
				{
						try
						{
								string filePath = Application.dataPath + "/iOSAutoPackage/Editor/SDKPorter/SMSSDKConfig.bin";
								BinaryFormatter formatter = new BinaryFormatter();
								Stream stream = new FileStream(filePath, FileMode.Create, FileAccess.Write, FileShare.None);
								formatter.Serialize(stream, this.config);
								stream.Flush();
								stream.Close();
						}
						catch (Exception e) 
						{
								Debug.Log ("save error:" + e);
						}
				}

		}
}