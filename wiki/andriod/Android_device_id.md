## Android Device Identity信息

设备型号
Build.MODEL
作为external name

设备Android ID
Settings.System.getString(mAppContext.getContentResolver(),
				Settings.Secure.ANDROID_ID)
作为external id，来唯一标识一台设备。

设备的Push token（可选）
向Google某个服务异步请求得到的token
作为附加信息，提交给服务器，API待定。
没有该token时，则不支持push。
另还需要提供更新token、检测是否已提交token的api。

