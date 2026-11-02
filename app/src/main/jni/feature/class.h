#include "imgui.h"



#define Screen_get_width (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", OBFUSCATE("get_width"))
#define Screen_get_height (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", OBFUSCATE("get_height"))
#define Screen_SetResolution (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", OBFUSCATE("SetResolution"), 3)
#define Screen_get_dpi (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", OBFUSCATE("get_dpi"),0)
class Screen {
    public:
	static void SetResolution(int width, int height, bool fullscreen) {
        auto _ = reinterpret_cast<void(*)(int , int , bool )>((uintptr_t)Screen_SetResolution);
        return _(width,height,fullscreen);
    }
	static int get_width() {
        auto _ = reinterpret_cast<int(*)()>((uintptr_t)Screen_get_width);
        return _();
    }
	static int get_height() {
        auto _ = reinterpret_cast<int(*)()>((uintptr_t)Screen_get_height);
        return _();
    }
	static float get_dpi() {
        static const auto _ = reinterpret_cast<float(__fastcall *)()>(Screen_get_dpi);
        return (float) _();
    }
};

//Class Camera
#define Camera_get_Positions (uintptr_t) Il2CppGetFieldOffset("UnityEngine.CoreModule.dll", "", "BattleManager", "m_LocalPlayerShow")
#define Camera_get_main (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "get_main")
#define Camera_WorldToScreenPoint (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "WorldToScreenPoint", 1)
#define Camera_get_fieldOfView (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "get_fieldOfView")
#define Camera_set_fieldOfView (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "set_fieldOfView", 1)

void *get_main() {
	return reinterpret_cast<void *(__fastcall *)()>(Camera_get_main)();
}

Vector3 WorldToScreen(Vector3 position) {
	return reinterpret_cast<Vector3(__fastcall *)(void *, Vector3)>(Camera_WorldToScreenPoint)(get_main(), position);
}

float get_fieldOfView() {
	return reinterpret_cast<float(__fastcall *)(void *)>(Camera_get_fieldOfView)(get_main());
}

void *set_fieldOfView(float value) {
	return reinterpret_cast<void *(__fastcall *)(void *, float)>(Camera_set_fieldOfView)(get_main(), value);
}

#define SystemData_GetBattlePlayerInfo (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", OBFUSCATE("GetBattlePlayerInfo"), 0)
#define SystemData_m_uiID (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll","","SystemData", OBFUSCATE("m_uiID"))
#define SystemData_battleId (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll","","SystemData", OBFUSCATE("_battleId"))

List<uintptr_t> *GetBattlePlayerInfo() {
    return reinterpret_cast<List<uintptr_t> *(__fastcall *)(void *)>(SystemData_GetBattlePlayerInfo)((void *)0);
}

#define RoomData_lUid (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("lUid"))
#define RoomData_uiZoneId (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("uiZoneId"))
#define RoomData_iCamp (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("iCamp"))
#define RoomData_heroid (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("heroid"))
#define RoomData_uiHeroIDChoose (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("uiHeroIDChoose"))
#define RoomData_iCertify (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("iCertify"))
#define RoomData_summonSkillId (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("summonSkillId"))
#define RoomData_sName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("_sName"))
#define RoomData_uiRankLevel (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("uiRankLevel"))
#define RoomData_iMythPoint (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("iMythPoint"))
#define RoomData_country (uintptr_t) Il2CppGetStaticFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData/RoomData"), OBFUSCATE("country"))
#define RoomData_Flag (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("country"))


uintptr_t BattleData_m_BattleBridge, BattleData_battleManager;
void loadBattleData() {
	BattleData_m_BattleBridge = (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "BattleData", OBFUSCATE("m_BattleBridge"));
	BattleData_battleManager = (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "BattleData", OBFUSCATE("battleManager"));
}

//BattleBridge
#define BattleBridge_bStartBattle (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleBridge", OBFUSCATE("bStartBattle"))

//EntityBase
#define EntityBase_m_ID (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_ID"))
#define EntityBase_m_bDeath (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_bDeath"))
#define EntityBase_m_bSameCampType (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_bSameCampType"))
#define EntityBase_m_Hp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_Hp"))
#define EntityBase_m_HpMax (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_HpMax"))
#define EntityBase_m_EntityCampType (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_EntityCampType"))


//ShowEntity
#define ShowEntity_bShowEntityLayer (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("bShowEntityLayer"))
#define ShowEntity_Position (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_vCachePosition")
#define ShowEntity_m_RoleName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_RoleName"))
#define ShowEntity_m_OwnSkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("m_OwnSkillComp"))
#define ShowEntity_get_InTransformation (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", OBFUSCATE("get_InTransformation"))



//BattleManager
#define BattleManager_m_LocalPlayerShow (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", OBFUSCATE("m_LocalPlayerShow"))
#define BattleManager_m_dicMonsterShow (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", OBFUSCATE("m_dicMonsterShow"))
#define BattleManager_m_dicPlayerShow (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", OBFUSCATE("m_dicPlayerShow"))


//ShowPlayer
#define ShowPlayer_m_iSummonSkillId (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", OBFUSCATE("m_iSummonStartSkillId"))



//LogicBattleManager
#define LogicBattleManager_GetPlayerLogic (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", OBFUSCATE("GetPlayerLogic"), 1)
#define LogicBattleManager_Instance (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "LogicBattleManager", OBFUSCATE("Instance"))
#define LogicBattleManager_GetBattleState (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("LogicBattleManager"), OBFUSCATE("GetBattleState"))



//LogicFighter
#define LogicFighter_m_SkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("LogicFighter"), OBFUSCATE("m_SkillComp"))


//LogicSkillComp
#define LogicSkillComp_m_CoolDownComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("LogicSkillComp"), OBFUSCATE("m_CoolDownComp"))


//ShowSkillData
#define ShowSkillData_m_TranID (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", OBFUSCATE("ShowSkillData"), OBFUSCATE("m_TranID"))


//ShowOwnSkillComp
#define ShowOwnSkillComp_skillUseTypeList (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("ShowOwnSkillComp"), OBFUSCATE("skillUseTypeList"))
#define ShowOwnSkillComp_m_SkillList (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("ShowOwnSkillComp"), OBFUSCATE("m_SkillList"))


//CoolDownComp
#define CoolDownComp_m_DicCoolInfo (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("CoolDownComp"), OBFUSCATE("m_DicCoolInfo"))


//CoolDownData
#define CoolDownData_GetCoolTime (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", OBFUSCATE("CoolDownData"), OBFUSCATE("GetCoolTime"))


int GetBattleState() {
	auto instance = *(uintptr_t *) ((uintptr_t)LogicBattleManager_Instance);
    if (!instance) return 0;
    return reinterpret_cast<int(__fastcall *)(void*)>(LogicBattleManager_GetBattleState)((void*)instance);
}


uintptr_t GetPlayerLogic(uint id) {
    auto instance = *(uintptr_t *) ((uintptr_t)LogicBattleManager_Instance);
    if (!instance) return 0;
    return reinterpret_cast<uintptr_t(__fastcall *)(void *, uint)>(LogicBattleManager_GetPlayerLogic)((void *)instance, id);
}


int GetCoolTime(void* instance) {
    return reinterpret_cast<int(__fastcall *)(void *)>(CoolDownData_GetCoolTime)(instance);
}

bool get_InTransformation(void* instance) {
    return reinterpret_cast<bool(__fastcall *)(void *)>(ShowEntity_get_InTransformation)(instance);
}

//Unlock Skin -> Mencoba
//Class UIRankHero.ChangeShow
#define UIRankHero_ChangeShow_iSelfHero (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIRankHero/ChangeShow"), OBFUSCATE("iSelfHero"))

//Class BattlePlayerInfo
#define BattlePlayerInfo_lUid (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("MTTDProto"), OBFUSCATE("BattlePlayerInfo"), OBFUSCATE("lUid"))
#define BattlePlayerInfo_uiSelHero (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("MTTDProto"), OBFUSCATE("BattlePlayerInfo"), OBFUSCATE("uiSelHero"))
#define BattlePlayerInfo_uiSkinId (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("MTTDProto"), OBFUSCATE("BattlePlayerInfo"), OBFUSCATE("uiSkinId"))

//Class CmdHeroSkin
#define CmdHeroSkin__ctor (uintptr_t) (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("MTTDProto"), OBFUSCATE("CmdHeroSkin"), OBFUSCATE(".ctor"))

//Class CmdHeroStatue
#define CmdHeroStatue__ctor (uintptr_t) (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("MTTDProto"), OBFUSCATE("CmdHeroStatue"), OBFUSCATE(".ctor"))

//Class SystemData,
#define SystemData_GetHeroSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("GetHeroSkin"), 2)
#define SystemData_GetMCLimitSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("GetMCLimitSkin"), 1)
#define SystemData_GetHeroHolyStatue (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("GetHeroHolyStatue"), 2)
#define SystemData_IsCanUseSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsCanUseSkin"), 1)
#define SystemData_IsHaveSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsHaveSkin"), 1)
#define SystemData_IsHaveSkinForever (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsHaveSkinForever"), 1)
#define SystemData_IsHaveStatue (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsHaveStatue"), 1)
#define SystemData_IsHaveStatueForever (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsHaveStatueForever"), 1)
#define SystemData_IsForbidStatue (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsForbidStatue"), 1)
#define SystemData_IsForbidSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsForbidSkin"), 1)
#define SystemData_IsForbidARSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsForbidARSkin"), 1)
#define SystemData_CheckReputationUnlockSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("CheckReputationUnlockSkin"), 1)
#define SystemData_GetStarSkinRank (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("GetStarSkinRank"),1)

#define SystemData_IsLimitActiveHero (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsLimitActiveHero"), 1)
#define SystemData_IsActivityForbidHeros (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsActivityForbidHeros"), 1)
#define SystemData_IsForbidHeroInChooseHero (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsForbidHeroInChooseHero"), 1)
#define SystemData_IsForbidHeros (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("IsForbidHeros"),1)

//Class UIChooseHero
#define UIChooseHero_SendSelectSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ChooseHeroMgr"), OBFUSCATE("SendSelectSkin"), 2)
#define UIChooseHero_SaveSelectHeroSkinId (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ChooseHeroMgr"), OBFUSCATE("SaveSelectHeroSkinId"), 2)
#define ChooseHeroMgr_BCustomRoomFreeSkill (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ChooseHeroMgr"), OBFUSCATE("BCustomRoomFreeSkill"), 0)
#define ChooseHeroMgr_OnSetSelfBattlePlayerInfo (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ChooseHeroMgr"), OBFUSCATE("OnSetSelfBattlePlayerInfo"), 1)
#define UIDataUtil_IsHeroInShop (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIDataUtil"), OBFUSCATE("IsHeroInShop"), 1)

//Class UIRankHero
#define UIRankHero_BatttleSelectSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIRankHero"), OBFUSCATE("BatttleSelectSkin"), 2)
#define UIRankHero_BatttleSelectSkin2 (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIChooseHero"), OBFUSCATE("BatttleSelectSkin"), 2)

#define UIRankHero_RefreshSkinDic (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIRankHero"), OBFUSCATE("RefreshSkinDic"), 3)
#define UIRankHero_RefreshHeroSkinShow (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIRankHero/RankingHeroShow"), OBFUSCATE("RefreshHeroSkinShow"), 3)

//Class UIRankHero.ChangeShow
#define UIRankHero_ChangeShow_TrySendUseSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIRankHero/ChangeShow"), OBFUSCATE("TrySendUseSkin"), 2)
#define UIRankHero_ChangeShow_SendUseSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIRankHero/ChangeShow"), OBFUSCATE("SendUseSkin"), 2)


//Class BattleReceiveMessage
#define BattleReceiveMessage_SetPlayerData (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleReceiveMessage"), OBFUSCATE("SetPlayerData"), 2)
#define BattleReceiveMessage_SetPlayerData_ (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleReceiveMessage"), OBFUSCATE("SetPlayerData"), 1)
#define BattleReceiveMessage_AddPlayerInfo (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleReceiveMessage"), OBFUSCATE("AddPlayerInfo"), 4)
#define BattleReceiveMessage_AddPlayerInfo_ (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BattleReceiveMessage"), OBFUSCATE("AddPlayerInfo"), 2)
#define BattleReceiveMessage_SendBattleData (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleReceiveMessage", "SendBattleData", 4)
#define GameReceiveMessage_SendGameData (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "GameReceiveMessage", "SendGameData", 3)
#define GameReceiveMessage_SendGameRawData (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "GameReceiveMessage", "_SendGameRawData", 6)

//Class GameServerConfig
#define GameServerConfig_SendRawData (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("GameServerConfig"), OBFUSCATE("SendRawData"), 8)
#define GameServerConfig_SendData2 (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("GameServerConfig"), OBFUSCATE("SendData"), 6)
#define GameServerConfig_IsChannel_dfjz (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("GameServerConfig"), OBFUSCATE("IsChannel_dfjz"), 0)
#define SystemData_GetExpiredCardSkinLimitTime (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("GetExpiredCardSkinLimitTime"), 1)
#define SystemData_GetLeaderSkinBForbid (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData"), OBFUSCATE("GetLeaderSkinBForbid"), 1)
#define UIRankHero_BRankHeroCanUse (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIRankHero"), OBFUSCATE("BRankHeroCanUse"), 1)
#define StarMemberData_ContainSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("StarMemberData"), OBFUSCATE("ContainSkin"), 1)
#define UIChooseHero_CheckHeroDefaultSkin (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("UIChooseHero"), OBFUSCATE("CheckHeroDefaultSkin"),1)

#define ShowSelfPlayer_TryUseSkill (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowSelfPlayer"), OBFUSCATE("TryUseSkill"), 9)
#define ShowSelfPlayer_OnUpdate (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowSelfPlayer"), OBFUSCATE("OnUpdate"))





