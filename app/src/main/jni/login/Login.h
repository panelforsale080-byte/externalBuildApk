#pragma once
#include "curl/curl.h"
#include "Tools.h"
#include "json.hpp"

#include "obfuscate/obfuscate.h"

using json = nlohmann::ordered_json;
std::string g_Token, g_Auth;
std::string expired, title, version, battleData;
std::string UUID;

std::string BHATIA_EXP = "";


bool bValid = false;

bool bInitDone;

struct MemoryStruct {
    char *memory;
    size_t size;
};

std::string GetFormattedDateTime() {
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), OBFUSCATE("%Y-%m-%d (%H:%M:%S)"), std::localtime(&now));
    return std::string(buffer);
}

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;
    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

//std::string credit;
std::string esp;
//std::string token;
std::string expiredDate;
std::string modstatus;

JavaVM *jvm;

std::string Login2(const char *user_key) {
    JNIEnv *env;
    jvm->AttachCurrentThread(&env, 0);
    
        
    auto looperClass = env->FindClass(OBFUSCATE("android/os/Looper"));
    auto prepareMethod = env->GetStaticMethodID(looperClass, OBFUSCATE("prepare"), OBFUSCATE("()V"));
    env->CallStaticVoidMethod(looperClass, prepareMethod);
    
    jclass activityThreadClass = env->FindClass(OBFUSCATE("android/app/ActivityThread"));
    jfieldID sCurrentActivityThreadField = env->GetStaticFieldID(activityThreadClass, OBFUSCATE("sCurrentActivityThread"), OBFUSCATE("Landroid/app/ActivityThread;"));
    jobject sCurrentActivityThread = env->GetStaticObjectField(activityThreadClass, sCurrentActivityThreadField);
    
    jfieldID mInitialApplicationField = env->GetFieldID(activityThreadClass, OBFUSCATE("mInitialApplication"), OBFUSCATE("Landroid/app/Application;"));
    jobject mInitialApplication = env->GetObjectField(sCurrentActivityThread, mInitialApplicationField);
    
    std::string hwid = user_key;
    hwid += GetAndroidID(env, mInitialApplication);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
    jvm->DetachCurrentThread();
    std::string errMsg;
    
    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;
    
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    
    if (curl) {
      
        std::string KAIFEE1 = OBFUSCATE ("https://");
        std::string KAIFEE2 = OBFUSCATE ("attack.software/freepanel/");
        std::string KAIFEE3 = OBFUSCATE ("connect");     
        std::string KAIFEE = KAIFEE1+KAIFEE2+KAIFEE3;      
        curl_easy_setopt(curl, CURLOPT_URL ,KAIFEE.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, OBFUSCATE("Content-Type: application/x-www-form-urlencoded"));
        
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        char data[4096];
        
        sprintf(data, OBFUSCATE("game=PUBG&user_key=%s&serial=%s"), user_key, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[std::string(OBFUSCATE("status"))] == true) {
                    
                    std::string token = result[std::string(OBFUSCATE("data"))][std::string(OBFUSCATE("token"))].get<std::string>();
                    time_t rng = result[std::string(OBFUSCATE("data"))][std::string(OBFUSCATE("rng"))].get<time_t>();
                    BHATIA_EXP = result["data"]["BHATIA_EXP"].get<std::string>();
              
                    if (rng + 30 > time(0)) {
                        std::string auth = OBFUSCATE("PUBG");
                        auth += std::string(OBFUSCATE("-"));
                        auth += user_key;
                        auth += std::string(OBFUSCATE("-"));
                        auth += UUID;
                        auth += std::string(OBFUSCATE("-"));
                        auth += std::string(OBFUSCATE("Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E"));
                        std::string outputAuth = Tools::CalcMD5(auth);
                        g_Token = token;
                        g_Auth = outputAuth;
                        
                        bValid = g_Token == g_Auth;
                        
                        if (bValid) {
                            bInitDone = true;
                        } else {
                            //exit(0);
                        }
                    }
                } else {
                    errMsg = result[std::string(OBFUSCATE("reason"))].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = "{";
                errMsg += e.what();
                errMsg += "}\n{";
                errMsg += chunk.memory;
                errMsg += "}";
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    jvm->DetachCurrentThread();
    return bValid ? OBFUSCATE("ZFMODZ") : errMsg;
 
}


std::string Login(JavaVM *vm, const char *user_key, bool *success) {
    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    auto object = getJNIContext(env);
    std::string hwid = user_key;
    hwid += GetAndroidID(env, object);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
    vm->DetachCurrentThread();
    std::string errMsg;

    struct MemoryStruct chunk {};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
	if (curl) {
		
		
		 std::string xOneusModder = "h";
        std::string xOneusModder1 = "t";
        std::string xOneusModder2 = "t";
        std::string xOneusModder3 = "p";
        std::string xOneusModder4 = "s";
        std::string xOneusModder5 = ":";
        std::string xOneusModder6 = "/";
        std::string xOneusModder7 = "/";
        std::string xOneusModder8 = "t";
        std::string xOneusModder9 = "z";
        std::string xOneusModder10 = "i";
        std::string xOneusModder11 = "g";
        std::string xOneusModder12 = ".";
        std::string xOneusModder13 = "x";
        std::string xOneusModder14 = "1";
        std::string xOneusModder15 = "0";
        std::string xOneusModder16 = ".";      
        std::string xOneusModder17 = "m";
        std::string xOneusRandiKa1 = "x";
        std::string xOneusModder18 = "/";
        std::string xOneusModder19 = "/";
        std::string xOneusModder20 = "/";
        std::string xOneusModder21 = "/";
        std::string xOneusModder22 = "/";
        std::string xOneusModder23 = "/";
        std::string xOneusModder24 = "/";        
        std::string xOneusModder25 = "c";
        std::string xOneusModder26 = "o";        
        std::string xOneusModder27 = "n";   
        std::string xOneusModder28 = "n";  
        std::string xOneusModder29 = "e";  
        std::string xOneusModder30 = "c";
        std::string xOneusModder31 = "t";   
		
		
		
		std::string sRedLink = xOneusModder+xOneusModder1+xOneusModder2+xOneusModder3+xOneusModder4+xOneusModder5+xOneusModder6+xOneusModder7+xOneusModder8+xOneusModder9+xOneusModder10+xOneusModder11+xOneusModder12+xOneusModder13+xOneusModder14+xOneusModder15+xOneusModder16+xOneusModder17+xOneusRandiKa1+xOneusModder18+xOneusModder19+xOneusModder20+xOneusModder21+xOneusModder22+xOneusModder23+xOneusModder24+xOneusModder25+xOneusModder26+xOneusModder27+xOneusModder28+xOneusModder29+xOneusModder30+xOneusModder31;
		
		curl_easy_setopt(curl, CURLOPT_URL, sRedLink.c_str());
	//	std::string api_key = OBFUSCATE("https://tzig.x10.mx/connect");
		//curl_easy_setopt(curl, CURLOPT_URL, (api_key.c_str()));
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
		
		struct curl_slist *headers = NULL;
		headers = curl_slist_append(headers, OBFUSCATE("Content-Type: application/x-www-form-urlencoded"));
		
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		char data[4096];
        sprintf(data, "game=PUBG&user_key=%s&serial=%s", user_key, UUID.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		res = curl_easy_perform(curl);
		if (res == CURLE_OK) {
			try {
				json result = json::parse(chunk.memory);
				if (result[std::string(OBFUSCATE("status"))] == true) {
					std::string token = result[std::string(OBFUSCATE("data"))][std::string(OBFUSCATE("token"))].get<std::string>();
					time_t rng = result[std::string(OBFUSCATE("data"))][std::string(OBFUSCATE("rng"))].get<time_t>();
                    BHATIA_EXP = result["data"]["BHATIA_EXP"].get<std::string>();
					if (rng + 30 > time(0)) {
						std::string auth = OBFUSCATE("PUBG");
						auth += std::string(OBFUSCATE("-"));
						auth += user_key;
						auth += std::string(OBFUSCATE("-"));
						auth += UUID;
						auth += std::string(OBFUSCATE("-"));
						auth += std::string(OBFUSCATE("Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E"));
						
						std::string outputAuth = Tools::CalcMD5(auth);
						g_Token = token;
						g_Auth = outputAuth;
                        *success = g_Token == g_Auth;
					}
				} else {
					errMsg = result[std::string(OBFUSCATE("reason"))].get<std::string>();
				}
			} catch (json::exception &e) {
				errMsg = "{";
				errMsg += e.what();
				errMsg += "}\n{";
				errMsg += chunk.memory;
				errMsg += "}";
			}
		} else {
			errMsg = curl_easy_strerror(res);
		}
	}
	curl_easy_cleanup(curl);
	vm->DetachCurrentThread();
	return errMsg;
}


