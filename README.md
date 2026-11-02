# externalBuildApk

ImGui + IL2CPP external menu template (from `externalBuildApk.zip`), packaged as a standalone debug APK.

- Native module: `libMvp.so` (`LOCAL_MODULE := Mvp`)
- Application id: `com.lieshooter.imgui`
- NDK: `ndk-build` via `app/src/main/jni/Android.mk` (arm64-v8a)

## Build

GitHub Actions → **Build APK** → artifact `externalBuildApk-apk`.

Local:

```bash
./gradlew assembleDebug
```

APK: `app/build/outputs/apk/debug/app-debug.apk`.

**Note:** Runtime logic targets injected use (`liblogic.so`, EGL hook). The APK shell loads `Mvp` for packaging and testing the build; full features require the target game environment described in the original template README.
