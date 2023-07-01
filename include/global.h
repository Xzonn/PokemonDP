#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "config.h"

#include "NNS_G3D_res_struct.h" //todo: add to nnsys.h

#include <string.h>
#include "function_target.h"
#include "nitro/types.h"
#include "constants/global.h"
#include "error_handling.h"

#define NELEMS(a) (sizeof(a) / sizeof(*(a)))

#define GF_ASSERT(expr) do {if (!(expr)) GF_AssertFail();} while (0)

#ifndef IN_MAIN_C
extern const u8 gGameLanguage;
extern const u8 gGameVersion;
#endif //IN_MAIN_C

#include "code16.h"

#endif //GUARD_GLOBAL_H
