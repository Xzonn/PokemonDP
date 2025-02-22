#include "global.h"
#include "party.h"
#include "heap.h"

void SaveArray_Party_Init(struct PlayerParty * party);
void InitPartyWithMaxSize(struct PlayerParty * party, int count);

u32 SaveArray_Party_sizeof(void)
{
    return sizeof(struct PlayerParty);
}

struct PlayerParty * SaveArray_Party_Alloc(HeapID heapId)
{
    struct PlayerParty * ret = (struct PlayerParty *)AllocFromHeap(heapId, sizeof(struct PlayerParty));
    SaveArray_Party_Init(ret);
    return ret;
}

void SaveArray_Party_Init(struct PlayerParty * party)
{
    InitPartyWithMaxSize(party, PARTY_SIZE);
}

void InitPartyWithMaxSize(struct PlayerParty * party, int count)
{
    int i;
    GF_ASSERT(count <= PARTY_SIZE);
    memset(party, 0, sizeof(struct PlayerParty));
    party->curCount = 0;
    party->maxCount = count;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&party->mons[i]);
}

BOOL AddMonToParty(struct PlayerParty * party, struct Pokemon * pokemon)
{
    if (party->curCount >= party->maxCount)
        return FALSE;
    party->mons[party->curCount] = *pokemon;
    party->curCount++;
    return TRUE;
}

BOOL RemoveMonFromParty(struct PlayerParty * party, int pos)
{
    int i;

    GF_ASSERT(pos >= 0);
    GF_ASSERT(pos < party->curCount);
    GF_ASSERT(pos < party->maxCount);
    GF_ASSERT(party->curCount > 0);

    for (i = pos; i < party->curCount - 1; i++)
    {
        party->mons[i] = party->mons[i + 1];
    }

    ZeroMonData(&party->mons[i]);
    party->curCount--;
    return TRUE;
}

int GetPartyCount(struct PlayerParty * party)
{
    return party->curCount;
}

struct Pokemon * GetPartyMonByIndex(struct PlayerParty * party, int pos)
{
    GF_ASSERT(pos >= 0);
    GF_ASSERT(pos < party->curCount);
    GF_ASSERT(pos < party->maxCount);
    return &party->mons[pos];
}

void ReplacePartySlotWithMon(struct PlayerParty * party, int pos, struct Pokemon * pokemon)
{
    int r2;
    GF_ASSERT(pos >= 0);
    GF_ASSERT(pos < party->curCount);
    GF_ASSERT(pos < party->maxCount);
    r2 = (int)(GetMonData(&party->mons[pos], MON_DATA_SPECIES_EXISTS, NULL) - GetMonData(pokemon, MON_DATA_SPECIES_EXISTS, NULL));
    party->mons[pos] = *pokemon;
    party->curCount += r2;
}

BOOL SwapSlotsInParty(struct PlayerParty * party, int pos1, int pos2)
{
    struct Pokemon * buffer;
    GF_ASSERT(pos1 >= 0);
    GF_ASSERT(pos1 < party->curCount);
    GF_ASSERT(pos1 < party->maxCount);
    GF_ASSERT(pos2 >= 0);
    GF_ASSERT(pos2 < party->curCount);
    GF_ASSERT(pos2 < party->maxCount);
    buffer = AllocFromHeap(HEAP_ID_DEFAULT, sizeof(struct Pokemon));
    *buffer = party->mons[pos1];
    party->mons[pos1] = party->mons[pos2];
    party->mons[pos2] = *buffer;
    FreeToHeap(buffer);
    return FALSE;
}

void CopyPlayerParty(struct PlayerParty * src, struct PlayerParty * dest)
{
    *dest = *src;
}

BOOL PartyHasMon(struct PlayerParty * party, u16 species)
{
    int i;
    for (i = 0; i < party->curCount; i++)
    {
        if (species == GetMonData(&party->mons[i], MON_DATA_SPECIES, NULL))
            break;
    }
    return i != party->curCount;
}

struct PlayerParty * SaveArray_PlayerParty_Get(struct SaveData * ptr)
{
    return (struct PlayerParty *)SaveArray_Get(ptr, 2);
}
