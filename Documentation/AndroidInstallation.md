## Android installation

`npm install react-native-webrtc --save`  

Starting with React Native 0.60 auto-linking works out of the box, so there are no extra steps.

See a sample app in the `examples/GumTestApp` directory.

### Manual linking

This is not needed with React Native >= 0.60.

<details><summary>Show instructions</summary>

In `android/settings.gradle`, add CustomWebRTCModule:

```gradle
include ':CustomWebRTCModule', ':app'
project(':CustomWebRTCModule').projectDir = new File(rootProject.projectDir, '../node_modules/react-native-webrtc/android')
```

In `android/app/build.gradle`, add CustomWebRTCModule to dependencies:

```gradle
dependencies {
  ...
  compile project(':CustomWebRTCModule')
}
```

In your `MainApplication.java`:

```java
@Override
protected List<ReactPackage> getPackages() {
    return Arrays.<ReactPackage>asList(
        new MainReactPackage(),
        new com.oney.CustomWebRTCModule.CustomWebRTCModulePackage() // <-- Add this line
    );
}
```

</details>

### Declaring permissions

Locate your app's `AndroidManifest.xml` file and add these permissions:

```xml
    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
    <uses-permission android:name="android.permission.BLUETOOTH" />
    <uses-permission android:name="android.permission.CAMERA" />
    <uses-permission android:name="android.permission.INTERNET" />
    <uses-permission android:name="android.permission.MODIFY_AUDIO_SETTINGS" />
    <uses-permission android:name="android.permission.RECORD_AUDIO" />
    <uses-permission android:name="android.permission.SYSTEM_ALERT_WINDOW" />
    <uses-permission android:name="android.permission.WAKE_LOCK" />
```

### Enable Java 8 support

In `android/app/build.gradle` add this inside the `android` section:

```gradle
compileOptions {
    sourceCompatibility JavaVersion.VERSION_1_8
    targetCompatibility JavaVersion.VERSION_1_8
}
```

## FAQ

##  Fatal Exception: java.lang.UnsatisfiedLinkError

If you are getting this error:

```
Fatal Exception: java.lang.UnsatisfiedLinkError: No implementation found for void org.custom.webrtc.PeerConnectionFactory.nativeInitializeAndroidGlobals() (tried Java_org_webrtc_PeerConnectionFactory_nativeInitializeAndroidGlobals and Java_org_webrtc_PeerConnectionFactory_nativeInitializeAndroidGlobals__)
       at org.custom.webrtc.PeerConnectionFactory.nativeInitializeAndroidGlobals(PeerConnectionFactory.java)
       at org.custom.webrtc.PeerConnectionFactory.initialize(PeerConnectionFactory.java:306)
       at com.oney.CustomWebRTCModule.CustomWebRTCModule.initAsync(CustomWebRTCModule.java:79)
       at com.oney.CustomWebRTCModule.CustomWebRTCModule.lambda$new$0(CustomWebRTCModule.java:70)
       at com.oney.CustomWebRTCModule.-$$Lambda$CustomWebRTCModule$CnyHZvkjDxq52UReGHUZlY0JsVw.run(-.java:4)
       at java.util.concurrent.ThreadPoolExecutor.runWorker(ThreadPoolExecutor.java:1162)
       at java.util.concurrent.ThreadPoolExecutor$Worker.run(ThreadPoolExecutor.java:636)
       at java.lang.Thread.run(Thread.java:764)
```

Add this line to `android/gradle.properties`:

```
# This one fixes a weird CustomWebRTC runtime problem on some devices.
# https://github.com/jitsi/jitsi-meet/issues/7911#issuecomment-714323255
android.enableDexingArtifactTransform.desugaring=false

```
