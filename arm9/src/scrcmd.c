#include "global.h"
#include "scrcmd.h"
#include "PAD_pad.h"
#include "bag.h"
#include "bg_window.h"
#include "camera.h"
#include "constants/global_fieldmap.h"
#include "constants/items.h"
#include "constants/sndseq.h"
#include "constants/weather.h"
#include "fashion_case.h"
#include "hall_of_fame.h"
#include "main.h"
#include "message_format.h"
#include "options.h"
#include "party.h"
#include "player_data.h"
#include "poketch.h"
#include "pokedex.h"
#include "render_window.h"
#include "save.h"
#include "seal.h"
#include "task.h"
#include "text.h"
#include "text_02054590.h"
#include "unk_0200CA44.h"
#include "unk_020139D8.h"
#include "unk_020337E8.h"
#include "unk_020377F0.h"
#include "unk_0204AF24.h"
#include "unk_0205EC84.h"
#include "unk_0208890C.h"

extern void *FieldSysGetAttrAddr(FieldSystem *fieldSystem, enum ScriptEnvField id);
extern ScriptContext *CreateScriptContext(FieldSystem *fieldSystem, u16 id);
extern u32 MapObject_GetID(LocalMapObject *lastInteracted);
extern void FlagSet(FieldSystem *fieldSystem, u16 flag);
extern void FlagClear(FieldSystem *fieldSystem, u16 flag);
extern u8 FlagCheck(FieldSystem *fieldSystem, u16 flag);
extern void TrainerFlagSet(FieldSystem *fieldSystem, u16 flag);
extern void TrainerFlagClear(FieldSystem *fieldSystem, u16 flag);
extern u8 TrainerFlagCheck(FieldSystem *fieldSystem, u16 flag);
extern void ov05_ShowMessageInField(ScriptContext *ctx, MsgData *msgData, u16 id);
extern void ov05_021E2BD0(ScriptContext *ctx, MsgData *msgData, u16 msgId, u32 param4, void *param5);
extern void ov05_021E2C58(ScriptContext *ctx, u16 typ, u16 id, u16 word1, s16 word2, u8 param5);
extern MessageFormat *ov06_02244210(SaveData *sav, u16 poke, u16 sex, u8 flag, u8 *unk);
extern void ov05_021E2CBC(ScriptContext *ctx, MessageFormat *messageFormat, u8 param2, u32 param3);
extern void ov05_021E2BB8(void *param0, ScriptContext *ctx);
extern u32 sub_02058488(LocalMapObject *lastInteracted);
extern BOOL sub_02030F40(void);
extern void sub_02055304(PlayerAvatar *playerAvatar, u32 param1);
extern void sub_02039460(FieldSystem *arg);
extern u32 sub_02058510(LocalMapObject *event, u32 param1);
extern void ov05_021E8128(u32 param0, u8 type, u16 map);
extern void ov05_021E8130(u32 param0, u32 param1);
extern void ov05_021E8158(FieldSystem *fieldSystem);
extern Window *ov05_021E8140(u32 param0);
extern BOOL ov05_021E8148(u32 param0);
extern void ov05_021E8144(u32 param0);
extern u32 Std_CreateYesNoMenu(BgConfig *param0, u8 **param1, u32 param2, u32 param3, u32 param4);
extern u32 sub_020021AC(u32 param0, u32 param1);
extern u32 ov05_021E1BF8(FieldSystem *fieldSystem, u8 param1, u8 param2, u8 param3, u8 param4, u16 *param5, MessageFormat *messageFormat, Window *window, MsgData *msgData);
extern void ov05_021E1C4C(u32 param0, u32 param1, u32 param2);
extern void ov05_021E1C54(u32 param0);
extern u32 sub_02052714(u32 param0);
extern void ov05_021E1ECC(u32 param0);
extern u32 ov05_021E1F34(FieldSystem *fieldSystem, u8 param1, u8 param2, u8 param3, u8 param4, u16 *param5, MessageFormat *messageFormat, Window *window, MsgData *msgData);
extern void ov05_021E1F58(u32 param0, u8 param1, u8 param2, u8 param3);
extern void ov05_021E1F60(u32 param0);
extern void ov05_021E26CC(u32 param0, u8 param1);
extern void ov05_021E2B80(u32 param0, u8 param1);
extern void ov05_021E2B9C(u32 param0, u8 param1);
extern u32 sub_0205AEA4(LocalMapObject *event, const void *ptr);
extern u32 sub_02058B2C(LocalMapObject *event);
extern u32 sub_02058B4C(LocalMapObject *event);
extern LocalMapObject *sub_020580B4(MapObjectManager *mapObjectManager, u32 param1);
extern LocalMapObject *GetMapObjectByID(MapObjectManager *mapObjectManager, u16 eventId);
extern BOOL sub_0205AEF0(u32 param0);
extern void sub_0205AEFC(u32 param0);
extern void sub_02058780(MapObjectManager *mapObjectManager);
extern LocalMapObject *PlayerAvatar_GetMapObject(PlayerAvatar *playerAvatar);
extern u32 sub_0205AE28(LocalMapObject *event);
extern void sub_02058908(LocalMapObject *event);
extern u32 sub_02058854(LocalMapObject *event);
extern LocalMapObject *sub_0205E7C4(LocalMapObject *event);
extern void sub_02058914(LocalMapObject *event);
extern void sub_020587B0(MapObjectManager *mapObjectManager);
extern u32 sub_02034B64(FieldSystem *fieldSystem);
extern u32 sub_02034B6C(FieldSystem *fieldSystem);
extern u32 sub_020575D4(MapObjectManager *mapObjectManager, u16 eventVar, u32 param2, u32 mapId, u32 param4);
extern void sub_02057688(LocalMapObject *event);
extern LocalMapObject *sub_0205753C(MapObjectManager *mapObjectManager, u16 x, u16 y, u16 z, u32 param4, u32 param5, u32 mapId);
extern u32 sub_02059D1C(LocalMapObject *target);
extern LocalMapObject *sub_0205889C(LocalMapObject *target, u32 param1);
extern LocalMapObject *sub_020588B8(LocalMapObject *target, u32 param1);
extern VecFx32 *sub_02058B7C(LocalMapObject *target);
extern void ov05_021EF5E0(VecFx32 *target, u32 param1);
extern void sub_02057654(LocalMapObject *target);
extern u32 PlayerAvatar_GetFacingDirection(PlayerAvatar *playerAvatar);
extern u32 sub_02059E74(u32 direction);
extern void ov05_021F1EC0(LocalMapObject *event, u32 param1);
extern u16 GetPlayerXCoord(PlayerAvatar *playerAvatar);
extern u16 GetPlayerYCoord(PlayerAvatar *playerAvatar);
extern void sub_02058BB4(LocalMapObject *event, VecFx32 *param1);
extern void sub_02058994(LocalMapObject *event, u8 value);
extern void sub_02058E90(LocalMapObject *event, u16 movement);
extern u16 sub_02058480(LocalMapObject *event);
extern void sub_02058EB0(LocalMapObject *event, u32 param1);
extern u16 sub_02029E0C(SealCase *sealCase);
extern u16 SealCase_CountSealOccurrenceAnywhere(SealCase *sealCase, u16 sealId);
extern void sub_02029D44(SealCase *sealCase, u16 sealId, s16 amount);
extern PartyMenuAppData *sub_020379F8(u32 param0, FieldSystem *fieldSystem);
extern PartyMenuAppData *sub_02037A1C(u32 param0, FieldSystem *fieldSystem);
extern PartyMenuAppData *sub_02037B44(TaskManager *taskManager, u32 param1);
extern u16 sub_02037A40(PartyMenuAppData *partyMenu);
extern u16 sub_02037A70(PartyMenuAppData *partyMenu);
extern void *sub_02037BB0(u32 param0, FieldSystem *fieldSystem, u16 param2, u16 param3, u16 param4, u16 param5);
extern void *sub_02037C00(u32 param0, FieldSystem *fieldSystem, u16 param2);
extern u16 sub_02037A78(void *runningAppData);
extern u16 ov05_021E1858(FieldSystem *fieldSystem, LocalMapObject *event, u16 param2);
extern u32 sub_02029048(u32 param0);
extern void sub_02028AD4(u32 *param0, u32 param1, u32 param2);
extern void sub_0204AF3C(TaskManager *taskManager);
extern SaveFashionData *Save_FashionData_Get(SaveData *save);
extern BOOL CheckPortraitSlotFull(SaveFashionData *fashionData, u32 portraitSlot);
extern BOOL CheckContestPortraitSlotFull(SaveFashionData *fashionData, u32 portraitSlot);
extern void ov05_021F02C4(FieldSystem *fieldSystem);
extern void sub_0206F3B8(TaskManager *taskManager);
extern u16 sub_02031190(void);
extern void Script_SetMonSeenFlagBySpecies(FieldSystem *fieldSystem, u16 species);
extern void ov05_021E1374(TaskManager *taskManager, MessageFormat *messageFormat, u16 *ptr);
extern void ov05_021E1994(FieldSystem *fieldSystem, LocalMapObject *lastInteracted);
extern void sub_0208A338(TaskManager *taskManager);
extern void sub_020380CC(TaskManager *taskManager, u16 *param1, SaveData *save, u16 partyPos, u16 param4);
extern void sub_02038130(FieldSystem *fieldSystem, FashionAppData *fashionData);
extern u32 sub_02027008(SaveFashionData *fashionData, u32 param1);
extern void sub_02027478(u32 param0, u16 param1);
extern void ShowGeonetScreen(FieldSystem *fieldSystem);
extern void ShowSealCapsuleEditor(TaskManager *taskManager, SaveData *save);
extern void sub_0205F7A0(FieldSystem *fieldSystem, TownMapAppData *townMap, u32 param2); //TownMap_Init?
extern void sub_02037E90(FieldSystem *fieldSystem, TownMapAppData *townMap); //ShowTownMap?
extern u32 sub_02028048(SaveData *save);
extern u32 sub_020281B8(u32 param0);
extern void sub_02037FE4(FieldSystem *fieldSystem, ScrCmdUnkStruct01D9 *param1);
extern void LaunchStoragePCInterface(FieldSystem *fieldSystem, PCBoxAppData *pcBoxAppData);
extern void sub_020383F8(FieldSystem *fieldSystem);
extern void sub_02065344(FieldSystem *fieldSystem);
extern void sub_020383D8(TaskManager *taskManager);
extern void *sub_0203842C(FieldSystem *fieldSystem);
extern void CallTask_GameClear(TaskManager *taskManager);
extern HallOfFame *sub_02038824(FieldSystem *fieldSystem);
extern void sub_020386E0(FieldSystem *fieldSystem, u16 param1);
extern void sub_0206F3D8(TaskManager *taskManager, u16 *param1);
extern void sub_020386A4(FieldSystem *fieldSystem, StarterSelectionData *starterSelectionData); 
extern void sub_0205F378(ScriptState *flags, u16 state);
extern BagScreenAppData *sub_0203789C(FieldSystem *fieldSystem, u8 mode);
extern u16 sub_020378FC(BagScreenAppData *bagScreenAppData);
extern void sub_02037E18(TaskManager *taskManager, u16 *param1, u16 *param2, u16 *param3);
extern void BeginNormalPaletteFade(u32 pattern, u32 typeTop, u32 typeBottom, u16 colour, u32 duration, u32 framesPer, u32 heapId);
extern void sub_0200E388(u32 param0);
extern BOOL IsPaletteFadeFinished(void);
extern void CallTask_ScriptWarp(TaskManager *taskManager, u16 mapId, s32 param2, u16 x, u16 y, u16 dir);
extern void sub_02049F98(TaskManager *taskManager, u16 mapId, s32 param2, u16 x, u16 y, u16 dir);
extern void sub_02049FFC(TaskManager *taskManager);
extern LocalFieldData *Save_LocalFieldData_Get(SaveData *save);
extern Location *sub_02034DC8(LocalFieldData *localFieldData);
extern void CallFieldTask_RockClimb(TaskManager *taskManager, u32 playerDirection, u16 partyPosition);
extern void sub_0205DD40(u32 param0);
extern void CallFieldTask_Surf(TaskManager *taskManager, u32 playerDirection, u16 partyPosition);
extern void sub_02049274(FieldSystem *fieldSystem, u16 mapId, s32 warpId, u16 x, u16 y, u32 direction);
extern u32 LocalFieldData_GetWeatherType(LocalFieldData *localFieldData);
extern void ov05_021DC174(u32 param0, u32 weather);
extern void LocalFieldData_SetWeatherType(LocalFieldData *localFieldData, u32 weather);
extern void CallFieldTask_Waterfall(TaskManager *taskManager, u32 playerDirection, u16 partyPosition);
extern u32 PlayerAvatar_GetGender(PlayerAvatar *avatar);
extern void *ov06_0224666C(FieldSystem *fieldSystem, u32 param1, Pokemon *mon, u32 playerGender);
extern BOOL ov06_022466A0(void *param0);
extern void ov06_022466AC(void *param0);
extern void ov05_021E7030(TaskManager *taskManager);
extern u32 PlayerAvatar_GetState(PlayerAvatar *avatar);
extern void FieldSystem_SetSavedMusicId(FieldSystem *fieldSystem, u16 musicId);
extern void FieldSystem_PlayOrFadeToNewMusicId(FieldSystem *fieldSystem, u16 musicId, u32 param2);
extern void Field_PlayerAvatar_OrrTransitionFlags(PlayerAvatar *playerAvatar, u32 transitionFlags);
extern void Field_PlayerAvatar_ApplyTransitionFlags(PlayerAvatar *playerAvatar);
extern u16 FieldSystem_GetOverriddenMusicId(FieldSystem *fieldSystem, u32 mapId);
extern void sub_02055720(PlayerAvatar *avatar, u8 action);
extern void PlayerAvatar_OrrTransitionFlags(PlayerAvatar *playerAvatar, u32 transitionFlags);
extern RoamerSaveData *Save_Roamers_Get(SaveData *save);
extern u32 Roamers_GetRand(RoamerSaveData *roamerSaveData, u32 index);
extern void GetSwarmInfoFromRand(u32 rand, u16 *map, u16 *species);
extern u16 ScriptState_GetStarter(ScriptState *state);
extern u32 ov06_022407DC(void);
extern void ov06_02240790(FieldSystem *fieldSystem, u16 param1, u16 param2, u16 param3);
extern void ov06_022407F8(FieldSystem *fieldSystem, u16 param1, u16 param2, u16 param3);
extern u32 ov06_02240844(void);
extern void sub_02047174(TaskManager *taskManager, u32 *param1, u32 param2);
extern void LocalFieldData_SetDynamicWarp(LocalFieldData *localFieldData, Location *warp);
extern void sub_02080C38(TaskManager *taskManager);
extern Location *LocalFieldData_GetDynamicWarp(LocalFieldData *localFieldData);
extern u16 MapNumToFloorNo(u32 mapId);
extern void PrintCurrentFloorInNewWindow(FieldSystem *fieldSystem, u32 x, u32 y, u16 *var, MessageFormat *messageFormat);
extern u16 sub_02054CC8(u32 param0, u16 param1);
extern u16 sub_02054D1C(u32 param0, u16 param1);
extern void SetupAndStartWildBattle(TaskManager *taskManager, u16 species, u8 level, u32 *winFlag, BOOL isLegendary);
extern void SetupAndStartFirstBattle(TaskManager *taskManager, u16 species, u8 level);
extern void SetupAndStartTutorialBattle(TaskManager *taskManager);
extern void UpdateHoneyTree(FieldSystem *fieldSystem);
extern u16 CheckHoneyTree(FieldSystem *fieldSystem);
extern void SetupAndStartHoneyTreeBattle(TaskManager *taskManager, u32 *winFlag);
extern void ov05_021F4E7C(FieldSystem *fieldSystem);
extern void sub_020386B4(FieldSystem *fieldSystem);
extern u16 Field_SaveGame(FieldSystem *fieldSystem);
extern void Field_GivePoketch(TaskManager *taskManager);
extern void sub_02031588(u8 param0);
extern s32 sub_02030F20(void);
extern BOOL sub_020315D8(u8 param0);
extern void sub_0203168C(void);
extern u16 sub_0205296C(MessageFormat *messageFormat);
extern u16 sub_02052C0C(u32 param0, MessageFormat *messageFormat);
extern void sub_02031C54(void);
extern void sub_02031C64(void);
extern void sub_02052B74(u16 param0);
extern void sub_02052D08(MessageFormat *messageFormat, u32 unk0, u16 objId, PlayerProfile *playerProfile, SaveEasyChat *easyChat);
extern void sub_0208881C(FieldSystem *fieldSystem);
extern void sub_02052F74(u32 param0);
extern void sub_02031B50(void);
extern u16 sub_020527A8(u32 param0);
extern u16 sub_02052A10(u32 param0, u32 objectId, u32 param2, MessageFormat *messageFormat);
extern u16 sub_020524CC(u32 param0, u32 objectId);
extern u16 sub_02052544(u32 param0, u32 objectId, u32 param2);
extern u32 sub_02052604(u32 param0);
extern void sub_020534DC(MapObjectManager *mapObjectManager, u32 param1);
extern void sub_02031C2C(void);
extern void sub_0205265C(u32 param0, u32 param1, u32 param2);
extern u32 sub_02052608(u32 param0);
extern void sub_02052E10(u32 param0);
extern u32 sub_02052648(u32 param0);
extern u32 sub_02052718(u32 param0, u32 param1);
extern void sub_0205363C(u32 trainerId, PlayerGender playerGender, MessageFormat *messageFormat);
extern u16 sub_02053678(u32 trainerId, PlayerGender playerGender, u32 param2);
extern u16 sub_020536D0(PlayerGender playerGender, u16 param1, u16 param2);
extern void sub_02049EA4(TaskManager *taskManager);
extern void LocalFieldData_SetBlackoutSpawn(LocalFieldData *localFieldData, u16 spawnPoint);
extern void CallFieldTask_BlackOut(TaskManager *taskManager);
extern void HealParty(PlayerParty *playerParty);
extern void sub_02050024(void);
extern u32 sub_02031810(void);
extern u32 sub_0202EDF8(void);
extern void sub_02050048(void);
extern void sub_0204FF5C(FieldSystem *fieldSystem);
extern void sub_0204F6DC(u16 param0);
extern void SetEventDefaultXYPos(FieldSystem *fieldSystem, u16 objectId, u16 x, u16 y);
extern void sub_02058E28(LocalMapObject *object, u16 x, u16 z, u16 y, u16 direction);
extern void SetEventDefaultDirection(FieldSystem *fieldSystem, u16 objectId, u16 direction);
extern void SetWarpXYPos(FieldSystem *fieldSystem, u16 warpId, u16 x, u16 y);
extern void SetBgEventXYPos(FieldSystem *fieldSystem, u16 bgEventId, u16 x, u16 y);
extern void SetEventDefaultMovement(FieldSystem *fieldSystem, u16 objectId, u16 movement);

u8 UNK_021C5A0C[4];

extern u8 *UNK_020F34E0;

static BOOL RunPauseTimer(ScriptContext *ctx);
static u32 Compare(u16 a, u16 b);
static BOOL sub_02039CC8(ScriptContext *ctx);
static BOOL sub_0203A2F0(ScriptContext *ctx);
static BOOL sub_0203A46C(ScriptContext *ctx);
static BOOL sub_0203A4AC(ScriptContext *ctx);
static BOOL sub_0203A4E0(ScriptContext *ctx);
static BOOL sub_0203A570(ScriptContext *ctx);
static BOOL sub_0203A6C8(ScriptContext *ctx);
static BOOL sub_0203A8A0(ScriptContext *ctx);
static BOOL sub_0203A94C(ScriptContext *ctx);
static BOOL sub_0203AA0C(ScriptContext *ctx);
static BOOL sub_0203AB00(ScriptContext *ctx);
static BOOL sub_0203AD2C(ScriptContext *ctx);
static BOOL sub_0203AD78(ScriptContext *ctx);
static LocalMapObject *sub_0203B120(FieldSystem *fieldSystem, u16 eventId);
static BOOL IsAllMovementFinished(ScriptContext *ctx);
static void sub_0203B174(FieldSystem *fieldSystem, u32 param1, void *param2);
static void sub_0203B1A8(u32 param0, UnkStruct_0203B174 *param1);
static BOOL sub_0203B218(ScriptContext *ctx);
/*static*/ BOOL sub_0203BB90(ScriptContext *ctx);
static BOOL sub_0203BBBC(ScriptContext *ctx);
/*static*/ BOOL sub_0203BC04(ScriptContext *ctx);
static BOOL CheckPortraitSlotFullInternal(FieldSystem *fieldSystem, BOOL isContest, u32 portraitSlot);
static FashionAppData *sub_0203BC6C(u32 heapId, FieldSystem *fieldSystem, BOOL isContest, u32 portraitSlot);
static BOOL sub_0203BE9C(ScriptContext *ctx);
static BOOL sub_0203C71C(ScriptContext *ctx);
static BOOL sub_0203C9F8(ScriptContext *ctx);
static BOOL sub_0203CCF8(ScriptContext *ctx);
static BOOL sub_0203CD90(ScriptContext *ctx);
static BOOL sub_0203D314(ScriptContext *ctx);
static BOOL sub_0203D47C(ScriptContext *ctx);
static BOOL sub_0203D5CC(ScriptContext *ctx);
static BOOL sub_0203D688(ScriptContext *ctx);
static BOOL sub_0203D6E0(ScriptContext *ctx);
static BOOL sub_0203D904(ScriptContext *ctx);

extern u8 sScriptConditionTable[6][3];

BOOL ScrCmd_Nop(ScriptContext *ctx) //0000
{
#pragma unused(ctx)
    return FALSE;
}

BOOL ScrCmd_Dummy(ScriptContext *ctx) //0001
{
#pragma unused(ctx)
    return FALSE;
}

BOOL ScrCmd_End(ScriptContext *ctx) //0002
{
    StopScript(ctx);
    return FALSE;
}

BOOL ScrCmd_Wait(ScriptContext *ctx) //0003
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 num = ScriptReadHalfword(ctx);
    u16 wk = ScriptReadHalfword(ctx);
    u16* VarPointer = GetVarPointer(fieldSystem, wk);
    *VarPointer = num;
    ctx->data[0] = wk;
    SetupNativeScript(ctx, RunPauseTimer);
    return TRUE;
}

static BOOL RunPauseTimer(ScriptContext *ctx)
{
    u16* VarPointer = GetVarPointer(ctx->fieldSystem, (u16)ctx->data[0]);
    *VarPointer = (u16)(*VarPointer - 1);
    return !(*VarPointer);
}

BOOL ScrCmd_DebugWatch(ScriptContext *ctx) //01F9
{
    ScriptGetVar(ctx);
    return FALSE;
}

BOOL ScrCmd_LoadByte(ScriptContext *ctx) //0004
{
    u8 index = ScriptReadByte(ctx);
    ctx->data[index] = ScriptReadByte(ctx);
    return FALSE;
}

BOOL ScrCmd_LoadWord(ScriptContext *ctx) //0005
{
    u8 index = ScriptReadByte(ctx);
    ctx->data[index] = ScriptReadWord(ctx);
    return FALSE;
}

BOOL ScrCmd_LoadByteFromAddr(ScriptContext *ctx) //0006
{
    u8 index = ScriptReadByte(ctx);
    ctx->data[index] = *(u8 *)ScriptReadWord(ctx);
    return FALSE;
}

BOOL ScrCmd_WriteByteToAddr(ScriptContext *ctx) //0007
{
    u8* ptr = (u8*)ScriptReadWord(ctx);
    *ptr = ScriptReadByte(ctx);
    return FALSE;
}

BOOL ScrCmd_SetPtrByte(ScriptContext *ctx) //0008
{
    u8* ptr = (u8*)ScriptReadWord(ctx);
    *ptr = (u8)ctx->data[ScriptReadByte(ctx)];
    return FALSE;
}

BOOL ScrCmd_CopyLocal(ScriptContext *ctx) //0009
{
    u8 index_store = ScriptReadByte(ctx);
    u8 index_load = ScriptReadByte(ctx);
    ctx->data[index_store] = ctx->data[index_load];
    return FALSE;
}

BOOL ScrCmd_CopyByte(ScriptContext *ctx) //000A
{
    u8 *target = (u8 *)ScriptReadWord(ctx);
    u8 *source = (u8 *)ScriptReadWord(ctx);
    *target = *source;
    return FALSE;
}

static u32 Compare(u16 a, u16 b)
{
    if (a < b)
    {
        return 0;
    }
    else if (a == b)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

BOOL ScrCmd_CompareLocalToLocal(ScriptContext *ctx) //000B
{
    u8 a = (u8)ctx->data[ScriptReadByte(ctx)];
    u8 b = (u8)ctx->data[ScriptReadByte(ctx)];
    ctx->comparisonResult = (u8)Compare(a, b);
    return FALSE;
}

BOOL ScrCmd_CompareLocalToValue(ScriptContext *ctx) //000C
{
    u8 a = (u8)ctx->data[ScriptReadByte(ctx)];
    u8 b = ScriptReadByte(ctx);
    ctx->comparisonResult = (u8)Compare(a, b);
    return FALSE;
}

BOOL ScrCmd_CompareLocalToAddr(ScriptContext *ctx) //000D
{
    u8 a = (u8)ctx->data[ScriptReadByte(ctx)];
    u8 b = *(u8*)ScriptReadWord(ctx);
    ctx->comparisonResult = (u8)Compare(a, b);
    return FALSE;
}

BOOL ScrCmd_CompareAddrToLocal(ScriptContext *ctx) //000E
{
    u8 a = *(u8*)ScriptReadWord(ctx);
    u8 b = (u8)ctx->data[ScriptReadByte(ctx)];
    ctx->comparisonResult = (u8)Compare(a, b);
    return FALSE;
}

BOOL ScrCmd_CompareAddrToValue(ScriptContext *ctx) //000F
{
    u8 a = *(u8*)ScriptReadWord(ctx);
    u8 b = (u8)ScriptReadByte(ctx);
    ctx->comparisonResult = (u8)Compare(a, b);
    return FALSE;
}

BOOL ScrCmd_CompareAddrToAddr(ScriptContext *ctx) //0010
{
    u8 a = *(u8*)ScriptReadWord(ctx);
    u8 b = *(u8*)ScriptReadWord(ctx);
    ctx->comparisonResult = (u8)Compare(a, b);
    return FALSE;
}

BOOL ScrCmd_CompareVarToValue(ScriptContext *ctx) //0011
{
    u16 a = *ScriptGetVarPointer(ctx);
    u16 b = ScriptReadHalfword(ctx);
    ctx->comparisonResult = (u8)Compare(a, b);
    return FALSE;
}

BOOL ScrCmd_CompareVarToVar(ScriptContext *ctx) //0012
{
    u16 *a = ScriptGetVarPointer(ctx);
    u16 *b = ScriptGetVarPointer(ctx);
    ctx->comparisonResult = (u8)Compare(*a, *b);
    return FALSE;
}

BOOL ScrCmd_RunScript(ScriptContext *ctx) //0013
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *activeScriptContextsNumber = (u8 *)FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_ACTIVE_SCRIPTCONTEXT_COUNT);
    ScriptContext **scriptContext1 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SCRIPT_CONTEXT_1);
    u16 id = ScriptReadHalfword(ctx);

    *scriptContext1 = CreateScriptContext(fieldSystem, id);
    (*activeScriptContextsNumber)++;
    return TRUE;
}

BOOL ScrCmd_RunScriptWait(ScriptContext *ctx) //0014
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *unk1 = (u8 *)FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_UNKNOWN_05);
    u8 *activeScriptContextsNumber = (u8 *)FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_ACTIVE_SCRIPTCONTEXT_COUNT);
    ScriptContext **scriptContext1 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SCRIPT_CONTEXT_1);

    u16 id = ScriptReadHalfword(ctx);
    *unk1 = 1;
    *scriptContext1 = CreateScriptContext(fieldSystem, id);
    (*activeScriptContextsNumber)++;

    SetupNativeScript(ctx, sub_02039CC8);
    return TRUE;
}

static BOOL sub_02039CC8(ScriptContext *ctx)
{
    u8* unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_UNKNOWN_05);

    if (*unk == 0)
    {
        return TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_RestartCurrentScript(ScriptContext *ctx) //0015
{
    u8* unk = (u8 *)FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_UNKNOWN_05);

    *unk = 0;
    return FALSE;
}

BOOL ScrCmd_GoTo(ScriptContext *ctx) //0016
{
    s32 offset = (s32)ScriptReadWord(ctx);
    ScriptJump(ctx, ctx->scriptPtr + offset);
    return FALSE;
}

BOOL ScrCmd_ObjectGoTo(ScriptContext *ctx) //0017
{
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u8 id = ScriptReadByte(ctx);
    s32 offset = (s32)ScriptReadWord(ctx);
    if (MapObject_GetID(*lastInteracted) == id)
    {
        ScriptJump(ctx, ctx->scriptPtr + offset);
    }
    return FALSE;
}

BOOL ScrCmd_BgGoTo(ScriptContext *ctx) //0018
{
    u32 bgId = sub_02046534(ctx->taskManager);
    u8 id = ScriptReadByte(ctx);
    s32 offset = (s32)ScriptReadWord(ctx);

    if (bgId == id)
    {
        ScriptJump(ctx, ctx->scriptPtr + offset);
    }
    return FALSE;
}

BOOL ScrCmd_DirectionGoTo(ScriptContext *ctx) //0019
{
    u32 *playerDirection = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_FACING_DIRECTION);
    u8 dir = ScriptReadByte(ctx);
    s32 offset = (s32)ScriptReadWord(ctx);

    if (*playerDirection == dir)
    {
        ScriptJump(ctx, ctx->scriptPtr + offset);
    }
    return FALSE;
}

BOOL ScrCmd_Call(ScriptContext *ctx) //001A
{
    s32 offset = (s32)ScriptReadWord(ctx);
    ScriptCall(ctx, ctx->scriptPtr + offset);
    return FALSE;
}

BOOL ScrCmd_Return(ScriptContext *ctx) //001B
{
    ScriptReturn(ctx);
    return FALSE;
}

BOOL ScrCmd_GoToIf(ScriptContext *ctx) //001C
{
    u8 compareType = ScriptReadByte(ctx);
    s32 offset = (s32)ScriptReadWord(ctx);

    if (sScriptConditionTable[compareType][ctx->comparisonResult] == TRUE)
    {
        ScriptJump(ctx, ctx->scriptPtr + offset);
    }
    return FALSE;
}

BOOL ScrCmd_CallIf(ScriptContext *ctx) //001D
{
    u8 compareType = ScriptReadByte(ctx);
    s32 offset = (s32)ScriptReadWord(ctx);

    if (sScriptConditionTable[compareType][ctx->comparisonResult] == TRUE)
    {
        ScriptCall(ctx, ctx->scriptPtr + offset);
    }
    return FALSE;
}

BOOL ScrCmd_SetFlag(ScriptContext *ctx) //001E
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag = ScriptReadHalfword(ctx);
    FlagSet(fieldSystem, flag);
    return FALSE;
}

BOOL ScrCmd_ClearFlag(ScriptContext *ctx) //001F
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag = ScriptReadHalfword(ctx);
    FlagClear(fieldSystem, flag);
    return FALSE;
}

BOOL ScrCmd_CheckFlag(ScriptContext *ctx) //0020
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag = ScriptReadHalfword(ctx);
    ctx->comparisonResult = FlagCheck(fieldSystem, flag);
    return FALSE;
}

BOOL ScrCmd_CheckFlagVar(ScriptContext *ctx) //0021
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *wk1 = ScriptGetVarPointer(ctx);
    u16 *wk2 = ScriptGetVarPointer(ctx);
    *wk2 = FlagCheck(fieldSystem, *wk1);
    return FALSE;
}

BOOL ScrCmd_SetFlagVar(ScriptContext *ctx) //0022
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *wk = ScriptGetVarPointer(ctx);
    FlagSet(fieldSystem, *wk);
    return FALSE;
}

BOOL ScrCmd_SetTrainerFlag(ScriptContext *ctx) //0023
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag = ScriptGetVar(ctx);
    TrainerFlagSet(fieldSystem, flag);
    return FALSE;
}

BOOL ScrCmd_ClearTrainerFlag(ScriptContext *ctx) //0024
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag = ScriptGetVar(ctx);
    TrainerFlagClear(fieldSystem, flag);
    return FALSE;
}

BOOL ScrCmd_CheckTrainerFlag(ScriptContext *ctx) //0025
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag = ScriptGetVar(ctx);
    ctx->comparisonResult = TrainerFlagCheck(fieldSystem, flag);
    return FALSE;
}

BOOL ScrCmd_AddVar(ScriptContext *ctx) //0026
{
    u16 *wk1 = ScriptGetVarPointer(ctx);
    u16 wk2 = ScriptGetVar(ctx);
    *wk1 = (u16)(*wk1 + wk2);
    return FALSE;
}

BOOL ScrCmd_SubVar(ScriptContext *ctx) //0027
{
    u16 *wk1 = ScriptGetVarPointer(ctx);
    u16 wk2 = ScriptGetVar(ctx);
    *wk1 = (u16)(*wk1 - wk2);
    return FALSE;
}

BOOL ScrCmd_SetVar(ScriptContext *ctx) //0028
{
    u16 *wk = ScriptGetVarPointer(ctx);
    *wk = ScriptReadHalfword(ctx);
    return FALSE;
}

BOOL ScrCmd_CopyVar(ScriptContext *ctx) //0029
{
    u16 *wk1 = ScriptGetVarPointer(ctx);
    u16 *wk2 = ScriptGetVarPointer(ctx);
    *wk1 = *wk2;
    return FALSE;
}

BOOL ScrCmd_SetOrCopyVar(ScriptContext *ctx) //002A - todo: better name
{
    u16 *wk1 = ScriptGetVarPointer(ctx);
    u16 wk2 = ScriptGetVar(ctx);
    *wk1 = wk2;
    return FALSE;
}

BOOL ScrCmd_Message(ScriptContext *ctx) //002B - todo: MessageAll?
{
    u8 id = ScriptReadByte(ctx);
    ov05_ShowMessageInField(ctx, ctx->msgData, id);
    return FALSE;
}

BOOL ScrCmd_MessageFrom(ScriptContext *ctx) //01FA - todo: MessageAllFromNarc?
{
    u16 arc = ScriptGetVar(ctx);
    u16 msg = ScriptGetVar(ctx);
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_MSGDATA_MSG, arc, 32);
    ov05_ShowMessageInField(ctx, msgData, msg);
    DestroyMsgData(msgData);
    return FALSE;
}

BOOL ScrCmd_MessageFrom2(ScriptContext *ctx) //01FB - todo: MessageFromNarc?
{
    u16 arc = ScriptGetVar(ctx);
    u16 msg = ScriptGetVar(ctx);
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_MSGDATA_MSG, arc, 32);
    ov05_021E2BD0(ctx, msgData, msg, 1, NULL);
    DestroyMsgData(msgData);
    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_Unk01FC(ScriptContext *ctx) //01FC
{
    u16 typ = ScriptReadHalfword(ctx);
    u16 id = ScriptReadHalfword(ctx);
    u16 word1 = ScriptReadHalfword(ctx);
    s16 word2 = (s16)ScriptReadHalfword(ctx);

    ov05_021E2C58(ctx, typ, id, word1, word2, 0xff);
    return FALSE;
}

BOOL ScrCmd_Unk01FD(ScriptContext *ctx) //01FD
{
    u16 typ = ScriptReadHalfword(ctx);
    u16 id = ScriptReadHalfword(ctx);
    u16 word1 = ScriptReadHalfword(ctx);
    s16 word2 = (s16)ScriptReadHalfword(ctx);

    ov05_021E2C58(ctx, typ, id, word1, word2, 1);
    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_Unk01FE(ScriptContext *ctx) //01FE
{
    u8 id = ScriptReadByte(ctx);

    if (ctx->fieldSystem->unkA8 == NULL)
    {
        return FALSE;
    }

    u16 *unkArr = ctx->fieldSystem->unkA8->unk90[id].unk0;
    if (unkArr[0] == 0xFFFF)
    {
        MsgData *msgdata = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_MSGDATA_MSG, 0x22b, 32);
        ov05_021E2BD0(ctx, msgdata, unkArr[1], 1, NULL);
        DestroyMsgData(msgdata);
    }
    else
    {
        ov05_021E2C58(ctx, unkArr[0], unkArr[1], unkArr[2], (s16)unkArr[3], 1);
    }
    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_Unk01FF(ScriptContext *ctx) //01FF
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 msg = ScriptReadByte(ctx);
    u16 poke = ScriptGetVar(ctx);
    u16 sex = ScriptReadHalfword(ctx);
    u8 flag = ScriptReadByte(ctx);
    u8 unk = 0;

    MessageFormat *messageFormat = ov06_02244210(fieldSystem->saveData, poke, sex, flag, &unk);
    ov05_021E2CBC(ctx, messageFormat, (u8)(msg + unk), 1);
    MessageFormat_Delete(messageFormat);

    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_MessageUnown(ScriptContext *ctx) //026D
{
    UnkStruct_0203A288 unkStruct;
    u16 msg = ScriptReadHalfword(ctx);

    ov05_021E2BB8(&unkStruct, ctx);
    unkStruct.unk2 = 3;

    ov05_021E2BD0(ctx, ctx->msgData, msg, 0, &unkStruct);
    SetupNativeScript(ctx, sub_0203A2F0);

    return TRUE;
}

BOOL ScrCmd_Unk002C(ScriptContext *ctx) //002C - todo: Message?
{
    u8 msg = ScriptReadByte(ctx);
    ov05_021E2BD0(ctx, ctx->msgData, msg, 1, NULL);
    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

static BOOL sub_0203A2F0(ScriptContext *ctx)
{
    u8 *textPrinterNumber = (u8 *)FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_TEXT_PRINTER_NUMBER);
    return sub_020546C8(*textPrinterNumber);
}

BOOL ScrCmd_Unk002D(ScriptContext *ctx) //002D - todo: MessageFromVar? MessageFlex?
{
    u16 msg = ScriptGetVar(ctx);
    ov05_021E2BD0(ctx, ctx->msgData, (u8)msg, 1, NULL);
    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_Unk02C0(ScriptContext *ctx) //02C0
{
    UnkStruct_0203A288 unkStruct;
    u16 msg = ScriptGetVar(ctx);

    ov05_021E2BB8(&unkStruct, ctx);
    unkStruct.unk1 = 1;

    ov05_021E2BD0(ctx, ctx->msgData, (u8)msg, 1, &unkStruct);
    SetupNativeScript(ctx, sub_0203A2F0);

    return TRUE;
}

BOOL ScrCmd_Unk002E(ScriptContext *ctx) //002E - todo: MessageWait? MessageNoSkip?
{
    u16 msg = ScriptGetVar(ctx);
    ov05_021E2BD0(ctx, ctx->msgData, (u8)msg, 0, NULL);
    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_Unk020C(ScriptContext *ctx) //020C
{
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u8 msg = (u8)sub_02058488(*lastInteracted);
    ov05_021E2BD0(ctx, ctx->msgData, msg, 1, NULL);
    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_Unk002F(ScriptContext *ctx) //002F
{
    u8 msg = ScriptReadByte(ctx);

    if (!sub_02030F40())
    {
        ov05_021E2BD0(ctx, ctx->msgData, msg, 1, NULL);
    }
    else
    {
        UnkStruct_0203A288 unkStruct;
        ov05_021E2BB8(&unkStruct, ctx);
        unkStruct.unk0 = 1;
        unkStruct.unk1 = 1;
        ov05_021E2BD0(ctx, ctx->msgData, msg, 0, &unkStruct);
    }

    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_WaitButtonAB(ScriptContext *ctx) //0030
{
    SetupNativeScript(ctx, sub_0203A46C);
    return TRUE;
}

static BOOL sub_0203A46C(ScriptContext *ctx)
{
#pragma unused(ctx)
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B))
    {
        return TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_WaitButtonABTime(ScriptContext *ctx) //0190
{
    ctx->data[0] = ScriptGetVar(ctx);
    SetupNativeScript(ctx, sub_0203A4AC);
    return TRUE;
}

static BOOL sub_0203A4AC(ScriptContext *ctx)
{
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B))
    {
        return TRUE;
    }
    ctx->data[0] = ctx->data[0] - 1;

    if (ctx->data[0] == 0)
    {
        return TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_WaitButton(ScriptContext *ctx) //0031
{
    SetupNativeScript(ctx, sub_0203A4E0);
    return TRUE;
}

static BOOL sub_0203A4E0(ScriptContext *ctx)
{
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B))
    {
        return TRUE;
    }
    else if (gSystem.newKeys & PAD_KEY_UP)
    {
        sub_02055304(ctx->fieldSystem->playerAvatar, 0);
    }
    else if (gSystem.newKeys & PAD_KEY_DOWN)
    {
        sub_02055304(ctx->fieldSystem->playerAvatar, 1);
    }
    else if (gSystem.newKeys & PAD_KEY_LEFT)
    {
        sub_02055304(ctx->fieldSystem->playerAvatar, 2);
    }
    else if (gSystem.newKeys & PAD_KEY_RIGHT)
    {
        sub_02055304(ctx->fieldSystem->playerAvatar, 3);
    }
    else if (gSystem.newKeys & PAD_BUTTON_X)
    {
        sub_02039460(ctx->fieldSystem);
    }
    else
    {
        return FALSE;
    }
    return TRUE;
}

BOOL ScrCmd_WaitButtonABPad(ScriptContext *ctx) //0032
{
    SetupNativeScript(ctx, sub_0203A570);
    return TRUE;
}

static BOOL sub_0203A570(ScriptContext *ctx)
{
#pragma unused(ctx)
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        return TRUE;
    }
    else if (gSystem.newKeys & (PAD_KEY_RIGHT | PAD_KEY_LEFT | PAD_KEY_UP | PAD_KEY_DOWN)) {
        return TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_Unk0033(ScriptContext *ctx) //0033 - todo: OpenMessageBox?
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *unk = (u8 *)FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_UNKNOWN_06);
    sub_020545B8(fieldSystem->bgConfig, (Window *)FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW), 3);
    sub_02054608((Window *)FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW), Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData));
    *unk = 1;
    return FALSE;
}

BOOL ScrCmd_CloseMessageBox(ScriptContext *ctx) //0034
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    Window *window = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW);
    u8 *unk2 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_UNKNOWN_06);
    ClearFrameAndWindow2(window, FALSE);
    RemoveWindow(window);
    *unk2 = 0;
    return FALSE;
}

BOOL ScrCmd_Unk0035(ScriptContext *ctx) //0035 - todo: FreezeMessageBox?
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    Window *window = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW);
    u8 *unk2 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_UNKNOWN_06);
    RemoveWindow(window);
    *unk2 = 0;
    return FALSE;
}

BOOL ScrCmd_ScrollBg(ScriptContext *ctx) //003C
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *xval = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8008);
    u16 *xcnt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8004);
    u16 *xdir = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8009);
    u16 *yval = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_800A);
    u16 *ycnt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8005);
    u16 *ydir = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_800B);

    *xval = ScriptReadByte(ctx);
    *xcnt = ScriptReadByte(ctx);
    *xdir = ScriptReadByte(ctx);
    *yval = ScriptReadByte(ctx);
    *ycnt = ScriptReadByte(ctx);
    *ydir = ScriptReadByte(ctx);

    SetupNativeScript(ctx, sub_0203A6C8);
    return TRUE;
}

static BOOL sub_0203A6C8(ScriptContext *ctx)
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *xval = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8008);
    u16 *xdir = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8009);
    u16 *yval = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_800A);
    u16 *ydir = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_800B);
    u16 *xcnt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8004);
    u16 *ycnt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8005);

    if (*xcnt == 0 && *ycnt == 0)
    {
        return TRUE;
    }

    if (*xval != 0)
    {
        if (*xdir == 0)
        {
            BgSetPosTextAndCommit(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_ADD_X, *xval);
        }
        else
        {
            BgSetPosTextAndCommit(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SUB_X, *xval);
        }
    }

    if (*yval != 0)
    {
        if (*ydir == 0)
        {
            BgSetPosTextAndCommit(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_ADD_Y, *yval);
        }
        else
        {
            BgSetPosTextAndCommit(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SUB_Y, *yval);
        }
    }

    if (*xcnt != 0)
    {
        *xcnt = (u16)(*xcnt - 1);
    }

    if (*ycnt != 0)
    {
        *ycnt = (u16)(*ycnt - 1);
    }

    return FALSE;
}

BOOL ScrCmd_CreateMessageBox(ScriptContext *ctx) //003C
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    String **stringBuffer1 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_1);
    String **stringBuffer0 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_0);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 typ, msg;
    u16 wk, map;

    msg = ScriptReadByte(ctx);
    typ = ScriptReadByte(ctx);
    map = ScriptReadHalfword(ctx);
    wk = ScriptReadHalfword(ctx);

    if (map == 0) {
        LocalMapObject **lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
        map = (u16)sub_02058510(*lastInteracted, 0);
    }

    ov05_021E8128(fieldSystem->unk60, typ, map);
    ov05_021E8130(fieldSystem->unk60, 1);
    ov05_021E8158(fieldSystem);
    ReadMsgDataIntoString(ctx->msgData, msg, *stringBuffer1);
    StringExpandPlaceholders(*messageFormat, *stringBuffer0, *stringBuffer1);
    AddTextPrinterParameterized(ov05_021E8140(fieldSystem->unk60), 1, *stringBuffer0, 0, 0, 0, NULL);

    return TRUE;
}

BOOL ScrCmd_Unk0037(ScriptContext *ctx) //0037 - todo: SetTextBoard? ColourMessageBox?
{
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 typ = ScriptReadByte(ctx);
    u16 map = ScriptReadHalfword(ctx);

    ov05_021E8128(fieldSystem->unk60, typ, map);
    ov05_021E8130(fieldSystem->unk60, 1);

    return TRUE;
}

BOOL ScrCmd_Unk0038(ScriptContext *ctx) { //0038 - todo: ShowMessageBox?
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 req = ScriptReadByte(ctx);
    ov05_021E8130(fieldSystem->unk60, req);
    return TRUE;
}

BOOL ScrCmd_Unk0039(ScriptContext *ctx) { //0039 - todo: MessageBoxWait? WaitMessageBox?
    if (ov05_021E8148(ctx->fieldSystem->unk60) == TRUE) {
        return FALSE;
    }

    SetupNativeScript(ctx, sub_0203A8A0);
    return TRUE;
}

static BOOL sub_0203A8A0(ScriptContext *ctx) {
    if (ov05_021E8148(ctx->fieldSystem->unk60) == TRUE) {
        return TRUE;
    }

    return FALSE;
}

BOOL ScrCmd_Unk003A(ScriptContext *ctx) { //003A - todo: CreateMessageBoxText?
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *printerNumber = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_TEXT_PRINTER_NUMBER);
    String **stringBuffer1 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_1);
    String **stringBuffer0 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_0);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);

    u8 msg = ScriptReadByte(ctx);
    u16 wk = ScriptReadHalfword(ctx);

    ReadMsgDataIntoString(ctx->msgData, msg, *stringBuffer1);
    StringExpandPlaceholders(*messageFormat, *stringBuffer0, *stringBuffer1);

    *printerNumber = (u8)sub_02054658(ov05_021E8140(fieldSystem->unk60), *stringBuffer0, Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData), 1);
    ctx->data[0] = wk;
    SetupNativeScript(ctx, sub_0203A94C);
    return TRUE;
}

static BOOL sub_0203A94C(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *printerNumber = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_TEXT_PRINTER_NUMBER);
    u16 *varPtr = GetVarPointer(fieldSystem, (u16)ctx->data[0]);
    ov05_021E8144(fieldSystem->unk60);

    u32 tmp = 0xFFFF;
    if (sub_020546C8(*printerNumber) == TRUE) {
        *varPtr = 2;
        return TRUE;
    }

    if (gSystem.newKeys & PAD_KEY_UP) {
        tmp = 0;
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        tmp = 1;
    } else if (gSystem.newKeys & PAD_KEY_LEFT) {
        tmp = 2;
    } else if (gSystem.newKeys & PAD_KEY_RIGHT) {
        tmp = 3;
    }

    if (tmp != 0xFFFF) {
        sub_0201BD7C(*printerNumber);
        sub_02055304(ctx->fieldSystem->playerAvatar, tmp);
        *varPtr = 0;
        return TRUE;
    } else {
        if (gSystem.newKeys & PAD_BUTTON_X) {
            sub_0201BD7C(*printerNumber);
            *varPtr = 1;
            return TRUE;
        }
        return FALSE;
    }
}

BOOL ScrCmd_Unk003B(ScriptContext *ctx) { //003B - todo: CloseMessageBox?
    ctx->data[0] = ScriptReadHalfword(ctx);

    SetupNativeScript(ctx, sub_0203AA0C);
    return TRUE;
}

static BOOL sub_0203AA0C(ScriptContext *ctx) {
    u16 *unk = GetVarPointer(ctx->fieldSystem, (u16)ctx->data[0]);

    u32 tmp = 0xFFFF;
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        *unk = 0;
        return TRUE;
    } else if (gSystem.newKeys & PAD_KEY_UP) {
        tmp = 0;
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        tmp = 1;
    } else if (gSystem.newKeys & PAD_KEY_LEFT) {
        tmp = 2;
    } else if (gSystem.newKeys & PAD_KEY_RIGHT) {
        tmp = 3;
    }

    if (tmp != 0xFFFF) {
        sub_02055304(ctx->fieldSystem->playerAvatar, tmp);
        *unk = 0;
        return TRUE;
    } else {
        if (gSystem.newKeys & PAD_BUTTON_X) {
            *unk = 1;
            return TRUE;
        } else {
            return FALSE;
        }
    }
}

BOOL ScrCmd_Menu(ScriptContext *ctx) { //003C
    sub_02039460(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_YesNoMenu(ScriptContext *ctx) { //003E
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 *unk = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LIST_MENU_2D);
    u16 wk = ScriptReadHalfword(ctx);
    LoadUserFrameGfx1(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 985, 11, 0, 4);
    *unk = Std_CreateYesNoMenu(fieldSystem->bgConfig, &UNK_020F34E0, 985, 11, 4);
    ctx->data[0] = wk;
    SetupNativeScript(ctx, sub_0203AB00);
    return TRUE;
}

static BOOL sub_0203AB00(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 *unk = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LIST_MENU_2D);
    u16 *ptr = GetVarPointer(fieldSystem, (u16)ctx->data[0]);
    u32 unk2 = sub_020021AC(*unk, 4);

    if (unk2 == -1) {
        return FALSE;
    }

    if (unk2 == 0) {
        *ptr = 0;
    } else {
        *ptr = 1;
    }
    return TRUE;
}

BOOL ScrCmd_ShowWaitingIcon(ScriptContext *ctx) { //018D
    Window *window = (Window *)FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WINDOW);
    WaitingIcon **waitingIcon = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WAITING_ICON);
    *waitingIcon = WaitingIcon_New(window, 994);
    return FALSE;
}

BOOL ScrCmd_HideWaitingIcon(ScriptContext *ctx) { //018E
    WaitingIcon **waitingIcon = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WAITING_ICON);
    sub_0200DBFC(*waitingIcon);
    return FALSE;
}

BOOL ScrCmd_Unk0040(ScriptContext *ctx) { //0040
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 *unk = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MENU_WINDOW);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 unk3 = ScriptReadByte(ctx);
    u8 unk4 = ScriptReadByte(ctx);
    u8 unk5 = ScriptReadByte(ctx);
    u8 unk6 = ScriptReadByte(ctx);
    u16 unk7 = ScriptReadHalfword(ctx);
    u16 *ptr = GetVarPointer(fieldSystem, unk7);
    Window *window = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WINDOW);
    *unk = ov05_021E1BF8(fieldSystem, unk3, unk4, unk5, unk6, ptr, *messageFormat, window, NULL);
    ctx->data[0] = unk7;
    return TRUE;
}

BOOL ScrCmd_Unk0041(ScriptContext *ctx) { //0041
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 *unk = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MENU_WINDOW);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 unk3 = ScriptReadByte(ctx);
    u8 unk4 = ScriptReadByte(ctx);
    u8 unk5 = ScriptReadByte(ctx);
    u8 unk6 = ScriptReadByte(ctx);
    u16 unk7 = ScriptReadHalfword(ctx);
    u16 *ptr = GetVarPointer(fieldSystem, unk7);
    Window *window = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WINDOW);
    *unk = ov05_021E1BF8(fieldSystem, unk3, unk4, unk5, unk6, ptr, *messageFormat, window, ctx->msgData);
    ctx->data[0] = unk7;
    return TRUE;
}

BOOL ScrCmd_Unk0042(ScriptContext *ctx) { //0042
    u32 *unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u8 unk2 = ScriptReadByte(ctx);
    u8 unk3 = ScriptReadByte(ctx);
    ov05_021E1C4C(*unk, unk2, unk3);
    return FALSE;
}

BOOL ScrCmd_Unk029D(ScriptContext *ctx) { //029D
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 *unk = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MENU_WINDOW);
    u16 unk2 = ScriptGetVar(ctx);
    u16 unk3 = ScriptGetVar(ctx);
    ov05_021E1C4C(*unk, unk2, unk3);
    return FALSE;
}

BOOL ScrCmd_Unk0043(ScriptContext *ctx) { //0043
    u32 *unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ov05_021E1C54(*unk);
    SetupNativeScript(ctx, sub_0203AD2C);
    return TRUE;
}

static BOOL sub_0203AD2C(ScriptContext *ctx) {
    u16 *varPtr = GetVarPointer(ctx->fieldSystem, (u16)ctx->data[0]);
    if (*varPtr == 0xEEEE) {
        return FALSE;
    } else {
        return TRUE;
    }
}

BOOL ScrCmd_Unk02B9(ScriptContext *ctx) { //02B9
    u32 *unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ov05_021E1C54(*unk);
    SetupNativeScript(ctx, sub_0203AD78);
    return TRUE;
}

static BOOL sub_0203AD78(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *varPtr = GetVarPointer(fieldSystem, (u16)ctx->data[0]);
    u32 *unk = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MENU_WINDOW);

    if (*varPtr == 0xEEEE) {
        if (sub_02052714(fieldSystem->unk78)) {
            *varPtr = 8;
            ov05_021E1ECC(*unk);
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        return TRUE;
    }
}

BOOL ScrCmd_Unk0044(ScriptContext *ctx) { //0044
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 *unk = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MENU_WINDOW);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 unk3 = ScriptReadByte(ctx);
    u8 unk4 = ScriptReadByte(ctx);
    u8 unk5 = ScriptReadByte(ctx);
    u8 unk6 = ScriptReadByte(ctx);

    u16 halfWord = ScriptReadHalfword(ctx);
    u16 *varPtr = GetVarPointer(fieldSystem, halfWord);
    Window *window = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WINDOW);
    *unk = ov05_021E1F34(fieldSystem, unk3, unk4, unk5, unk6, varPtr, *messageFormat, window, NULL);
    ctx->data[0] = halfWord;
    return TRUE;
}

BOOL ScrCmd_Unk0045(ScriptContext *ctx) { //0045
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 *unk = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MENU_WINDOW);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 unk3 = ScriptReadByte(ctx);
    u8 unk4 = ScriptReadByte(ctx);
    u8 unk5 = ScriptReadByte(ctx);
    u8 unk6 = ScriptReadByte(ctx);

    u16 halfWord = ScriptReadHalfword(ctx);
    u16 *varPtr = GetVarPointer(fieldSystem, halfWord);
    Window *window = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WINDOW);
    *unk = ov05_021E1F34(fieldSystem, unk3, unk4, unk5, unk6, varPtr, *messageFormat, window, ctx->msgData);
    ctx->data[0] = halfWord;
    return TRUE;
}

BOOL ScrCmd_Unk0046(ScriptContext *ctx) { //0046 - todo: AddListOption?
    u32 *unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u16 unk2 = ScriptGetVar(ctx);
    u16 unk3 = ScriptGetVar(ctx);
    u16 unk4 = ScriptGetVar(ctx);
    ov05_021E1F58(*unk, (u8)unk2, (u8)unk3, (u8)unk4);
    return FALSE;
}

BOOL ScrCmd_Unk0047(ScriptContext *ctx) { //0047 - todo: ShowList?
    u32 *unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ov05_021E1F60(*unk);
    SetupNativeScript(ctx, sub_0203AD2C);
    return TRUE;
}

BOOL ScrCmd_Unk0048(ScriptContext *ctx) { //0048
    u32 *unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ov05_021E26CC(*unk, ScriptReadByte(ctx));
    SetupNativeScript(ctx, sub_0203AD2C);
    return TRUE;
}

BOOL ScrCmd_Unk02CF(ScriptContext *ctx) { //02CF
    u32 *unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ov05_021E2B80(*unk, ScriptReadByte(ctx));
    return TRUE;
}

BOOL ScrCmd_Unk02D0(ScriptContext *ctx) { //02D0
    u32 *unk = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ov05_021E2B9C(*unk, ScriptReadByte(ctx));
    return TRUE;
}

BOOL ScrCmd_Unk005E(ScriptContext *ctx) { //005E - todo: ApplyMovement?
    u16 unk = ScriptGetVar(ctx);
    u32 unk2 = ScriptReadWord(ctx);

    LocalMapObject *event = sub_0203B120(ctx->fieldSystem, unk);
    GF_ASSERT(event);

    u32 unk4 = sub_0205AEA4(event, ctx->scriptPtr + unk2);
    u8 *movementCounter = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_ACTIVE_MOVEMENT_COUNTER);
    (*movementCounter)++;

    sub_0203B174(ctx->fieldSystem, unk4, NULL);
    return FALSE;
}

BOOL ScrCmd_Unk02A1(ScriptContext *ctx) { //02A1
    LocalMapObject *event; //has to be defined first to match
    u16 unk0 = ScriptGetVar(ctx);
    u16 unk1 = ScriptGetVar(ctx);
    u16 unk2 = ScriptGetVar(ctx);

    event = sub_0203B120(ctx->fieldSystem, unk0);

    GF_ASSERT(event);

    u16 *unk4 = AllocFromHeap(4, 0x100);
    u16 xVal = (u16)sub_02058B2C(event);
    u16 yVal = (u16)sub_02058B4C(event);

    u32 pos = 0;

    if (xVal < unk1) {
        unk4[0] = 15;
        pos++;
        unk4[1] = (u16)(unk1 - xVal);
    } else if (xVal > unk1) {
        unk4[0] = 14;
        pos++;
        unk4[1] = (u16)(xVal - unk1);
    }

    if (yVal < unk2) {
        unk4[pos * 2] = 12;
        unk4[pos * 2 + 1] = (u16)(unk2 - yVal);
        pos++;
    } else if (yVal > unk2) {
        unk4[pos * 2] = 13;
        unk4[pos * 2 + 1] = (u16)(yVal - unk2);
        pos++;
    }

    unk4[pos * 2] = 254;
    unk4[pos * 2 + 1] = 0;

    u32 unk7 = sub_0205AEA4(event, unk4);
    u8 *movementCounter = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_ACTIVE_MOVEMENT_COUNTER);

    (*movementCounter)++;

    sub_0203B174(ctx->fieldSystem, unk7, unk4);
    return FALSE;
}

static LocalMapObject *sub_0203B120(FieldSystem *fieldSystem, u16 eventId) {
    if (eventId == 242) {
        return sub_020580B4(fieldSystem->mapObjectManager, 48);
    } else if (eventId == 241) {
        LocalMapObject **cameraTarget = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_CAMERA_TARGET);
        return *cameraTarget;
    } else {
        return GetMapObjectByID(fieldSystem->mapObjectManager, eventId);
    }
}

BOOL ScrCmd_WaitForMovement(ScriptContext *ctx) { //005F
    SetupNativeScript(ctx, IsAllMovementFinished);
    return TRUE;
}

static BOOL IsAllMovementFinished(ScriptContext *ctx) {
    u8 *movCounter = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_ACTIVE_MOVEMENT_COUNTER);
    return *movCounter == 0;
}

static void sub_0203B174(FieldSystem *fieldSystem, u32 param1, void *param2) {
    UnkStruct_0203B174 *unkStruct = (UnkStruct_0203B174 *)AllocFromHeap(4, sizeof(UnkStruct_0203B174));
    if (unkStruct == NULL)
    {
        GF_AssertFail();
        return;
    }
    unkStruct->fieldSystem = fieldSystem;
    unkStruct->Unk04 = param1;
    unkStruct->Unk08 = param2;
    unkStruct->Unk00 = sub_0200CA44((void (*)(u32, void *))sub_0203B1A8, unkStruct, 0);
}

void sub_0203B1A8(u32 param0, UnkStruct_0203B174 *param1) {
    //is it tho?
#pragma unused(param0)
    u8 *movementCounter = (u8 *)FieldSysGetAttrAddr(param1->fieldSystem, SCRIPTENV_ACTIVE_MOVEMENT_COUNTER);

    if (sub_0205AEF0(param1->Unk04) != TRUE) {
        return;
    }

    sub_0205AEFC(param1->Unk04);
    sub_0200CAB4((s32)param1->Unk00);

    if (param1->Unk08 != NULL) {
        FreeToHeap(param1->Unk08);
    }

    FreeToHeap(param1);

    if (*movementCounter == 0) {
        GF_ASSERT(FALSE);
    } else {
        (*movementCounter)--;
    }
}

BOOL ScrCmd_LockAllEvents(ScriptContext *ctx) { //0060
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);

    if (*lastInteracted == NULL) {
        sub_02058780(fieldSystem->mapObjectManager);
    } else {
        ScrCmd_LockAllEvents2(ctx);
    }
    return TRUE;
}

static BOOL sub_0203B218(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    LocalMapObject *playerAvatar = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    if (UNK_021C5A0C[0] & 1) {
        if (sub_0205AE28(playerAvatar) == 1) {
            sub_02058908(playerAvatar);
            UNK_021C5A0C[0] &= 0xfe;
        }
    }
    if (UNK_021C5A0C[0] & 4) {
        if (sub_02058854(*lastInteracted) == 0) {
            sub_02058908(*lastInteracted);
            UNK_021C5A0C[0] &= 0xfb;
        }
    }
    if (UNK_021C5A0C[0] & 2) {
        LocalMapObject *unk1 = sub_020580B4(fieldSystem->mapObjectManager, 48);
        if (sub_02058854(unk1) == 0) {
            sub_02058908(unk1);
            UNK_021C5A0C[0] &= 0xfd;
        }
    }
    if (UNK_021C5A0C[0] & 8) {
        LocalMapObject *modifiedevent = sub_0205E7C4(*lastInteracted);
        if (sub_02058854(modifiedevent) == 0) {
            sub_02058908(modifiedevent);
            UNK_021C5A0C[0] &= 0xf7;
        }
    }
    if (UNK_021C5A0C[0] == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

BOOL ScrCmd_LockAllEvents2(ScriptContext *ctx) { //02B4
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    LocalMapObject *playerAvatar = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    LocalMapObject *unk1 = sub_020580B4(fieldSystem->mapObjectManager, 48);
    LocalMapObject *unk2 = sub_0205E7C4(*lastInteracted);
    MapObjectManager *mapObjectManager = fieldSystem->mapObjectManager;
    UNK_021C5A0C[0] = 0;

    sub_02058780(mapObjectManager);
    if (sub_0205AE28(playerAvatar) == 0) {
        UNK_021C5A0C[0] |= 1;
        sub_02058914(playerAvatar);
    }
    if (sub_02058854(*lastInteracted) != 0) {
        UNK_021C5A0C[0] |= 4;
        sub_02058914(*lastInteracted);
    }
    if (unk1 != NULL) {
        ScriptState *state = SaveArray_Flags_Get(fieldSystem->saveData);
        if (sub_0205ED3C(state) == TRUE) {
            if (sub_02058854(unk1) != 0) {
                UNK_021C5A0C[0] |= 2;
                sub_02058914(unk1);
            }
        }
    }
    if (unk2 != NULL) {
        if (sub_02058854(unk2) != 0) {
            UNK_021C5A0C[0] |= 8;
            sub_02058914(unk2);
        }
    }
    SetupNativeScript(ctx, sub_0203B218);
    return TRUE;
}

BOOL ScrCmd_ReleaseAllEvents(ScriptContext *ctx) { //0061
    sub_020587B0(ctx->fieldSystem->mapObjectManager);
    return TRUE;
}

BOOL ScrCmd_LockEvent(ScriptContext *ctx) { //0062
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 eventId = ScriptReadHalfword(ctx);
    sub_02058908(GetMapObjectByID(fieldSystem->mapObjectManager, eventId));
    return FALSE;
}

BOOL ScrCmd_ReleaseEvent(ScriptContext *ctx) { //0063
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 eventId = ScriptReadHalfword(ctx);
    sub_02058914(GetMapObjectByID(fieldSystem->mapObjectManager, eventId));
    return FALSE;
}

BOOL ScrCmd_AddEvent(ScriptContext *ctx) { //0064
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 eventId = ScriptGetVar(ctx);
    u32 unk0 = sub_02034B64(fieldSystem);
    u32 unk1 = sub_02034B6C(fieldSystem);
    u32 res = sub_020575D4(fieldSystem->mapObjectManager, eventId, unk0, fieldSystem->location->mapId, unk1);

    GF_ASSERT(res);
    return FALSE;
}

BOOL ScrCmd_RemoveEvent(ScriptContext *ctx) { //0065
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 eventId = ScriptGetVar(ctx);
    sub_02057688(GetMapObjectByID(fieldSystem->mapObjectManager, eventId));
    return FALSE;
}

BOOL ScrCmd_LockCamera(ScriptContext *ctx) { //0066
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    LocalMapObject **targetPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_CAMERA_TARGET);
    *targetPtr = sub_0205753C(ctx->fieldSystem->mapObjectManager, x, y, 0, 0x2000, 0, ctx->fieldSystem->location->mapId);
    sub_02059D1C(*targetPtr);
    sub_0205889C(*targetPtr, 1);
    sub_020588B8(*targetPtr, 0);
    VecFx32 *position = sub_02058B7C(*targetPtr);
    ov05_021EF5E0(position, ctx->fieldSystem->unk24);
    Camera_SetFixedTarget(position, ctx->fieldSystem->camera);
    return FALSE;
}

BOOL ScrCmd_ReleaseCamera(ScriptContext *ctx) { //0067
    LocalMapObject **targetPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_CAMERA_TARGET);
    sub_02057654(*targetPtr);
    VecFx32 *position = sub_02058B7C(GetMapObjectByID(ctx->fieldSystem->mapObjectManager, 0xff));
    ov05_021EF5E0(position, ctx->fieldSystem->unk24);
    Camera_SetFixedTarget(position, ctx->fieldSystem->camera);
    return FALSE;
}

BOOL ScrCmd_FacePlayer(ScriptContext *ctx) { //0068
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 unk0 = sub_02059E74(PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar));
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);

    if (*lastInteracted == NULL) {
        return FALSE;
    }

    ov05_021F1EC0(*lastInteracted, unk0);
    return FALSE;
}

BOOL ScrCmd_GetPlayerPosition(ScriptContext *ctx) { //0069
    FieldSystem *fieldSystem = ctx->fieldSystem;

    u16 *x = ScriptGetVarPointer(ctx);
    u16 *y = ScriptGetVarPointer(ctx);

    *x = GetPlayerXCoord(fieldSystem->playerAvatar);
    *y = GetPlayerYCoord(fieldSystem->playerAvatar);

    return FALSE;
}

BOOL ScrCmd_GetEventPosition(ScriptContext *ctx) { //006A
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 eventId = ScriptGetVar(ctx);
    LocalMapObject *event = GetMapObjectByID(fieldSystem->mapObjectManager, eventId);

    u16 *x = ScriptGetVarPointer(ctx);
    u16 *y = ScriptGetVarPointer(ctx);

    *x = (u16)sub_02058B2C(event);
    *y = (u16)sub_02058B4C(event);
    return FALSE;
}

BOOL ScrCmd_GetPlayerDirection(ScriptContext *ctx) { //01BD
    u16 *directionVar = ScriptGetVarPointer(ctx);

    *directionVar = (u16)PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    return FALSE;
}

BOOL ScrCmd_Unk006B(ScriptContext *ctx) { //006B - todo: CheckPersonPosition?
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    u16 z = ScriptGetVar(ctx);

    VecFx32 vector;
    vector.x = FX32_CONST(x);
    vector.y = FX32_CONST(y);
    vector.z = FX32_CONST(z);

    sub_02058BB4(PlayerAvatar_GetMapObject(ctx->fieldSystem->playerAvatar), &vector);
    Camera_OffsetLookAtPosAndTarget(&vector, ctx->fieldSystem->camera);
    return FALSE;
}

BOOL ScrCmd_KeepEvent(ScriptContext *ctx) { //006C
    u16 eventId = ScriptGetVar(ctx);
    LocalMapObject *event = GetMapObjectByID(ctx->fieldSystem->mapObjectManager, eventId);
    sub_02058994(event, ScriptReadByte(ctx));
    return FALSE;
}

BOOL ScrCmd_SetEventMovement(ScriptContext *ctx) { //006D
    u16 eventId = ScriptGetVar(ctx);
    LocalMapObject *event = GetMapObjectByID(ctx->fieldSystem->mapObjectManager, eventId);
    u16 movement = ScriptReadHalfword(ctx);
    sub_02058E90(event, movement);
    return FALSE;
}

BOOL ScrCmd_GetEventMovement(ScriptContext *ctx) { //02AD
    u16 *variable = ScriptGetVarPointer(ctx);
    *variable = 0;
    u16 eventId = ScriptGetVar(ctx);

    LocalMapObject *event = GetMapObjectByID(ctx->fieldSystem->mapObjectManager, eventId);
    if (event != NULL) {
        *variable = sub_02058480(event);
    }
    return FALSE;
}

BOOL ScrCmd_EventStopFollowing(ScriptContext *ctx) { //006E
    LocalMapObject *event = sub_020580B4(ctx->fieldSystem->mapObjectManager, 0x30);
    sub_02058EB0(event, 0xFE);
    return FALSE;
}

BOOL ScrCmd_Unk02AB(ScriptContext *ctx) { //02AB
    u16 *variable = ScriptGetVarPointer(ctx);
    SealCase *sealCase = Save_SealCase_Get(ctx->fieldSystem->saveData);
    *variable = sub_02029E0C(sealCase);
    return FALSE;
}

BOOL ScrCmd_GetSealCountFromId(ScriptContext *ctx) { //0093
    u16 sealId = ScriptGetVar(ctx);
    u16 *variable = ScriptGetVarPointer(ctx);
    SealCase *sealCase = Save_SealCase_Get(ctx->fieldSystem->saveData);
    *variable = SealCase_CountSealOccurrenceAnywhere(sealCase, sealId);
    return FALSE;
}

BOOL ScrCmd_GiveSeals(ScriptContext *ctx) { //0094
    u16 sealId = ScriptGetVar(ctx);
    u16 amount = ScriptGetVar(ctx);

    SealCase *sealCase = Save_SealCase_Get(ctx->fieldSystem->saveData);
    sub_02029D44(sealCase, sealId, (s16)amount);
    return FALSE;
}

BOOL ScrCmd_GetPokemonForme(ScriptContext *ctx) { //0095
    u16 partyPosition = ScriptGetVar(ctx);
    u16 *variable = ScriptGetVarPointer(ctx);

    PlayerParty *party = SaveArray_PlayerParty_Get(ctx->fieldSystem->saveData);
    *variable = GetMonUnownLetter(GetPartyMonByIndex(party, partyPosition));

    return FALSE;
}

BOOL ScrCmd_ChoosePokemonMenu(ScriptContext *ctx) { //0191
    PartyMenuAppData **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *partyMenu = sub_020379F8(0x20, ctx->fieldSystem);
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_OpenTradeScreen(ScriptContext *ctx) { //02A5
    PartyMenuAppData **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *partyMenu = sub_02037A1C(0x20, ctx->fieldSystem);
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_UnionChoosePokemonMenu(ScriptContext *ctx) { //0192
    PartyMenuAppData **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *partyMenu = sub_02037B44(ctx->fieldSystem->taskManager, 0x20);
    return TRUE;
}

BOOL ScrCmd_GetSelectedPartySlot(ScriptContext *ctx) { //0193
    u16 *variable = ScriptGetVarPointer(ctx);
    PartyMenuAppData **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);

    GF_ASSERT(*partyMenu);
    *variable = sub_02037A40(*partyMenu);

    if (*variable == 7) {
        *variable = 0xFF;
    }
    FreeToHeap(*partyMenu);
    *partyMenu = NULL;
    return FALSE;
}

BOOL ScrCmd_Unk0194(ScriptContext *ctx) { //0194
    void **runningAppData = (void **)FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 unk0 = ScriptGetVar(ctx);
    u16 unk1 = ScriptGetVar(ctx);
    u16 unk2 = ScriptGetVar(ctx);
    u16 unk3 = ScriptGetVar(ctx);

    *runningAppData = sub_02037BB0(0x20, ctx->fieldSystem, unk2, unk1, unk3, unk0);
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_Unk0195(ScriptContext *ctx) { //0195
    u16 *unk0 = ScriptGetVarPointer(ctx);
    u16 *unk1 = ScriptGetVarPointer(ctx);
    PartyMenuAppData **partyMenuData = (PartyMenuAppData **)FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    GF_ASSERT(*partyMenuData);

    *unk0 = sub_02037A40(*partyMenuData);

    if (*unk0 == 7) {
        *unk0 = 0xFF;
    }

    *unk1 = sub_02037A70(*partyMenuData);
    *unk1 = (*unk1 == 1);

    FreeToHeap(*partyMenuData);
    *partyMenuData = NULL;
    return FALSE;
}

BOOL ScrCmd_Unk0196(ScriptContext *ctx) { //0196
    void **runningAppData = (void **)FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 unk0 = ScriptGetVar(ctx);

    *runningAppData = sub_02037C00(0x20, ctx->fieldSystem, unk0);
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_Unk0197(ScriptContext *ctx) { //0197
    u16 *unk0 = ScriptGetVarPointer(ctx);
    void **runningAppData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);

    GF_ASSERT(*runningAppData);

    *unk0 = sub_02037A78(*runningAppData);
    FreeToHeap(*runningAppData);
    *runningAppData = NULL;

    return FALSE;
}

BOOL ScrCmd_Unk009B(ScriptContext *ctx) { //009B
    LocalMapObject **lastInteracted = (LocalMapObject **)FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u16 unk0 = ScriptGetVar(ctx);
    u16 *unk1 = ScriptGetVarPointer(ctx);

    *unk1 = ov05_021E1858(ctx->fieldSystem, *lastInteracted, unk0);
    return FALSE;
}

BOOL ScrCmd_DummySetWeather(ScriptContext *ctx) { //009C
#pragma unused(ctx)
    return FALSE;
}

BOOL ScrCmd_DummyInitWeather(ScriptContext *ctx) { //009D
#pragma unused(ctx)
    return FALSE;
}

BOOL ScrCmd_DummyUpdateWeather(ScriptContext *ctx) { //009E
#pragma unused(ctx)
    return TRUE;
}

BOOL ScrCmd_DummyGetMapPosition(ScriptContext *ctx) { //009F
#pragma unused(ctx)
    return FALSE;
}

/*static*/ BOOL sub_0203BB90(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    void **runningAppData = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_RUNNING_APP_DATA);

    if (sub_0204647C(fieldSystem)) {
        return FALSE;
    }
    FreeToHeap(*runningAppData);
    *runningAppData = NULL;
    return TRUE;
}

static BOOL sub_0203BBBC(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    PCBoxAppData **pcBoxDataPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    PCBoxAppData *pcBoxData = *pcBoxDataPtr;
    if (sub_0204647C(fieldSystem)) {
        return FALSE;
    }
    if (pcBoxData->unk08 == TRUE) {
        sub_02028AD4(fieldSystem->unk98, sub_02029048(11), 1);
    }
    FreeToHeap(*pcBoxDataPtr);
    *pcBoxDataPtr = NULL;
    return TRUE;
}

/*static*/ BOOL sub_0203BC04(ScriptContext *ctx) {
    return !sub_0204647C(ctx->fieldSystem);
}

BOOL ScrCmd_RestoreOverworld(ScriptContext *ctx) { //00A1
    sub_0204AF84(ctx->fieldSystem->taskManager);
    return TRUE;
}

BOOL ScrCmd_TerminateOverworldProcess(ScriptContext *ctx) { //01F8
    sub_0204AF3C(ctx->fieldSystem->taskManager);
    return TRUE;
}

static BOOL CheckPortraitSlotFullInternal(FieldSystem *fieldSystem, BOOL isContest, u32 portraitSlot) {
    SaveFashionData *fashionData = Save_FashionData_Get(fieldSystem->saveData);
    if (!isContest) {
        if (!CheckPortraitSlotFull(fashionData, portraitSlot)) {
            return FALSE;
        }
    } else {
        if (!CheckContestPortraitSlotFull(fashionData, portraitSlot)) {
            return FALSE;
        }
    }
    return TRUE;
}

static FashionAppData *sub_0203BC6C(u32 heapId, FieldSystem *fieldSystem, BOOL isContest, u32 portraitSlot) {
    SaveFashionData *fashionData = Save_FashionData_Get(fieldSystem->saveData);
    if (!CheckPortraitSlotFullInternal(fieldSystem, isContest, portraitSlot)) {
        return NULL;
    }
    FashionAppData *appData = AllocFromHeap(heapId, sizeof(FashionAppData));
    __builtin__clear(appData, sizeof(FashionAppData));
    appData->fashionData = fashionData;
    appData->isContest = isContest;
    appData->portraitSlot = portraitSlot;
    return appData;
}

BOOL ScrCmd_Unk00A2(ScriptContext *ctx) { //00A2
    ov05_021F02C4(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_Unk00A3(ScriptContext *ctx) { //00A3
    sub_0206F3B8(ctx->taskManager);
    return TRUE;
}

BOOL ScrCmd_GetDressupPortraitSlot(ScriptContext *ctx) { //00A4
    FashionAppData **runningAppData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 *portraitSlotPtr = ScriptGetVarPointer(ctx);
    *portraitSlotPtr = (*runningAppData)->portraitSlot;
    FreeToHeap(*runningAppData);
    return FALSE;
}

BOOL ScrCmd_Unk0207(ScriptContext *ctx) { //0207
    u16 *ptr = ScriptGetVarPointer(ctx);
    *ptr = sub_02031190();
    return TRUE;
}

BOOL ScrCmd_ShowPokemonPic(ScriptContext *ctx) { //0208
    PokepicManager **pokepicManager = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 species = ScriptGetVar(ctx);
    u16 gender = ScriptGetVar(ctx);
    LoadUserFrameGfx1(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 11, 0, 4);
    *pokepicManager = DrawPokemonPicFromSpecies(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 10, 5, 11, 0x3D9, species, gender, 4);
    Script_SetMonSeenFlagBySpecies(ctx->fieldSystem, species);
    return FALSE;
}

BOOL ScrCmd_ShowPartyPokemonPic(ScriptContext *ctx) { //028C
    PokepicManager **pokepicManager = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 partyId = ScriptGetVar(ctx);
    Pokemon *mon = GetPartyMonByIndex(SaveArray_PlayerParty_Get(ctx->fieldSystem->saveData), partyId);
    LoadUserFrameGfx1(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 11, 0, 4);
    *pokepicManager = DrawPokemonPicFromMon(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 10, 5, 11, 0x3D9, mon, 4);
    u32 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    Script_SetMonSeenFlagBySpecies(ctx->fieldSystem, (u16)species);
    return FALSE;
}

BOOL ScrCmd_Unk0209(ScriptContext *ctx) { //0209
    PokepicManager **pokepicManager = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    (*pokepicManager)->unk00 = 1;
    return TRUE;
}

BOOL ScrCmd_Unk028D(ScriptContext *ctx) { //028D
    PokepicManager **pokepicManager = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    (*pokepicManager)->unk00 = 2;
    return TRUE;
}

BOOL ScrCmd_Unk028E(ScriptContext *ctx) { //028E
    ctx->data[0] = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, sub_0203BE9C);
    return TRUE;
}

static BOOL sub_0203BE9C(ScriptContext *ctx) {
    PokepicManager **pokepicManager = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 *var = GetVarPointer(ctx->fieldSystem, ctx->data[0]); //unused
    return (*pokepicManager)->unk00 != 3;
}

BOOL ScrCmd_Unk020A(ScriptContext *ctx) { //020A
    u16 unk0 = ScriptReadHalfword(ctx);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u16 *ptr = GetVarPointer(ctx->fieldSystem, unk0);
    ov05_021E1374(ctx->taskManager, *messageFormat, ptr);
    return TRUE;
}

BOOL ScrCmd_Unk020B(ScriptContext *ctx) { //020B
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    if (*lastInteracted != NULL) {
        ov05_021E1994(ctx->fieldSystem, *lastInteracted);
    }
    return FALSE;
}

BOOL ScrCmd_Unk00A5(ScriptContext *ctx) { //00A5
    sub_0208A338(ctx->taskManager);
    return TRUE;
}

BOOL ScrCmd_DressupPokemon(ScriptContext *ctx) { //00A6
    u16 partyPos = ScriptGetVar(ctx);
    u16 *unk0 = ScriptGetVarPointer(ctx);
    u16 unk1 = ScriptGetVar(ctx);
    sub_020380CC(ctx->fieldSystem->taskManager, unk0, ctx->fieldSystem->saveData, partyPos, unk1);
    return TRUE;
}

BOOL ScrCmd_ShowDressedPokemon(ScriptContext *ctx) { //00A7
    FashionAppData **fashionAppData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 portraitSlot = ScriptReadHalfword(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    *fashionAppData = sub_0203BC6C(11, ctx->fieldSystem, FALSE, portraitSlot);
    if (*fashionAppData == NULL) {
        *var = 1;
        return TRUE;
    }
    *var = 0;
    sub_02038130(ctx->fieldSystem, *fashionAppData);
    SetupNativeScript(ctx, sub_0203BB90);
    return TRUE;
}

BOOL ScrCmd_ShowContestPokemon(ScriptContext *ctx) { //00A8
    FashionAppData **fashionAppData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 portraitSlot = ScriptReadHalfword(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    *fashionAppData = sub_0203BC6C(11, ctx->fieldSystem, TRUE, portraitSlot);
    if (*fashionAppData == NULL) {
        *var = 1;
        return TRUE;
    }
    *var = 0;
    sub_02038130(ctx->fieldSystem, *fashionAppData);
    SetupNativeScript(ctx, sub_0203BB90);
    return TRUE;
}

BOOL ScrCmd_CheckPortraitSlot(ScriptContext *ctx) { //012E
    u16 portraitSlot = ScriptReadHalfword(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    if (CheckPortraitSlotFullInternal(ctx->fieldSystem, FALSE, portraitSlot) == TRUE) {
        *var = TRUE;
        return TRUE;
    }
    *var = FALSE;
    return TRUE;
}

BOOL ScrCmd_CheckContestPortraitSlot(ScriptContext *ctx) { //012F
    u16 portraitSlot = ScriptReadHalfword(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    if (CheckPortraitSlotFullInternal(ctx->fieldSystem, TRUE, portraitSlot) == TRUE) {
        *var = TRUE;
        return TRUE;
    }
    *var = FALSE;
    return TRUE;
}

BOOL ScrCmd_Unk0130(ScriptContext *ctx) { //0130
    u16 unk0 = ScriptGetVar(ctx);
    SaveFashionData *fashionData = Save_FashionData_Get(ctx->fieldSystem->saveData);
    sub_02027478(sub_02027008(fashionData, 0), unk0);
    return TRUE;
}

BOOL ScrCmd_ShowGeonetScreen(ScriptContext *ctx) { //0205
    ShowGeonetScreen(ctx->fieldSystem);
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_ShowSealCapsuleEditor(ScriptContext *ctx) { //00A9
    ShowSealCapsuleEditor(ctx->taskManager, ctx->fieldSystem->saveData);
    return TRUE;
}

BOOL ScrCmd_ShowTownMapScreen(ScriptContext *ctx) { //00AA
    TownMapAppData **townMap = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *townMap = AllocFromHeap(11, sizeof(TownMapAppData));
    sub_0205F7A0(ctx->fieldSystem, *townMap, 2); //TownMap_Init?
    sub_02037E90(ctx->fieldSystem, *townMap); //ShowTownMap?
    SetupNativeScript(ctx, sub_0203BB90);
    return TRUE;
}

BOOL ScrCmd_Unk01D7(ScriptContext *ctx) { //01D7 - TODO: ShowPoffinCaseScreen?
    PoffinCaseAppData **poffinCaseAppData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u8 unk0 = ScriptReadHalfword(ctx);
    *poffinCaseAppData = sub_02088960(ctx->fieldSystem, unk0, 11);
    SetupNativeScript(ctx, sub_0203BB90);
    return TRUE;
}

BOOL ScrCmd_Unk01D8(ScriptContext *ctx) { //01D8
    u16 *unk0 = ScriptGetVarPointer(ctx);
    Bag *bag = Save_Bag_Get(ctx->fieldSystem->saveData);
    if (!Bag_PocketNotEmpty(bag, POCKET_BERRIES)) {
        *unk0 = 1;
        return FALSE;
    }
    else if (sub_020281B8(sub_02028048(ctx->fieldSystem->saveData)) >= 0x64) {
        *unk0 = 2;
        return FALSE;
    }
    *unk0 = 0;
    return FALSE;
}

BOOL ScrCmd_Unk01D9(ScriptContext *ctx) { //01D9
    u16 unk0 = ScriptGetVar(ctx);
    u16 unk1 = ScriptGetVar(ctx);
    ScrCmdUnkStruct01D9 **unkStructPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *unkStructPtr = AllocFromHeap(11, sizeof(ScrCmdUnkStruct01D9));
    ScrCmdUnkStruct01D9 *unkStruct = *unkStructPtr;
    MI_CpuFill8(unkStruct, 0, sizeof(ScrCmdUnkStruct01D9)); //consider inlining as is in heartgold
    unkStruct->unk04 = unk0;
    unkStruct->unk06 = unk1;
    unkStruct->save = ctx->fieldSystem->saveData;
    sub_02037FE4(ctx->fieldSystem, *unkStructPtr);
    SetupNativeScript(ctx, sub_0203BB90);
    return TRUE;
}

BOOL ScrCmd_ShowPCBoxScreen(ScriptContext *ctx) { //00AB
    PCBoxAppData **pcBoxAppDataPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    PCBoxAppData *pcBoxAppData = AllocFromHeap(11, sizeof(PCBoxAppData)); //also seems inlined
    pcBoxAppData->save = ctx->fieldSystem->saveData;
    pcBoxAppData->operation = (enum PCBoxOperation)ScriptReadByte(ctx);
    *pcBoxAppDataPtr = pcBoxAppData;
    LaunchStoragePCInterface(ctx->fieldSystem, *pcBoxAppDataPtr);
    SetupNativeScript(ctx, sub_0203BBBC);
    return TRUE;
}

BOOL ScrCmd_Unk00AC(ScriptContext *ctx) { //00AC
    sub_020383F8(ctx->fieldSystem);
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_Unk00AD(ScriptContext *ctx) { //00AD
    sub_02065344(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_Unk00AE(ScriptContext *ctx) { //00AE
    sub_020383D8(ctx->fieldSystem->taskManager);
    return TRUE;
}

BOOL ScrCmd_Unk00AF(ScriptContext *ctx) { //00AF
    void **appData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA); //todo: define an app type for this
    *appData = sub_0203842C(ctx->fieldSystem);
    SetupNativeScript(ctx, sub_0203BB90);
    return TRUE;
}

BOOL ScrCmd_ShowEndGameScreen(ScriptContext *ctx) { //00B0
    CallTask_GameClear(ctx->fieldSystem->taskManager);
    return TRUE;
}

BOOL ScrCmd_InitHallOfFame(ScriptContext *ctx) { //00B1
    HallOfFame **hallOfFameData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *hallOfFameData = sub_02038824(ctx->fieldSystem);
    SetupNativeScript(ctx, sub_0203BB90);
    return TRUE;
}

BOOL ScrCmd_Unk00B2(ScriptContext *ctx) { //00B2
    u16 unk0 = ScriptGetVar(ctx);
    u16 *unk1 = ScriptGetVarPointer(ctx);
    if (sub_0203384C(ctx->fieldSystem->saveData)) {
        *unk1 = 1;
        sub_020386E0(ctx->fieldSystem, unk0);
        SetupNativeScript(ctx, sub_0203BC04);
    } else {
        *unk1 = 0;
    }
    return TRUE;
}

BOOL ScrCmd_Unk00B3(ScriptContext *ctx) { //00B3
    u16 *var = ScriptGetVarPointer(ctx);
    sub_0206F3D8(ctx->taskManager, var);
    return TRUE;
}

BOOL ScrCmd_StarterSelectionScreen(ScriptContext *ctx) { //00B4
    StarterSelectionData **starterSelectionPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    *starterSelectionPtr = AllocFromHeap(11, sizeof(StarterSelectionData));
    StarterSelectionData *starterSelectionData = *starterSelectionPtr; //consider inlining
    starterSelectionData->options = Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData);
    sub_020386A4(ctx->fieldSystem, *starterSelectionPtr);
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_EndStarterSelectionScreen(ScriptContext *ctx) { //00B5
    StarterSelectionData **starterSelectionData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    ScriptState *flags = SaveArray_Flags_Get(ctx->fieldSystem->saveData);
    sub_0205F378(flags, (*starterSelectionData)->state);
    FreeToHeap(*starterSelectionData);
    return FALSE;
}

BOOL ScrCmd_ShowBagScreen(ScriptContext *ctx) { //0178
    BagScreenAppData **bagData; //required for matching
    u8 mode = ScriptReadByte(ctx) != 0 ? 1 : 0;
    bagData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);

    GF_ASSERT(*bagData == NULL);
    *bagData = sub_0203789C(ctx->fieldSystem, mode); //BagData_New?
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_GetBagScreenSelection(ScriptContext *ctx) { //0179
    u16 *var = ScriptGetVarPointer(ctx);
    BagScreenAppData **bagData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);

    GF_ASSERT(*bagData != NULL);
    *var = sub_020378FC(*bagData); //BagData_GetSelection?
    FreeToHeap(*bagData);
    *bagData = NULL;
    return FALSE;
}

BOOL ScrCmd_NamePlayerScreen(ScriptContext *ctx) { //00BA
    u16 *var = ScriptGetVarPointer(ctx);
    CreateNamingScreen(ctx->taskManager, NAMINGSCREEN_PLAYER, 0, PLAYER_NAME_LENGTH, 0, NULL, var);
    return TRUE;
}

BOOL ScrCmd_NamePokemonScreen(ScriptContext *ctx) { //00BB
    FieldSystem *fieldSystem = ctx->fieldSystem;

    u16 partyPos = ScriptGetVar(ctx);
    PlayerParty *party = SaveArray_PlayerParty_Get(fieldSystem->saveData);
    Pokemon *mon = GetPartyMonByIndex(party, partyPos);

    u16 monNick[20];
    GetMonData(mon, MON_DATA_NICKNAME, monNick);

    u16 *var = ScriptGetVarPointer(ctx);

    s32 species = GetMonData(mon, MON_DATA_SPECIES, NULL);

    CreateNamingScreen(ctx->taskManager, NAMINGSCREEN_POKEMON, species, POKEMON_NAME_LENGTH, partyPos, monNick, var);
    return TRUE;
}

BOOL ScrCmd_WriteWhiteRockInscription(ScriptContext *ctx) { //0271
    u16 *var = ScriptGetVarPointer(ctx);
    CreateNamingScreen(ctx->taskManager, NAMINGSCREEN_SHAYMIN_ROCK, 0, POKEMON_NAME_LENGTH, 0, NULL, var);
    return TRUE;
}

BOOL ScrCmd_Unk0243(ScriptContext *ctx) { //0243
    u16 unused = ScriptGetVar(ctx);
    u16 *unk1 = ScriptGetVarPointer(ctx);
    u16 *unk2 = ScriptGetVarPointer(ctx);
    *unk2 = 0xFFFF;
    sub_02037E18(ctx->fieldSystem->taskManager, unk1, unk2, NULL);
    return TRUE;
}

BOOL ScrCmd_Unk0244(ScriptContext *ctx) { //0244
    u16 unk0 = ScriptGetVar(ctx);
    u16 *unk1 = ScriptGetVarPointer(ctx);
    u16 *unk2 = ScriptGetVarPointer(ctx);
    u16 *unk3 = ScriptGetVarPointer(ctx);
    *unk2 = 0xFFFF;
    *unk3 = 0xFFFF;
    sub_02037E18(ctx->fieldSystem->taskManager, unk1, unk2, unk3);
    return TRUE;
}

BOOL ScrCmd_Unk0245(ScriptContext *ctx) { //0245
    MessageFormat **messageFormat = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u16 unk0 = ScriptGetVar(ctx);
    u16 unk1 = ScriptGetVar(ctx);
    BufferECWord(*messageFormat, unk0, unk1);
    return FALSE;
}

BOOL ScrCmd_FadeScreen(ScriptContext *ctx) { //00BC8
    u16 duration = ScriptReadHalfword(ctx);
    u16 speed = ScriptReadHalfword(ctx);
    u16 type = ScriptReadHalfword(ctx);
    u16 colour = ScriptReadHalfword(ctx);
    BeginNormalPaletteFade(0, type, type, colour, duration, speed, 4);
    sub_0200E388(0);
    sub_0200E388(1);
    return FALSE;
}

BOOL ScrCmd_WaitFadeScreen(ScriptContext *ctx) { //00BD
    SetupNativeScript(ctx, sub_0203C71C);
    return TRUE;
}

static BOOL sub_0203C71C(ScriptContext *ctx) {
    return IsPaletteFadeFinished() == TRUE;
}

BOOL ScrCmd_Warp(ScriptContext *ctx) { //00BE
    u16 mapId = ScriptReadHalfword(ctx);
    u16 door = ScriptReadHalfword(ctx); //unused?
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    u16 dir = ScriptReadHalfword(ctx);
    CallTask_ScriptWarp(ctx->taskManager, mapId, -1, x, y, dir);
    return TRUE;
}

BOOL ScrCmd_BattleRoomWarp(ScriptContext *ctx) { //0203
    u16 mapId = ScriptReadHalfword(ctx);
    u16 door = ScriptReadHalfword(ctx); //unused?
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    u16 dir = ScriptReadHalfword(ctx);
    sub_02049F98(ctx->fieldSystem->taskManager, mapId, -1, x, y, dir);
    return TRUE;
}

BOOL ScrCmd_ExitBattleRoom(ScriptContext *ctx) { //0204
    sub_02049FFC(ctx->fieldSystem->taskManager);
    return TRUE;
}

BOOL ScrCmd_GetPreviousMapID(ScriptContext *ctx) { //0200
    Location *location = sub_02034DC8(Save_LocalFieldData_Get(ctx->fieldSystem->saveData));
    u16 *var = ScriptGetVarPointer(ctx);
    *var = location->mapId;
    return FALSE;
}

BOOL ScrCmd_GetCurrentMapID(ScriptContext *ctx) { //0201
    u16 *var = ScriptGetVarPointer(ctx);
    *var = ctx->fieldSystem->location->mapId;
    return FALSE;
}

BOOL ScrCmd_RockClimb(ScriptContext *ctx) { //00BF
    u16 partyPosition = ScriptGetVar(ctx);
    u32 playerDirection = PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    CallFieldTask_RockClimb(ctx->taskManager, playerDirection, partyPosition);
    return TRUE;
}

BOOL ScrCmd_Surf(ScriptContext *ctx) { //00C0
    sub_0205DD40(ctx->fieldSystem->unk90);
    u16 partyPosition = ScriptGetVar(ctx);
    u32 playerDirection = PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    CallFieldTask_Surf(ctx->taskManager, playerDirection, partyPosition);
    return TRUE;
}

BOOL ScrCmd_Waterfall(ScriptContext *ctx) { //00C1
    u16 partyPosition = ScriptGetVar(ctx);
    u32 playerDirection = PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    CallFieldTask_Waterfall(ctx->taskManager, playerDirection, partyPosition);
    return TRUE;
}

BOOL ScrCmd_Fly(ScriptContext *ctx) { //00C2
    u16 mapId = ScriptReadHalfword(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    sub_02049274(ctx->fieldSystem, mapId, -1, x, y, DIR_SOUTH); //fly function
    return TRUE;
}

BOOL ScrCmd_Flash(ScriptContext *ctx) { //00C3
    LocalFieldData *localFieldData = Save_LocalFieldData_Get(ctx->fieldSystem->saveData);
    LocalFieldData_SetWeatherType(localFieldData, WEATHER_SUNNY); //clear weather
    ov05_021DC174(ctx->fieldSystem->unk04->unk0C, LocalFieldData_GetWeatherType(localFieldData)); //CallFieldTask_SetWeather? second param is get weather
    return TRUE;
}

BOOL ScrCmd_Defog(ScriptContext *ctx) { //00C4
    LocalFieldData *localFieldData = Save_LocalFieldData_Get(ctx->fieldSystem->saveData);
    LocalFieldData_SetWeatherType(localFieldData, WEATHER_SUNNY); //clear weather
    ov05_021DC174(ctx->fieldSystem->unk04->unk0C, LocalFieldData_GetWeatherType(localFieldData)); //CallFieldTask_SetWeather? second param is get weather
    return TRUE;
}

BOOL ScrCmd_Cut(ScriptContext *ctx) { //00C5
    void **miscData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR); //todo identify
    u16 partyPosition = ScriptGetVar(ctx);
    Pokemon *mon = GetPartyMonByIndex(SaveArray_PlayerParty_Get(ctx->fieldSystem->saveData), partyPosition);
    u32 gender = PlayerAvatar_GetGender(ctx->fieldSystem->playerAvatar);
    *miscData = ov06_0224666C(ctx->fieldSystem, 0, mon, gender);
    SetupNativeScript(ctx, sub_0203C9F8);
    return TRUE;
}

static BOOL sub_0203C9F8(ScriptContext *ctx) {
    void **miscData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR); //todo identify
    if (ov06_022466A0(*miscData) == TRUE) {
        ov06_022466AC(*miscData);
        return TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_ApplyContestDress(ScriptContext *ctx) { //00C6
    ov05_021E7030(ctx->taskManager);
    return TRUE;
}

BOOL ScrCmd_CheckBike(ScriptContext *ctx) { //00C7
    u16 *var = ScriptGetVarPointer(ctx);
    if (PlayerAvatar_GetState(ctx->fieldSystem->playerAvatar) == PLAYER_STATE_CYCLING) {
        *var = TRUE;
    } else {
        *var = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_RideBike(ScriptContext *ctx) { //00C8
    u8 action = ScriptReadByte(ctx);
    if (action == TRUE) {
        FieldSystem_SetSavedMusicId(ctx->fieldSystem, SEQ_BICYCLE);
        FieldSystem_PlayOrFadeToNewMusicId(ctx->fieldSystem, SEQ_BICYCLE, 1);
        Field_PlayerAvatar_OrrTransitionFlags(ctx->fieldSystem->playerAvatar, PLAYER_TRANSITION_CYCLING);
        Field_PlayerAvatar_ApplyTransitionFlags(ctx->fieldSystem->playerAvatar);
    } else {
        Field_PlayerAvatar_OrrTransitionFlags(ctx->fieldSystem->playerAvatar, PLAYER_TRANSITION_WALKING);
        Field_PlayerAvatar_ApplyTransitionFlags(ctx->fieldSystem->playerAvatar);
        FieldSystem_SetSavedMusicId(ctx->fieldSystem, 0);
        FieldSystem_PlayOrFadeToNewMusicId(ctx->fieldSystem, FieldSystem_GetOverriddenMusicId(ctx->fieldSystem, ctx->fieldSystem->location->mapId), 1);
    }
    return FALSE;
}

BOOL ScrCmd_DummyRideBike(ScriptContext *ctx) { //02BF
    Field_PlayerAvatar_OrrTransitionFlags(ctx->fieldSystem->playerAvatar, PLAYER_TRANSITION_CYCLING);
    FieldSystem_SetSavedMusicId(ctx->fieldSystem, SEQ_BICYCLE);
    return FALSE;
}

BOOL ScrCmd_CyclingRoad(ScriptContext *ctx) { //00C9
    u8 action = ScriptReadByte(ctx);
    sub_02055720(ctx->fieldSystem->playerAvatar, action);
    return FALSE;
}

BOOL ScrCmd_GetPlayerState(ScriptContext *ctx) { //00CA
    u16 *var = ScriptGetVarPointer(ctx);
    *var = PlayerAvatar_GetState(ctx->fieldSystem->playerAvatar);
    return FALSE;
}

BOOL ScrCmd_SetPlayerState(ScriptContext *ctx) { //00CB
    u16 state = ScriptReadHalfword(ctx);
    PlayerAvatar_OrrTransitionFlags(ctx->fieldSystem->playerAvatar, state);
    return TRUE;
}

BOOL ScrCmd_ApplyPlayerState(ScriptContext *ctx) { //00CC
    Field_PlayerAvatar_ApplyTransitionFlags(ctx->fieldSystem->playerAvatar);
    return FALSE;
}

BOOL ScrCmd_GetSwarmInfo(ScriptContext *ctx) { //00E3
    RoamerSaveData *roamerData = Save_Roamers_Get(ctx->fieldSystem->saveData);
    u16 *map = ScriptGetVarPointer(ctx);
    u16 *species = ScriptGetVarPointer(ctx);
    GetSwarmInfoFromRand(Roamers_GetRand(roamerData, 2), map, species);
    return FALSE;
}

BOOL ScrCmd_GetStarter(ScriptContext *ctx) { //00DE
    u16 *var = ScriptGetVarPointer(ctx);
    *var = ScriptState_GetStarter(SaveArray_Flags_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_TrainerMessage(ScriptContext *ctx) { //00E6
    FieldSystem *fieldSystem = ctx->fieldSystem;

    u16 *scriptNumber = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_ACTIVE_SCRIPT_NUMBER);
    String **string = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_0);
    void *unk06 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_UNKNOWN_06);
    u8 *printerNumber = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_TEXT_PRINTER_NUMBER);

    u16 trainerId = ScriptGetVar(ctx);
    u16 msgNo = ScriptGetVar(ctx);
    GetTrainerMessageByIdPair(trainerId, msgNo, *string, 11);
    FillWindowPixelBuffer(FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW), 15);
    *printerNumber = sub_02054658(FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW), *string, Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData), TRUE);
    SetupNativeScript(ctx, sub_0203A2F0);
    return TRUE;
}

BOOL ScrCmd_Unk00F2(ScriptContext *ctx) { //00F2
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 unk0 = ScriptGetVar(ctx);
    u16 unk1 = ScriptGetVar(ctx);
    u16 unk2 = ScriptGetVar(ctx);
    u16 unk3 = ScriptReadHalfword(ctx);
    ov06_02240790(fieldSystem, unk0, unk1, unk2);
    ctx->data[0] = unk3;
    SetupNativeScript(ctx, sub_0203CCF8);
    return TRUE;
}

static BOOL sub_0203CCF8(ScriptContext *ctx) {
    u16 *var = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    u32 result = ov06_022407DC();
    if (result == 0) {
        return FALSE;
    } else {
        *var = result;
        return TRUE;
    }
}

BOOL ScrCmd_Unk00F3(ScriptContext *ctx) { //00F3
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 unk0 = ScriptGetVar(ctx);
    u16 unk1 = ScriptGetVar(ctx);
    u16 unk2 = ScriptGetVar(ctx);
    u16 unk3 = ScriptReadHalfword(ctx);
    ov06_022407F8(fieldSystem, unk0, unk1, unk2);
    ctx->data[0] = unk3;
    SetupNativeScript(ctx, sub_0203CD90);
    return TRUE;
}

static BOOL sub_0203CD90(ScriptContext *ctx) {
    u16 *var = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    u32 result = ov06_02240844();
    if (result == 0) {
        return FALSE;
    } else {
        *var = result;
        return TRUE;
    }
}

BOOL ScrCmd_Unk00F4(ScriptContext *ctx) { //00F4
    u16 unused = ScriptReadHalfword(ctx);
    return TRUE;
}

BOOL ScrCmd_Unk00F5(ScriptContext *ctx) { //00F5
    u16 unused = ScriptReadHalfword(ctx);
    return TRUE;
}

BOOL ScrCmd_Unk00F6(ScriptContext *ctx) { //00F6
    ScrCmdUnkStruct00F4 **appDataPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    ScrCmdUnkStruct00F4 *appData = *appDataPtr;
    sub_02047174(ctx->fieldSystem->taskManager, &appData->unk2C, 5);
    FreeToHeap(appData);
    *appDataPtr = NULL;
    return TRUE;
}

BOOL ScrCmd_Unk00F7(ScriptContext *ctx) { //00F7
    sub_02080C38(ctx->taskManager);
    return TRUE;
}

BOOL ScrCmd_SetDynamicWarp(ScriptContext *ctx) { //011B
    Location warp;
    warp.mapId = ScriptGetVar(ctx);
    warp.warpId = ScriptGetVar(ctx);
    warp.x = ScriptGetVar(ctx);
    warp.y = ScriptGetVar(ctx);
    warp.direction = ScriptGetVar(ctx);
    LocalFieldData_SetDynamicWarp(Save_LocalFieldData_Get(ctx->fieldSystem->saveData), &warp);
    return FALSE;
}

BOOL ScrCmd_GetDynamicWarpFloorNumber(ScriptContext *ctx) { //011C
    u16 *var = ScriptGetVarPointer(ctx);
    Location *dynamicWarp = LocalFieldData_GetDynamicWarp(Save_LocalFieldData_Get(ctx->fieldSystem->saveData));
    *var = MapNumToFloorNo(dynamicWarp->mapId);
    return FALSE;
}

BOOL ScrCmd_ShowCurrentFloorNumber(ScriptContext *ctx) { //011D
    FieldSystem *fieldSystem = ctx->fieldSystem;
    MessageFormat **messageFormat = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    PrintCurrentFloorInNewWindow(fieldSystem, x, y, var, *messageFormat);
    return FALSE;
}

BOOL ScrCmd_CountSinnohDexSeen(ScriptContext *ctx) { //011E
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = Pokedex_CountSinnohDexSeen(pokedex);
    return FALSE;
}

BOOL ScrCmd_CountSinnohDexOwned(ScriptContext *ctx) { //011F
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = Pokedex_CountSinnohDexOwned(pokedex);
    return FALSE;
}

BOOL ScrCmd_CountNationalDexSeen(ScriptContext *ctx) { //0120
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = Pokedex_CountNationalDexSeen(pokedex);
    return FALSE;
}

BOOL ScrCmd_CountNationalDexOwned(ScriptContext *ctx) { //0121
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = Pokedex_CountNationalDexOwned(pokedex);
    return FALSE;
}

BOOL ScrCmd_DummyDexCheck(ScriptContext *ctx) { //0122
    return FALSE;
}

BOOL ScrCmd_GetDexEvaluationMessage(ScriptContext *ctx) { //0123
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    PlayerProfile *playerProfile = Save_PlayerData_GetProfileAddr(ctx->fieldSystem->saveData);
    u8 mode = ScriptReadByte(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    if (mode == 0) {
        *var = sub_02054CC8(Pokedex_CountSinnohDexSeen_OmitMythicals(pokedex), sub_0205F2E4(SaveArray_Flags_Get(ctx->fieldSystem->saveData), 2, 10));
    } else {
        *var = sub_02054D1C(Pokedex_CountNationalDexOwned_OmitMythicals(pokedex), PlayerProfile_GetTrainerGender(playerProfile));
    }
    return FALSE;
}

BOOL ScrCmd_WildBattle(ScriptContext *ctx) { //0124
    u32 *winFlag = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_BATTLE_WIN_FLAG);
    u16 species = ScriptGetVar(ctx);
    u16 level = ScriptGetVar(ctx);
    SetupAndStartWildBattle(ctx->taskManager, species, level, winFlag, FALSE);
    return TRUE;
}

BOOL ScrCmd_LegendaryBattle(ScriptContext *ctx) { //02BD
    u32 *winFlag = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_BATTLE_WIN_FLAG);
    u16 species = ScriptGetVar(ctx);
    u16 level = ScriptGetVar(ctx);
    SetupAndStartWildBattle(ctx->taskManager, species, level, winFlag, TRUE);
    return TRUE;
}

BOOL ScrCmd_FirstBattle(ScriptContext *ctx) { //0125
    u16 species = ScriptGetVar(ctx);
    u16 level = ScriptGetVar(ctx);
    SetupAndStartFirstBattle(ctx->taskManager, species, level);
    return TRUE;
}

BOOL ScrCmd_CatchTutorial(ScriptContext *ctx) { //0126
    SetupAndStartTutorialBattle(ctx->taskManager);
    return TRUE;
}

BOOL ScrCmd_UpdateHoneyTree(ScriptContext *ctx) { //0127
    UpdateHoneyTree(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_CheckHoneyTree(ScriptContext *ctx) { //0128
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *var = ScriptGetVarPointer(ctx);
    *var = CheckHoneyTree(fieldSystem);
    return FALSE;
}

BOOL ScrCmd_HoneyTreeBattle(ScriptContext *ctx) { //0129
    u32 *winFlag = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_BATTLE_WIN_FLAG);
    SetupAndStartHoneyTreeBattle(ctx->taskManager, winFlag);
    return TRUE;
}

BOOL ScrCmd_StopHoneyTreeAnimation(ScriptContext *ctx) { //012A
    ov05_021F4E7C(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_ShowSignatureScreen(ScriptContext *ctx) { //012B
    sub_020386B4(ctx->fieldSystem);
    SetupNativeScript(ctx, sub_0203BC04);
    return TRUE;
}

BOOL ScrCmd_CheckSaveStatus(ScriptContext *ctx) { //012C
    SaveData *saveData = ctx->fieldSystem->saveData;
    u16 *var = ScriptGetVarPointer(ctx);

    if (Save_FileDoesNotBelongToPlayer(saveData)) {
        *var = 0;
    } else if (!Save_FileExists(saveData)) {
        *var = 1;
    } else if (Save_GetDirtyBit(saveData)) {
        *var = 2;
    } else {
        *var = 3;
    }
    return FALSE;
}

BOOL ScrCmd_SaveGame(ScriptContext *ctx) { //012D
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *var = ScriptGetVarPointer(ctx);
    *var = Field_SaveGame(fieldSystem);
    return FALSE;
}

BOOL ScrCmd_GivePoketch(ScriptContext *ctx) { //0131
    Field_GivePoketch(ctx->taskManager);
    return TRUE;
}

BOOL ScrCmd_CheckPoketch(ScriptContext *ctx) { //0132
    Poketch *poketch = Save_Poketch_Get(ctx->fieldSystem->saveData);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = Save_Poketch_IsGiven(poketch);
    return FALSE;
}

BOOL ScrCmd_UnlockPoketchApp(ScriptContext *ctx) { //0133
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 appNumber = ScriptGetVar(ctx);
    Poketch *poketch = Save_Poketch_Get(fieldSystem->saveData);
    Save_Poketch_UnlockApp(poketch, (PoketchApp)appNumber);
    return FALSE;
}

BOOL ScrCmd_CheckPoketchApp(ScriptContext *ctx) { //0134
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 appNumber = ScriptGetVar(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    Poketch *poketch = Save_Poketch_Get(fieldSystem->saveData);
    *var = Save_Poketch_AppIsUnlocked(poketch, (PoketchApp)appNumber);
    return FALSE;
}

BOOL ScrCmd_Unk0135(ScriptContext *ctx) { //0135
    u16 unk0 = ScriptGetVar(ctx);
    ctx->data[0] = unk0;
    sub_02031588(unk0);
    SetupNativeScript(ctx, sub_0203D314);
    return TRUE;
}

static BOOL sub_0203D314(ScriptContext *ctx) {
    if (sub_02030F20() < 2) {
        return TRUE;
    }
    return sub_020315D8(ctx->data[0]);
}

BOOL ScrCmd_Unk0136(ScriptContext *ctx) { //0136
    sub_0203168C();
    return FALSE;
}

BOOL ScrCmd_Unk0137(ScriptContext *ctx) { //0137
    MessageFormat **messageFormat = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = sub_0205296C(*messageFormat);
    return FALSE;
}

BOOL ScrCmd_Unk0138(ScriptContext *ctx) { //0138
    u16 *var = ScriptGetVarPointer(ctx);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    *var = sub_02052C0C(ctx->fieldSystem->unk78, *messageFormat);
    return FALSE;
}

BOOL ScrCmd_Unk0139(ScriptContext *ctx) { //0139
    u16 unk0 = ScriptReadHalfword(ctx);

    if (unk0 == 5 || unk0 == 7 || unk0 == 9 || unk0 == 6) {
        sub_02031C54();
    } else if (unk0 == 11) {
        sub_02031C64();
    }
    if (sub_02031190() == 0) {
        sub_02052B74(unk0);
    }
    return FALSE;
}

BOOL ScrCmd_Unk013C(ScriptContext *ctx) { //013C
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u16 unk0 = ScriptReadHalfword(ctx);
    PlayerProfile *playerProfile = Save_PlayerData_GetProfileAddr(FieldSystem_GetSaveDataPtr(ctx->fieldSystem));
    SaveEasyChat *easyChat = Save_EasyChat_Get(FieldSystem_GetSaveDataPtr(ctx->fieldSystem));

    u16 objId;
    if (unk0 == 0) {
        objId = MapObject_GetID(*lastInteracted);
    } else {
        objId = 0;
    }
    sub_02052D08(*messageFormat, unk0, objId, playerProfile, easyChat);
    return FALSE;
}

BOOL ScrCmd_Unk013D(ScriptContext *ctx) { //013D
    sub_0208881C(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_Unk013E(ScriptContext *ctx) { //013E
    sub_02052F74(ctx->fieldSystem->unk7C);
    sub_02031B50();
    SetupNativeScript(ctx, sub_0203D47C);
    return TRUE;
}

static BOOL sub_0203D47C(ScriptContext *ctx) {
    return sub_02030F20() < 2;
}

BOOL ScrCmd_Unk013F(ScriptContext *ctx) { //013F
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u16 unk0 = ScriptReadHalfword(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    MessageFormat **messageFormat = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    *var = sub_02052A10(ctx->fieldSystem->unk78, MapObject_GetID(*lastInteracted), unk0, *messageFormat);
    return FALSE;
}

BOOL ScrCmd_Unk02BA(ScriptContext *ctx) { //02BA
    u16 *var = ScriptGetVarPointer(ctx);
    *var = sub_020527A8(ctx->fieldSystem->unk78);
    if (*var) {
        void **runningAppData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
        FreeToHeap(*runningAppData);
    }
    return FALSE;
}

BOOL ScrCmd_Unk0140(ScriptContext *ctx) { //0140
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = sub_020524CC(fieldSystem->unk78, MapObject_GetID(*lastInteracted));
    return FALSE;
}

BOOL ScrCmd_Unk0146(ScriptContext *ctx) { //0146
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u16 unk0 = ScriptGetVar(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = sub_02052544(fieldSystem->unk78, MapObject_GetID(*lastInteracted), unk0);
    return FALSE;
}

BOOL ScrCmd_Unk0141(ScriptContext *ctx) { //0141
    ctx->data[0] = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, sub_0203D5CC);
    return TRUE;
}

static BOOL sub_0203D5CC(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 unk0 = sub_02052604(fieldSystem->unk78);
    u16 *var = GetVarPointer(fieldSystem, ctx->data[0]);
    if (unk0 == 0) {
        return FALSE;
    } else {
        *var = unk0;
        return TRUE;
    }
}

BOOL ScrCmd_Unk0142(ScriptContext *ctx) { //0142
    sub_020534DC(ctx->fieldSystem->mapObjectManager, ctx->fieldSystem->unk7C);
    return FALSE;
}

BOOL ScrCmd_Unk013A(ScriptContext *ctx) { //013A
    sub_02052B74(4);
    sub_02031C2C();
    return FALSE;
}

BOOL ScrCmd_Unk013B(ScriptContext *ctx) { //013B
    sub_02031C64();
    sub_02031B50();
    sub_02052B74(0);
    return FALSE;
}

BOOL ScrCmd_Unk0143(ScriptContext *ctx) { //0143
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 unk0 = ScriptGetVar(ctx);
    u16 unk1 = ScriptGetVar(ctx);
    sub_0205265C(fieldSystem->unk78, unk0, unk1);
    return FALSE;
}

BOOL ScrCmd_Unk0144(ScriptContext *ctx) { //0144
    ctx->data[0] = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, sub_0203D688);
    return TRUE;
}

static BOOL sub_0203D688(ScriptContext *ctx) {
    u16 *var = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    u32 unk0 = sub_02052608(ctx->fieldSystem->unk78);
    if (unk0 >= 1) {
        *var = unk0;
        sub_02052E10(ctx->fieldSystem->unk78);
        return TRUE;
    }
    *var = 0;
    return FALSE;
}

BOOL ScrCmd_Unk0145(ScriptContext *ctx) { //0145
    ctx->data[0] = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, sub_0203D6E0);
    return TRUE;
}

static BOOL sub_0203D6E0(ScriptContext *ctx) {
    u16 *var = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    u32 unk0 = sub_02052648(ctx->fieldSystem->unk78);
    if (gSystem.newKeys & PAD_BUTTON_B) {
        unk0 = sub_02052718(ctx->fieldSystem->unk78, 8);
    }
    if (unk0 != 0) {
        *var = unk0;
        return TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_Unk0153(ScriptContext *ctx) { //0153
    sub_02049EA4(ctx->fieldSystem->taskManager);
    return TRUE;
}

BOOL ScrCmd_Unk0154(ScriptContext *ctx) { //0154
    PlayerProfile *playerProfile = Save_PlayerData_GetProfileAddr(FieldSystem_GetSaveDataPtr(ctx->fieldSystem));
    MessageFormat **messageFormat = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    sub_0205363C(PlayerProfile_GetTrainerID(playerProfile), PlayerProfile_GetTrainerGender(playerProfile), *messageFormat);
    return FALSE;
}

BOOL ScrCmd_Unk0155(ScriptContext *ctx) { //0155
    PlayerProfile *playerProfile = Save_PlayerData_GetProfileAddr(FieldSystem_GetSaveDataPtr(ctx->fieldSystem));
    u16 unk0 = ScriptGetVar(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = sub_02053678(PlayerProfile_GetTrainerID(playerProfile), PlayerProfile_GetTrainerGender(playerProfile), unk0);
    *var = sub_020536D0(PlayerProfile_GetTrainerGender(playerProfile), *var, 2);
    return FALSE;
}

BOOL ScrCmd_Unk029C(ScriptContext *ctx) { //029C
    PlayerProfile *playerProfile = Save_PlayerData_GetProfileAddr(FieldSystem_GetSaveDataPtr(ctx->fieldSystem));
    u16 unk0 = ScriptGetVar(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    *var = sub_02053678(PlayerProfile_GetTrainerID(playerProfile), PlayerProfile_GetTrainerGender(playerProfile), unk0);
    return FALSE;
}

BOOL ScrCmd_SetPlayerAvatar(ScriptContext *ctx) { //0156
    PlayerProfile *playerProfile = Save_PlayerData_GetProfileAddr(FieldSystem_GetSaveDataPtr(ctx->fieldSystem));
    u16 avatar = ScriptGetVar(ctx);
    PlayerProfile_SetAvatar(playerProfile, avatar);
    return FALSE;
}

BOOL ScrCmd_DummyBlackOut(ScriptContext *ctx) { //014B
    CallFieldTask_BlackOut(ctx->taskManager);
    return TRUE;
}

BOOL ScrCmd_SetSpawn(ScriptContext *ctx) { //014C
    u16 spawnPoint = ScriptGetVar(ctx);
    LocalFieldData *localFieldData = Save_LocalFieldData_Get(ctx->fieldSystem->saveData);
    LocalFieldData_SetBlackoutSpawn(localFieldData, spawnPoint);
    return FALSE;
}

BOOL ScrCmd_GetPlayerGender(ScriptContext *ctx) { //014D
    PlayerProfile *playerProfile = Save_PlayerData_GetProfileAddr(FieldSystem_GetSaveDataPtr(ctx->fieldSystem));
    u16 *var = ScriptGetVarPointer(ctx);
    *var = PlayerProfile_GetTrainerGender(playerProfile);
    return FALSE;
}

BOOL ScrCmd_HealParty(ScriptContext *ctx) { //014E
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(ctx->taskManager);
    HealParty(SaveArray_PlayerParty_Get(fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_Unk014F(ScriptContext *ctx) { //014F
    return FALSE;
}

BOOL ScrCmd_Unk0150(ScriptContext *ctx) { //0150
    sub_02050024();
    SetupNativeScript(ctx, sub_0203D904);
    return TRUE;
}

static BOOL sub_0203D904(ScriptContext *ctx) {
    if (sub_02031810() != 1 && sub_0202EDF8() != 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_Unk02BB(ScriptContext *ctx) { //02BB
    sub_02050048();
    SetupNativeScript(ctx, sub_0203D904);
    return TRUE;
}

BOOL ScrCmd_Unk0151(ScriptContext *ctx) { //0151
    sub_0204FF5C(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_Unk0152(ScriptContext *ctx) { //0152
    u16 unk0 = ScriptReadHalfword(ctx);
    sub_0204F6DC(unk0);
    return FALSE;
}

BOOL ScrCmd_CheckPocketNotEmpty(ScriptContext *ctx) { //017A
    u16 pocket = ScriptGetVar(ctx);
    u16 *var = ScriptGetVarPointer(ctx);
    Bag *bag = Save_Bag_Get(ctx->fieldSystem->saveData);
    *var = Bag_PocketNotEmpty(bag, pocket);
    return FALSE;
}

BOOL ScrCmd_SetEventDefaultPosition(ScriptContext *ctx) { //0186
    u16 eventId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    SetEventDefaultXYPos(ctx->fieldSystem, eventId, x, y);
    return FALSE;
}

BOOL ScrCmd_SetEventPosition(ScriptContext *ctx) { //0187
    u16 eventId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 z = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    u16 direction = ScriptGetVar(ctx);
    LocalMapObject *object = GetMapObjectByID(ctx->fieldSystem->mapObjectManager, eventId);
    sub_02058E28(object, x, z, y, direction);
    sub_02059D1C(object);
    return FALSE;
}

BOOL ScrCmd_SetEventDefaultMovement(ScriptContext *ctx) { //0188
    u16 eventId = ScriptGetVar(ctx);
    u16 movementId = ScriptGetVar(ctx);
    SetEventDefaultMovement(ctx->fieldSystem, eventId, movementId);
    return FALSE;
}

BOOL ScrCmd_SetEventDefaultDirection(ScriptContext *ctx) { //0189
    u16 eventId = ScriptGetVar(ctx);
    u16 direction = ScriptGetVar(ctx);
    SetEventDefaultDirection(ctx->fieldSystem, eventId, direction);
    return FALSE;
}

BOOL ScrCmd_SetWarpPosition(ScriptContext *ctx) { //018A
    u16 warpId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    SetWarpXYPos(ctx->fieldSystem, warpId, x, y);
    return FALSE;
}

BOOL ScrCmd_SetBgEventPosition(ScriptContext *ctx) { //018B
    u16 bgEventId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    SetBgEventXYPos(ctx->fieldSystem, bgEventId, x, y);
    return FALSE;
}
