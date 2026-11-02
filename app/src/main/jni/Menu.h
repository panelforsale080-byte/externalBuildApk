#include "feature/minimap.h"

bool show_another_kontol = false;

bool showMenu = true;
bool bFullChecked = false;
bool bypass = false;

static bool isLogin = false, isSave = false;

static bool loginButton = false;

static const char *statusLogin = "Click Login";

static char s[64];
    
unsigned int gpCrash = 0xfa91b9cd;
static int crash(int randomval){
    volatile int *p = (int *)gpCrash;
    p += randomval;
    p += *p + randomval;
    /* If it still doesnt crash..crash using null pointer */
    p = 0;
    p += *p;
    return *p;
}

void CenteredText(ImColor color, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    const char *text, *text_end;
    ImFormatStringToTempBufferV(&text, &text_end, fmt, args);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize(text, text_end).x) * 0.5);
    ImGui::TextColoredV(color, fmt, args);
    va_end(args);
}

inline ImVec4 RGBA2ImVec4(int r, int g, int b, int a) {
    float newr = (float)r / 255.0f;
    float newg = (float)g / 255.0f;
    float newb = (float)b / 255.0f;
    float newa = (float)a / 255.0f;
    return ImVec4(newr, newg, newb, newa);
}

struct sFeature {
    //ESP Player
    bool ESPLine;
    bool ESPRound;
    bool ESPName;
	bool ESPHero;
    bool ESPHealth;
    bool ESPAlert;

    //ESP Info
    bool ESPSkillCD;
    bool ESPSpellCD;

    //ESP Jungle
    bool ESPMRound;
    bool ESPMHealth;
	
	//Minimap
	bool MinimapIcon2;
	bool MinimapIcon1;
    bool MinimapIcon;
    bool HideLine;
	int SetAjust=2;
	bool TrySkill = false;
};
struct sAuto {
		bool SwordLing;
		bool Karina;
		bool Gusion;
		bool Gusion2;
		bool Martis;
		bool Zilong;
		bool Pharsa;
        };
 sAuto Auto{0};
struct sAim {
		int Target;	
		bool AutoTakeSword;
		    bool Basic;
            bool Spell;
            bool Skill1;
            bool Skill2;
            bool Skill3;
            bool Skill4;
        };
 sAim Aim{0};
sFeature Feature{0};
struct sAutoRetribution {
			bool Buff;
            bool Turtle;
			bool Lord;
			bool Creep;
			bool Litho;
			bool Buf1;
            bool Turtl1;
			bool Lor1;
			bool Cree1;
			bool Lith1;
        };
 //sAutoRetribution AutoRetribution{0}
 
 
 
 
static float SetFieldOfView = 0, GetFieldOfView = 0;
static float RangeFOV = 15.0f;
void HideMenu(bool& bShow) {
    if (bShow) {
        ImGui::OpenPopup("ConfirmHide");
    }
	

    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    if (ImGui::BeginPopupModal("ConfirmHide", 0, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse))
    {
        ImGui::Text("Are you sure you want to hide the menu?");
        if (ImGui::Button("Yes", ImVec2(ImGui::GetContentRegionAvail().x / 2, 0)))
        {
            showMenu = false;
            bShow = false;
            ImGui::CloseCurrentPopup();
        }
        ImGui::SameLine();
        if (ImGui::Button("No", ImVec2(ImGui::GetContentRegionAvail().x, 0)))
        {
            bShow = false;
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
}

std::string msg;
void LoginThread(const std::string &user_key, bool *success) {
    msg = Login(g_vm, user_key.c_str(), success);
}

void ShowMenu()
{
    ImGui::SetNextWindowSize(ImVec2(600, 680), ImGuiCond_FirstUseEver);
    ImGuiIO& io = ImGui::GetIO();

    static float window_scale;
    if (!window_scale) window_scale = 1.0f;
    io.FontGlobalScale = window_scale;

    
    if (isLogin && !isSave) {
      /*  SharedPreferences sharedPref(GetJNIEnv(g_vm), "divarvian_sharedpref");
        SharedPreferences_Editor editor=sharedPref.edit();
        editor.putString("key", s);
        editor.commit();*/
        isSave = true;
		pthread_t t;
		loadBattleData();
		bFullChecked = true;
    }

    static bool isPopUpHide = false;
    HideMenu(isPopUpHide);
	
    static bool bFlagAutoResize = true;
    static ImGuiWindowFlags window_flags;
    if (bFlagAutoResize) {
        window_flags = ImGuiWindowFlags_AlwaysAutoResize;
    } else {
        window_flags = ImGuiWindowFlags_None;
    }

   //if (isLogin && title == "") crash(0x3d5f);
	if (isLogin && title != "") {
		pthread_t t;
		loadBattleData();
		bFullChecked = true;
	}
	
	std::string FULLTITLE = std::string(OBFUSCATE(" RenMods External V2")) + std::string("") + std::string("") + std::string("") + std::string(ABI);
    if (!ImGui::Begin(FULLTITLE.c_str(), 0, window_flags))
    {
        ImGui::End();
        return;
    }

    if (!isLogin) {
        if (ImGui::BeginTabBar("TabLogin", ImGuiTabBarFlags_FittingPolicyScroll)) {
            if (ImGui::BeginTabItem("HOME")) {
                ImGui::BeginGroupPanel("Login Here [ Copy Key To Clip Board ]", ImVec2(0.0f, 0.0f));
                {
                    ImGui::PushItemWidth(-1);
                    ImGui::InputText("##key", s, sizeof s);
                    ImGui::PopItemWidth();
                    
                    if (ImGui::Button("Login", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                    loginButton = true;
                    }

                    ImGui::TextColored(RGBA2ImVec4(111, 45, 168, 255), "%s", statusLogin);
                    ImGui::Spacing();
                }
                ImGui::EndGroupPanel();
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
    } else {
        if (ImGui::BeginTabBar("Tab", ImGuiTabBarFlags_FittingPolicyScroll)) {
			
			if (ImGui::BeginTabItem("Menu")) {
		    ImGui::BeginGroupPanel("About", ImVec2(0.0f, 0.0f));
            
			    ImGui::Text("Developer : @RenMods17 ");
			    ImGui::Text("Telegram : RenMods17");
			    ImGui::Text("Contact : 0822-1193-1032 ");
			    ImGui::Text("Developer From : INDONESIA");
			    ImGui::Text("Version : Playstore");
			    ImGui::Text("Bypass : Strong+");
			    ImGui::Text("UI : Smooth");
				ImGui::Text("Status : Safe");
				
			    ImGui::Text("Expired : ");
                ImGui::TextColored(ImVec4{0.74f, 0.58f, 0.98f, 1.0f}, BHATIA_EXP.c_str());
    
    
				ImGui::Spacing();
                ImGui::EndGroupPanel();
                
                ImGui::EndTabItem();
			}
         
			if (ImGui::BeginTabItem("VISUAL")) {
                ImGui::BeginGroupPanel("Player", ImVec2(0.0f, 0.0f));
                {
                    ImGui::Checkbox("Line", &Feature.ESPLine);
                    ImGui::Checkbox("Round", &Feature.ESPRound);
                    ImGui::Checkbox("Name", &Feature.ESPName);
					ImGui::Checkbox("Hero", &Feature.ESPHero);
                    ImGui::Checkbox("Health", &Feature.ESPHealth);
                 //   ImGui::Checkbox("Esp Minimap icon", &Feature.MinimapIcon);
					
					ImGui::Spacing();
                }
                ImGui::EndGroupPanel();

                ImGui::SameLine();

                ImGui::BeginGroup();
                {
                    ImGui::BeginGroupPanel("Monster", ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::Checkbox("ESP Round", &Feature.ESPMRound);
						ImGui::SameLine();
                        ImGui::Checkbox("ESP Health", &Feature.ESPMHealth);
                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();

                    ImGui::BeginGroupPanel("Info ESP", ImVec2(-1.0f, 0.0f));
                    {
						ImGui::Checkbox("Skill CD", &Feature.ESPSkillCD);
                        ImGui::Checkbox("Spell CD", &Feature.ESPSpellCD);
                        ImGui::Checkbox("Show Hero Alert", &Feature.ESPAlert);
                        ImGui::Checkbox("Skin", &UnlockSkins);
                      
						ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();
                }
                ImGui::EndGroup();
				
				ImGui::EndTabItem();


            }
				
				if (ImGui::BeginTabItem("OTHER")) {
				ImGui::BeginGroupPanel("Esp MiniMap", ImVec2(-1.0f, 0.0f));
                    {
				ImGui::Checkbox("ESP MiniMap", &Feature.MinimapIcon);
					
			ImGui::Text("Map Size:");
			ImGui::SliderInt("Pos", &ESP::MinimapPos, 0, 400);
            ImGui::SliderInt("Size", &ESP::MinimapSize, 0, 600);
            ImGui::Text("Icon Size:");
				   ImGui::SliderFloat("##ICSize", &ICSize, 20, 40, "%.1f");
				   ImGui::SliderFloat("##ICHealthThin", &ICHealthThin, 1, 5, "%.1f");
				 
						ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();
             
				
				ImGui::BeginGroupPanel("Additional", ImVec2(-1.0f, 0.0f));
                {
					
			     ImGui::Checkbox("Bypass", &bypass);
				 ImGui::Text("Drone View:");
                   ImGui::SliderFloat("##DroneView", &SetFieldOfView, 0, 50, "%.1f");
                   
					ImGui::Spacing();
                }
                ImGui::EndGroupPanel();
	
ImGui::EndTabItem();


            }
            if (ImGui::BeginTabItem("ROOM INFO")) {
				if (bFullChecked) RoomInfoList();
                ImGui::TextColored(ImVec4(0.0f, 0.8f, 1.0f, 1.0f), "Team");
                if (ImGui::BeginTable("##Team", 9, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    ImGui::TableSetupColumn("Name");
					ImGui::TableSetupColumn("ID");
                    ImGui::TableSetupColumn("Verified");
                    ImGui::TableSetupColumn("Rank");
                    ImGui::TableSetupColumn("Star");
					ImGui::TableSetupColumn("Hero");
					ImGui::TableSetupColumn("Spell");
					ImGui::TableSetupColumn("Flag");
					ImGui::TableSetupColumn("Country");
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < 5; row++) {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 9; column++) {
                            ImGui::TableSetColumnIndex(column);
                            char buf[32];
                            if (column == 0) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Name.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 1) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].UserID.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 2) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Verified.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 3) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Rank.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 4) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Star.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 5) {
                                RoomInfoHero(RoomInfo.PlayerB[row].HeroID);
                            } else if (column == 6) {
                                RoomInfoSpell(RoomInfo.PlayerB[row].Spell);
						    } else if (column == 7) {								
                                 RoomInfoCountry2(RoomInfo.PlayerB[row].Country2); 
                            } else if (column == 8) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Country.c_str());
                                ImGui::TextUnformatted(buf);
                            }
                        }
                    }
                    ImGui::EndTable();
                }
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Enemy");
                if (ImGui::BeginTable("##Enemy", 9, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    ImGui::TableSetupColumn("Name");
					ImGui::TableSetupColumn("ID");
                    ImGui::TableSetupColumn("Verified");
                    ImGui::TableSetupColumn("Rank");
                    ImGui::TableSetupColumn("Star");
					ImGui::TableSetupColumn("Hero");
					ImGui::TableSetupColumn("Spell");
					ImGui::TableSetupColumn("Flag");
					ImGui::TableSetupColumn("Country");
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < 5; row++) {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 9; column++) {
                            ImGui::TableSetColumnIndex(column);
                            char buf[32];
                            if (column == 0) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Name.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 1) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].UserID.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 2) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Verified.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 3) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Rank.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 4) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Star.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 5) {
                                RoomInfoHero(RoomInfo.PlayerR[row].HeroID);
                            } else if (column == 6) {
                                RoomInfoSpell(RoomInfo.PlayerR[row].Spell);
						    } else if (column == 7) {								
                                RoomInfoCountry2(RoomInfo.PlayerR[row].Country2); 
                            } else if (column == 8) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Country.c_str());
                                ImGui::TextUnformatted(buf);
                            }
                        }
                    }
                    ImGui::EndTable();
                }
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Setting")) {
				show_another_kontol = false;
                ImGui::BeginGroupPanel("Menu Setting", ImVec2(-1.0f, 0.0f));
                {
					ImGui::BeginGroupPanel("Key Information", ImVec2(-1.0f, 0.0f));
    {
    ImGui::Text("Expired : ");
    ImGui::SameLine();
    ImGui::TextColored(ImVec4{0.74f, 0.58f, 0.98f, 1.0f}, BHATIA_EXP.c_str());
    }
    ImGui::EndGroupPanel();
 
 ImGui::Spacing();
					
                        
                    ImGui::Checkbox("Auto Resize", &bFlagAutoResize);
                    ImGui::BeginGroupPanel("Window Size", ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::PushItemWidth(-1);
                        ImGui::SliderFloat("##Scale", &window_scale, 0.5f, 1.5f, "%.1f");
                        ImGui::PopItemWidth();
                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();

                    if (ImGui::Button("Hide Menu", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                        isPopUpHide = true;
                    }

                    ImGui::BeginGroupPanel("English", ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::TextColored(RGBA2ImVec4(111, 45, 168, 255), "To display the menu again,");
                        ImGui::TextColored(RGBA2ImVec4(111, 45, 168, 255), "simply touch on the lower left corner of your screen.");
                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();

                    ImGui::BeginGroupPanel("Indonesia", ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::TextColored(RGBA2ImVec4(111, 45, 168, 255), "Untuk menampilkan kembali menu,");
                        ImGui::TextColored(RGBA2ImVec4(111, 45, 168, 255), "cukup sentuh di pojok kiri bawah layar Anda.");
                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();

                    ImGui::Spacing();
                }
                ImGui::EndGroupPanel();
                ImGui::EndTabItem();
				
				
        }
		
		
		if (bypass) {
       ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.30f, (float) glHeight * 0.30f),ImGuiCond_Once);
        if (ImGui::Begin("Bypass RenMods", &bypass, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text(" Bypass Protection : Running... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
		    ImGui::Text(" Bypass DNS : Running... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
		    ImGui::Text(" Blocked Report : Running... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
		    ImGui::Text(" Blocked Detect Devices : Running... %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
                
       }}


          
            }
            ImGui::EndTabBar();
        }
    }



