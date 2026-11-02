Leaked By : https://t.me/PhSourceGame





void dns_bepas() {
    
    auto thread = Il2CppThreadAttach();
    
    auto GetHostByName_internal = (bool (*)(void *, String *, String *, String *, String *, int)) (AssemblyCSharp->getClass("System.Net", "Dns")->getMethod("GetHostByName_internal", 5));
    if (GetHostByName_internal) {
		auto aksess = GetHostByName_internal(0, String::Create(OBFUSCATE(""), String::Create(OBFUSCATE(""), String::Create(OBFUSCATE(""), String::Create(OBFUSCATE(""), 0);
		if (aksess) {
			aksess = false;
		}
	}
	
	auto GetHostByAddr_internal = (bool (*)(void *, String *, String *, String *, String *, int)) (AssemblyCSharp->getClass("System.Net", "Dns")->getMethod("GetHostByAddr_internal", 5));
    if (GetHostByAddr_internal) {
		auto aksess = GetHostByAddr_internal(0, String::Create(OBFUSCATE(""), String::Create(OBFUSCATE(""), String::Create(OBFUSCATE(""), String::Create(OBFUSCATE(""), 0);
		if (aksess) {
			aksess = false;
		}
	}
	
	auto GetHostName_internal = (bool (*)(void *, String *)) (AssemblyCSharp->getClass("System.Net", "Dns")->getMethod("GetHostName_internal", 1));
    if (GetHostName_internal) {
		auto aksess = GetHostName_internal(0, String::Create(OBFUSCATE(""));
		if (aksess) {
			aksess = false;
		}
	}
	
	auto Error_11001 = (void * (*)(void *, String *)) (AssemblyCSharp->getClass("System.Net", "Dns")->getMethod("Error_11001", 1));
    if (Error_11001) {
		auto aksess = Error_11001(0, String::Create(OBFUSCATE(""));
		if (aksess) {
			aksess = nullptr;
		}
	}
	
	Il2CppThreadDetach(thread);
}



leak By : https://t.me/PhSourceGame