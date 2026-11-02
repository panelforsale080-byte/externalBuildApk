#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <thread>
#include <pthread.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <jni.h>
#include <android/log.h>
#include <elf.h>
#include <dlfcn.h>
#include <sys/system_properties.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <android/native_window.h>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>

#define IMGUI_DEFINE_MATH_OPERATORS

#include "imgui.h"
#include "imgui_additional.h"
#include "imgui_themes.h"
#include "backends/imgui_impl_android.h"
#include "backends/imgui_impl_opengl3.h"
#include "fonts/GoogleSans.h"

#include "Tools/xDL/xdl.h"
#include "Tools/fake_dlfcn.h"
#include "Tools/Il2Cpp.h"
#include "Tools/Tools.h"

#include "struct/Vector3.hpp"
#include "struct/Vector2.h"
#include "struct/Rect.h"
#include "struct/Quaternion.h"

#include "config/setup.h"
#include "config/JNIStuff.h"

#include "TouchSystem.h"

#include "icon/DrawIcon.h"

#include "login/Login.h"

#include "feature/class.h"
#include "feature/room.h"
#include "Menu.h"
#include "feature/esp.h"
#include "feature/protection.h"
#include "feature/UnlockSkin.h"
//#include "feature/AutoSkill.h"
//#include "feature/TrySkill.h"
//#include "feature/Retribution.h"


void *pLibRealUnity = nullptr;
typedef jint(JNICALL *CallJNI_OnLoad_t)(JavaVM *vm, void *reserved);
CallJNI_OnLoad_t RealJNIOnLoad = nullptr;

bool copyFile(const char *SRC, const char* DEST)
{
    std::ifstream src(SRC, std::ios::binary);
    std::ofstream dest(DEST, std::ios::binary);
    dest << src.rdbuf();
    return src && dest;
}

const char* getLibraryPath() {
#if defined(__aarch64__) // Untuk arm64-v8a
    return OBFUSCATE("/sdcard/Android/data/com.mobile.legends/files/dragon2017/assets/comlibs/arm64-v8a/libAkSoundEngineNew.bytes");
#elif defined(__ARM_ARCH_7A__) // Untuk armeabi-v7a
    return OBFUSCATE("/sdcard/Android/data/com.mobile.legends/files/dragon2017/assets/comlibs/armeabi-v7a/libAkSoundEngineNew.bytes");
#else
    return nullptr;
#endif
}


const char *realLibToLoad = getLibraryPath();
const char *realLibToLoad2 = OBFUSCATE("/data/data/com.mobile.legends/app_libs/libAkSoundEngineNew.so");
const char *realLinToLoad3 = OBFUSCATE("/data/data/com.mobile.legends/app_libs/libAkSoundEngineNew.so");



#define RealLibToLoad realLibToLoad
#define RealLibToLoad2 realLibToLoad2
#define RealLibToLoad3 realLinToLoad3

EGLBoolean (*orig_eglSwapBuffers)(...);
EGLBoolean _eglSwapBuffers (EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
	if (!(glWidth > 0 && glHeight > 0)) return orig_eglSwapBuffers(dpy, surface);
    if (!g_Initialized) {
        ImGui::CreateContext();
        ImGuiStyle* style = &ImGui::GetStyle();

	    SetAnotherDarkThemeReally();
		
		
		
		style->WindowBorderSize = 2.0f;
		style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
        style->ScaleAllSizes(1.5f);

        ImGuiIO* io = &ImGui::GetIO();
        io->IniFilename = nullptr;
		
		io->DisplaySize = ImVec2((float)glWidth, (float)glHeight);
		
        ImGui_ImplOpenGL3_Init("#version 300 es");

        ImFontConfig font_cfg;
        io->Fonts->AddFontFromMemoryCompressedTTF(GoogleSans_compressed_data, GoogleSans_compressed_size, 28.5f, &font_cfg, io->Fonts->GetGlyphRangesChineseFull());
		
		setRes(glWidth, glHeight);
		
        g_Initialized = true;
    }

    ImGuiIO* io = &ImGui::GetIO();
	
    ImGui_ImplOpenGL3_NewFrame();
	ImplAndroid_NewFrame();
    ImGui::NewFrame();
	
	if (screenWidth < glWidth && screenHeight < glHeight) setRes(glWidth, glHeight);
	
	// set the unity screen resolution to fix touch issue
    if (screenWidth != Screen::get_width() || screenHeight != Screen::get_height()) {
        Screen::SetResolution(screenWidth, screenHeight, true);
    }
	
	ImGui_GetTouch(io, screenHeight);
	
	auto hideShowMin = ImVec2(0, screenHeight - 80);
	auto hideShowMax = ImVec2(80, screenHeight);
	auto mousePos = io->MousePos;
	
	if  (mousePos.x >= hideShowMin.x && mousePos.x <= hideShowMax.x && mousePos.y >= hideShowMin.y && mousePos.y <= hideShowMax.y) {
		showMenu = true;
	}

	UnlockSkin();
	//GusionSkill();
	//ShowWindow
	if (showMenu) ShowMenu();
	
	if (bFullChecked) drawESP(ImGui::GetBackgroundDrawList(), screenWidth, screenHeight);
	
	if (!AttachIconDone) {
		AttachIcon();
		AttachIconDone = true;
	}
	
	if (!AttachSpellDone) {
		AttachSpell();
		AttachSpellDone = true;
	}
	
	if (!AttachCountryDone) {
        AttachCountry();   
        AttachCountryDone = true;
    }
	
    ImGui::EndFrame();
    ImGui::Render();
	glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	
	if (clearMousePos) {
        io->MousePos = ImVec2(-1, -1);
        clearMousePos = false;
    }
	
    return orig_eglSwapBuffers(dpy, surface);
}

std::string getClipboard() {
    std::string result;
    JNIEnv *env;
    
    jvm->AttachCurrentThread(&env, NULL);
    
    auto looperClass = env->FindClass(OBFUSCATE("android/os/Looper"));
    auto prepareMethod = env->GetStaticMethodID(looperClass, OBFUSCATE("prepare"), OBFUSCATE("()V"));
    env->CallStaticVoidMethod(looperClass, prepareMethod);
    
    jclass activityThreadClass = env->FindClass(OBFUSCATE("android/app/ActivityThread"));
    jfieldID sCurrentActivityThreadField = env->GetStaticFieldID(activityThreadClass, OBFUSCATE("sCurrentActivityThread"), OBFUSCATE("Landroid/app/ActivityThread;"));
    jobject sCurrentActivityThread = env->GetStaticObjectField(activityThreadClass, sCurrentActivityThreadField);
    
    jfieldID mInitialApplicationField = env->GetFieldID(activityThreadClass, OBFUSCATE("mInitialApplication"), OBFUSCATE("Landroid/app/Application;"));
    jobject mInitialApplication = env->GetObjectField(sCurrentActivityThread, mInitialApplicationField);
    
    auto contextClass = env->FindClass(OBFUSCATE("android/content/Context"));
    auto getSystemServiceMethod = env->GetMethodID(contextClass, OBFUSCATE("getSystemService"), OBFUSCATE("(Ljava/lang/String;)Ljava/lang/Object;"));
    
    auto str = env->NewStringUTF(OBFUSCATE("clipboard"));
    auto clipboardManager = env->CallObjectMethod(mInitialApplication, getSystemServiceMethod, str);
    env->DeleteLocalRef(str);
    
    jclass ClipboardManagerClass = env->FindClass(OBFUSCATE("android/content/ClipboardManager"));
    auto getText = env->GetMethodID(ClipboardManagerClass, OBFUSCATE("getText"), OBFUSCATE("()Ljava/lang/CharSequence;"));

    jclass CharSequenceClass = env->FindClass(OBFUSCATE("java/lang/CharSequence"));
    auto toStringMethod = env->GetMethodID(CharSequenceClass, OBFUSCATE("toString"), OBFUSCATE("()Ljava/lang/String;"));

    auto text = env->CallObjectMethod(clipboardManager, getText);
    if (text) {
        str = (jstring) env->CallObjectMethod(text, toStringMethod);
        result = env->GetStringUTFChars(str, 0);
        env->DeleteLocalRef(str);
        env->DeleteLocalRef(text);
    }
    
    env->DeleteLocalRef(CharSequenceClass);
    env->DeleteLocalRef(ClipboardManagerClass);
    env->DeleteLocalRef(clipboardManager);
    env->DeleteLocalRef(contextClass);
    env->DeleteLocalRef(mInitialApplication);
    env->DeleteLocalRef(activityThreadClass);   
    jvm->DetachCurrentThread();
    return result.c_str();
}

static std::string err = OBFUSCATE("0");

static std::string key = OBFUSCATE("0");

void *paste_Key(void *) {
    
    while(!isLogin){
        key = getClipboard();
        strncpy(s, key.c_str(), sizeof s);
        
        if(loginButton){
        err = Login2(s);
        
           if (err == "ZFMODZ") {
              isLogin = bValid && g_Auth == g_Token;
              statusLogin = "Sukses Login";
           }else{
              loginButton = false;
              statusLogin = err.c_str();
           }
                        
        
       }
    }
    return nullptr;
}

void *main_thread(void *) {

    copyFile(RealLibToLoad, RealLibToLoad2); 
	
    while (!m_IL2CPP) {
        m_IL2CPP = Tools::GetBaseAddress("liblogic.so");
        sleep(1);
    }

    while (!m_EGL) {
        m_EGL = dlopen_ex("libEGL.so", RTLD_NOW);
        sleep(1);
    }
	
	Il2CppAttach("liblogic.so");
	UnlockSkin();
	sleep(20);
    Tools::Hook((void *) dlsym_ex(m_EGL, "eglSwapBuffers"), (void *) _eglSwapBuffers, (void **) &orig_eglSwapBuffers);
 /*   Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Net"), OBFUSCATE("Dns"), OBFUSCATE("GetHostByName_internal"), 4), (void *) oDns_GetHostByName_internal, (void **) &Dns_GetHostByName_internal);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Net"), OBFUSCATE("Dns"), OBFUSCATE("GetHostByAddr_internal"), 4), (void *) oDns_GetHostByAddr_internal, (void **) &Dns_GetHostByAddr_internal);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Net"), OBFUSCATE("Dns"), OBFUSCATE("hostent_to_IPHostEntry"), 3), (void *) oDns_hostent_to_IPHostEntry, (void **) &Dns_hostent_to_IPHostEntry);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Net"), OBFUSCATE("Dns"), OBFUSCATE("GetHostByAddressFromString"), 2), (void *) oDns_GetHostByAddressFromString, (void **) &Dns_GetHostByAddressFromString);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Net"), OBFUSCATE("Dns"), OBFUSCATE("GetHostEntry"), 1), (void *) oDns_GetHostEntry, (void **) &Dns_GetHostEntry);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Net"), OBFUSCATE("Dns"), OBFUSCATE("GetHostEntry"), 1), (void *) oDns_GetHostEntry, (void **) &Dns_GetHostEntry);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Net"), OBFUSCATE("Dns"), OBFUSCATE("GetHostAddresses"), 1), (void *) oDns_GetHostAddresses, (void **) &Dns_GetHostAddresses);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Net"), OBFUSCATE("Dns"), OBFUSCATE("GetHostByName"), 1), (void *) oDns_GetHostByName, (void **) &Dns_GetHostByName);
    Tools::Hook((void *) (uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("System/Runtime/Remoting"), OBFUSCATE("ServerIdentity"), OBFUSCATE("DisposeServerObject")), (void *) DisposeServerObject, (void **) &oDisposeServerObject);
	*/sleep(5);
	//Tools::Hook((void *) ShowSelfPlayer_OnUpdate, (void *) ShowSelfPlayerOnUpdate, (void **) &oShowSelfPlayerOnUpdate);
   // Tools::Hook((void *) ShowSelfPlayer_TryUseSkill, (void *) TryUseSkill, (void **) &orig_TryUseSkill); 
    return nullptr;
}


JNIEXPORT jint JNICALL CallJNIOL(JavaVM *vm, void *reserved) {
    pthread_t ptid;
    pthread_create(&ptid, NULL, main_thread, NULL);
    
    pthread_t ptid2;
    pthread_create(&ptid2, NULL, paste_Key, NULL);
    
    sleep(5);
    
    if (!pLibRealUnity) {
            pLibRealUnity = dlopen(RealLibToLoad3, RTLD_NOW);
        }
    

    if (!RealJNIOnLoad) {
        RealJNIOnLoad = reinterpret_cast<CallJNI_OnLoad_t>(dlsym(pLibRealUnity, "JNI_OnLoad"));
        if (!RealJNIOnLoad) {
            return -1;
        }
    }
    return RealJNIOnLoad(vm, reserved);
  }

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    jvm = vm;
    JNIEnv *env;
   
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    
   
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    
    return CallJNIOL(vm, reserved);
}
