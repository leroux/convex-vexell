char jhc_c_compile[] = "gcc build_haskell/rts/profile.c build_haskell/rts/rts_support.c build_haskell/rts/gc_none.c build_haskell/rts/jhc_rts.c build_haskell/lib/lib_cbits.c build_haskell/rts/gc_jgc.c build_haskell/rts/stableptr.c build_haskell/rts/conc.c -Ibuild_haskell/cbits -Ibuild_haskell build_haskell/hs_main.c -o build_haskell/hs_main.c '-std=gnu99' -D_GNU_SOURCE '-falign-functions=4' -ffast-math -Wextra -Wall -Wno-unused-parameter -fno-strict-aliasing -DNDEBUG -O3 '-D_JHC_GC=_JHC_GC_JGC' '-D_JHC_CONC=_JHC_CONC_NONE'";
char jhc_command[] = "ajhc -fffi --tdir=build_haskell -C --include=hs_src --include=../../vexell/src -o build_haskell/hs_main.c hs_src/Main.hs";
char jhc_version[] = "ajhc 0.8.0.10 (66a602abc10dec74e2c0bb9289819a015bf21e4f)";

#include "jhc_rts_header.h"
struct s_caches_pub {
    struct s_cache *cCJhc_Prim_Prim_$x3a;
    struct s_cache *cFR$__fJhc_Basics_$pp;
    struct s_cache *cCJhc_Type_Ptr_Ptr;
    struct s_cache *cCControl_Concurrent_ThreadId;
};
#include <rts/conc.h>
#include <rts/stableptr.h>
#include <stdio.h>
#include <stdlib.h>
#include <c_extern.h>

enum {
    CJhc_Prim_Prim_$BE = 1,
    CJhc_Prim_Prim_$LR = 0,
    CJhc_Prim_Prim_$x3a = 0,
    CJhc_Type_Basic_Char = 0,
    P1__Arm_armTask = 0,
    P1__Drive_driveTask = 1,
    P1__Intake_intakeTask = 2,
    P1__Pneumatics_pneumaticsTask = 3
};
struct sCControl_Concurrent_ThreadId A_ALIGNED;
struct sCJhc_Prim_Prim_$x3a A_ALIGNED;
struct sCJhc_Type_Ptr_Ptr A_ALIGNED;
struct sFR$__fJhc_Basics_$pp A_ALIGNED;

struct sCControl_Concurrent_ThreadId {
    sptr_t a1;
};

struct sCJhc_Prim_Prim_$x3a {
    sptr_t a1;
    sptr_t a2;
};

struct sCJhc_Type_Ptr_Ptr {
    uintptr_t a1;
};

struct sFR$__fJhc_Basics_$pp {
    fptr_t head;
    sptr_t a1;
    wptr_t a2;
};
void jhc_hs_init(gc_t gc,arena_t arena) ;
static wptr_t E__fR$__fJhc_Basics_$pp(gc_t gc,arena_t arena,struct sFR$__fJhc_Basics_$pp* arg) A_STD A_FALIGNED;
void _amain(void) ;
static void b__main(gc_t gc,arena_t arena) A_STD;
static sptr_t bapply__2079(gc_t gc,arena_t arena,wptr_t v1) A_STD A_MALLOC;
static sptr_t fArm_armTask(gc_t gc,arena_t arena) A_STD A_MALLOC;
static wptr_t fControl_Concurrent_forkOS(gc_t gc,arena_t arena,sptr_t v207355951) A_STD A_MALLOC;
static sptr_t fDrive_driveTask(gc_t gc,arena_t arena) A_STD A_MALLOC;
static uintptr_t fFE$__CCall_forkOScreateThreadWrapper(gc_t gc,arena_t arena,wptr_t v26) A_STD;
static void fFE$__CCall_hs__vexOperator(gc_t gc,arena_t arena) A_STD;
static void fFE$__CCall_hs__vexUserInit(gc_t gc,arena_t arena) A_STD;
static void fFE$__CCall_hs__vexUserSetup(gc_t gc,arena_t arena) A_STD;
static sptr_t fIntake_intakeTask(gc_t gc,arena_t arena) A_STD A_MALLOC;
static wptr_t fJhc_IO_putErrLn(gc_t gc,arena_t arena,wptr_t v76) A_STD A_MALLOC;
static sptr_t fPneumatics_pneumaticsTask(gc_t gc,arena_t arena) A_STD A_MALLOC;
static wptr_t fR$__fJhc_Basics_$pp(gc_t gc,arena_t arena,sptr_t v110947982,wptr_t v29534740) A_STD A_MALLOC;
HsPtr forkOScreateThreadWrapper(wptr_t x8) ;
static void ftheMain(gc_t gc,arena_t arena) A_STD;
void hs_vexOperator(void) ;
void hs_vexUserInit(void) ;
void hs_vexUserSetup(void) ;
/* CAFS */
/* (HcNode CJhc.Prim.Prim.: [Left &("P1_Pneumatics.pneumaticsTask"),Left &("CJhc.Prim.Prim.[]")],46) */
static const struct sCJhc_Prim_Prim_$x3a _c46 = {.a1 = (sptr_t)SET_RAW_TAG(P1__Pneumatics_pneumaticsTask), .a2 = (sptr_t)SET_RAW_TAG(CJhc_Prim_Prim_$BE)};
#define c46 (TO_SPTR_C(P_WHNF, (sptr_t)&_c46))
/* (HcNode CJhc.Prim.Prim.: [Left &("P1_Intake.intakeTask"),Right 46],47) */
static const struct sCJhc_Prim_Prim_$x3a _c47 = {.a1 = (sptr_t)SET_RAW_TAG(P1__Intake_intakeTask), .a2 = c46};
#define c47 (TO_SPTR_C(P_WHNF, (sptr_t)&_c47))
/* (HcNode CJhc.Prim.Prim.: [Left &("P1_Arm.armTask"),Right 47],48) */
static const struct sCJhc_Prim_Prim_$x3a _c48 = {.a1 = (sptr_t)SET_RAW_TAG(P1__Arm_armTask), .a2 = c47};
#define c48 (TO_SPTR_C(P_WHNF, (sptr_t)&_c48))
/* (HcNode CJhc.Prim.Prim.: [Left &("P1_Drive.driveTask"),Right 48],49) */
static const struct sCJhc_Prim_Prim_$x3a _c49 = {.a1 = (sptr_t)SET_RAW_TAG(P1__Drive_driveTask), .a2 = c48};
#define c49 (TO_SPTR_C(P_WHNF, (sptr_t)&_c49))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 121),Left &("CJhc.Prim.Prim.[]")],7) */
static const struct sCJhc_Prim_Prim_$x3a _c7 = {.a1 = (sptr_t)RAW_SET_UF('y'), .a2 = (sptr_t)SET_RAW_TAG(CJhc_Prim_Prim_$BE)};
#define c7 (TO_SPTR_C(P_WHNF, (sptr_t)&_c7))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 114),Right 7],8) */
static const struct sCJhc_Prim_Prim_$x3a _c8 = {.a1 = (sptr_t)RAW_SET_UF('r'), .a2 = c7};
#define c8 (TO_SPTR_C(P_WHNF, (sptr_t)&_c8))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 111),Right 8],9) */
static const struct sCJhc_Prim_Prim_$x3a _c9 = {.a1 = (sptr_t)RAW_SET_UF('o'), .a2 = c8};
#define c9 (TO_SPTR_C(P_WHNF, (sptr_t)&_c9))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 109),Right 9],10) */
static const struct sCJhc_Prim_Prim_$x3a _c10 = {.a1 = (sptr_t)RAW_SET_UF('m'), .a2 = c9};
#define c10 (TO_SPTR_C(P_WHNF, (sptr_t)&_c10))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 101),Right 10],11) */
static const struct sCJhc_Prim_Prim_$x3a _c11 = {.a1 = (sptr_t)RAW_SET_UF('e'), .a2 = c10};
#define c11 (TO_SPTR_C(P_WHNF, (sptr_t)&_c11))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 109),Right 11],12) */
static const struct sCJhc_Prim_Prim_$x3a _c12 = {.a1 = (sptr_t)RAW_SET_UF('m'), .a2 = c11};
#define c12 (TO_SPTR_C(P_WHNF, (sptr_t)&_c12))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 32),Right 12],13) */
static const struct sCJhc_Prim_Prim_$x3a _c13 = {.a1 = (sptr_t)RAW_SET_UF(' '), .a2 = c12};
#define c13 (TO_SPTR_C(P_WHNF, (sptr_t)&_c13))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 102),Right 13],14) */
static const struct sCJhc_Prim_Prim_$x3a _c14 = {.a1 = (sptr_t)RAW_SET_UF('f'), .a2 = c13};
#define c14 (TO_SPTR_C(P_WHNF, (sptr_t)&_c14))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 111),Right 14],15) */
static const struct sCJhc_Prim_Prim_$x3a _c15 = {.a1 = (sptr_t)RAW_SET_UF('o'), .a2 = c14};
#define c15 (TO_SPTR_C(P_WHNF, (sptr_t)&_c15))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 32),Right 15],16) */
static const struct sCJhc_Prim_Prim_$x3a _c16 = {.a1 = (sptr_t)RAW_SET_UF(' '), .a2 = c15};
#define c16 (TO_SPTR_C(P_WHNF, (sptr_t)&_c16))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 116),Right 16],17) */
static const struct sCJhc_Prim_Prim_$x3a _c17 = {.a1 = (sptr_t)RAW_SET_UF('t'), .a2 = c16};
#define c17 (TO_SPTR_C(P_WHNF, (sptr_t)&_c17))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 117),Right 17],18) */
static const struct sCJhc_Prim_Prim_$x3a _c18 = {.a1 = (sptr_t)RAW_SET_UF('u'), .a2 = c17};
#define c18 (TO_SPTR_C(P_WHNF, (sptr_t)&_c18))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 111),Right 18],19) */
static const struct sCJhc_Prim_Prim_$x3a _c19 = {.a1 = (sptr_t)RAW_SET_UF('o'), .a2 = c18};
#define c19 (TO_SPTR_C(P_WHNF, (sptr_t)&_c19))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 32),Right 19],20) */
static const struct sCJhc_Prim_Prim_$x3a _c20 = {.a1 = (sptr_t)RAW_SET_UF(' '), .a2 = c19};
#define c20 (TO_SPTR_C(P_WHNF, (sptr_t)&_c20))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 46),Left &("CJhc.Prim.Prim.[]")],22) */
static const struct sCJhc_Prim_Prim_$x3a _c22 = {.a1 = (sptr_t)RAW_SET_UF('.'), .a2 = (sptr_t)SET_RAW_TAG(CJhc_Prim_Prim_$BE)};
#define c22 (TO_SPTR_C(P_WHNF, (sptr_t)&_c22))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 100),Right 22],23) */
static const struct sCJhc_Prim_Prim_$x3a _c23 = {.a1 = (sptr_t)RAW_SET_UF('d'), .a2 = c22};
#define c23 (TO_SPTR_C(P_WHNF, (sptr_t)&_c23))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 97),Right 23],24) */
static const struct sCJhc_Prim_Prim_$x3a _c24 = {.a1 = (sptr_t)RAW_SET_UF('a'), .a2 = c23};
#define c24 (TO_SPTR_C(P_WHNF, (sptr_t)&_c24))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 101),Right 24],25) */
static const struct sCJhc_Prim_Prim_$x3a _c25 = {.a1 = (sptr_t)RAW_SET_UF('e'), .a2 = c24};
#define c25 (TO_SPTR_C(P_WHNF, (sptr_t)&_c25))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 114),Right 25],26) */
static const struct sCJhc_Prim_Prim_$x3a _c26 = {.a1 = (sptr_t)RAW_SET_UF('r'), .a2 = c25};
#define c26 (TO_SPTR_C(P_WHNF, (sptr_t)&_c26))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 104),Right 26],27) */
static const struct sCJhc_Prim_Prim_$x3a _c27 = {.a1 = (sptr_t)RAW_SET_UF('h'), .a2 = c26};
#define c27 (TO_SPTR_C(P_WHNF, (sptr_t)&_c27))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 116),Right 27],28) */
static const struct sCJhc_Prim_Prim_$x3a _c28 = {.a1 = (sptr_t)RAW_SET_UF('t'), .a2 = c27};
#define c28 (TO_SPTR_C(P_WHNF, (sptr_t)&_c28))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 32),Right 28],29) */
static const struct sCJhc_Prim_Prim_$x3a _c29 = {.a1 = (sptr_t)RAW_SET_UF(' '), .a2 = c28};
#define c29 (TO_SPTR_C(P_WHNF, (sptr_t)&_c29))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 83),Right 29],30) */
static const struct sCJhc_Prim_Prim_$x3a _c30 = {.a1 = (sptr_t)RAW_SET_UF('S'), .a2 = c29};
#define c30 (TO_SPTR_C(P_WHNF, (sptr_t)&_c30))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 79),Right 30],31) */
static const struct sCJhc_Prim_Prim_$x3a _c31 = {.a1 = (sptr_t)RAW_SET_UF('O'), .a2 = c30};
#define c31 (TO_SPTR_C(P_WHNF, (sptr_t)&_c31))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 32),Right 31],32) */
static const struct sCJhc_Prim_Prim_$x3a _c32 = {.a1 = (sptr_t)RAW_SET_UF(' '), .a2 = c31};
#define c32 (TO_SPTR_C(P_WHNF, (sptr_t)&_c32))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 101),Right 32],33) */
static const struct sCJhc_Prim_Prim_$x3a _c33 = {.a1 = (sptr_t)RAW_SET_UF('e'), .a2 = c32};
#define c33 (TO_SPTR_C(P_WHNF, (sptr_t)&_c33))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 116),Right 33],34) */
static const struct sCJhc_Prim_Prim_$x3a _c34 = {.a1 = (sptr_t)RAW_SET_UF('t'), .a2 = c33};
#define c34 (TO_SPTR_C(P_WHNF, (sptr_t)&_c34))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 97),Right 34],35) */
static const struct sCJhc_Prim_Prim_$x3a _c35 = {.a1 = (sptr_t)RAW_SET_UF('a'), .a2 = c34};
#define c35 (TO_SPTR_C(P_WHNF, (sptr_t)&_c35))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 101),Right 35],36) */
static const struct sCJhc_Prim_Prim_$x3a _c36 = {.a1 = (sptr_t)RAW_SET_UF('e'), .a2 = c35};
#define c36 (TO_SPTR_C(P_WHNF, (sptr_t)&_c36))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 114),Right 36],37) */
static const struct sCJhc_Prim_Prim_$x3a _c37 = {.a1 = (sptr_t)RAW_SET_UF('r'), .a2 = c36};
#define c37 (TO_SPTR_C(P_WHNF, (sptr_t)&_c37))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 99),Right 37],38) */
static const struct sCJhc_Prim_Prim_$x3a _c38 = {.a1 = (sptr_t)RAW_SET_UF('c'), .a2 = c37};
#define c38 (TO_SPTR_C(P_WHNF, (sptr_t)&_c38))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 32),Right 38],39) */
static const struct sCJhc_Prim_Prim_$x3a _c39 = {.a1 = (sptr_t)RAW_SET_UF(' '), .a2 = c38};
#define c39 (TO_SPTR_C(P_WHNF, (sptr_t)&_c39))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 58),Right 20],21) */
static const struct sCJhc_Prim_Prim_$x3a _c21 = {.a1 = (sptr_t)RAW_SET_UF(':'), .a2 = c20};
#define c21 (TO_SPTR_C(P_WHNF, (sptr_t)&_c21))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 116),Right 39],40) */
static const struct sCJhc_Prim_Prim_$x3a _c40 = {.a1 = (sptr_t)RAW_SET_UF('t'), .a2 = c39};
#define c40 (TO_SPTR_C(P_WHNF, (sptr_t)&_c40))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 111),Right 40],41) */
static const struct sCJhc_Prim_Prim_$x3a _c41 = {.a1 = (sptr_t)RAW_SET_UF('o'), .a2 = c40};
#define c41 (TO_SPTR_C(P_WHNF, (sptr_t)&_c41))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 110),Right 41],42) */
static const struct sCJhc_Prim_Prim_$x3a _c42 = {.a1 = (sptr_t)RAW_SET_UF('n'), .a2 = c41};
#define c42 (TO_SPTR_C(P_WHNF, (sptr_t)&_c42))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 110),Right 42],43) */
static const struct sCJhc_Prim_Prim_$x3a _c43 = {.a1 = (sptr_t)RAW_SET_UF('n'), .a2 = c42};
#define c43 (TO_SPTR_C(P_WHNF, (sptr_t)&_c43))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 97),Right 43],44) */
static const struct sCJhc_Prim_Prim_$x3a _c44 = {.a1 = (sptr_t)RAW_SET_UF('a'), .a2 = c43};
#define c44 (TO_SPTR_C(P_WHNF, (sptr_t)&_c44))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 67),Right 44],45) */
static const struct sCJhc_Prim_Prim_$x3a _c45 = {.a1 = (sptr_t)RAW_SET_UF('C'), .a2 = c44};
#define c45 (TO_SPTR_C(P_WHNF, (sptr_t)&_c45))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 99),Left &("CJhc.Prim.Prim.[]")],1) */
static const struct sCJhc_Prim_Prim_$x3a _c1 = {.a1 = (sptr_t)RAW_SET_UF('c'), .a2 = (sptr_t)SET_RAW_TAG(CJhc_Prim_Prim_$BE)};
#define c1 (TO_SPTR_C(P_WHNF, (sptr_t)&_c1))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 111),Right 1],2) */
static const struct sCJhc_Prim_Prim_$x3a _c2 = {.a1 = (sptr_t)RAW_SET_UF('o'), .a2 = c1};
#define c2 (TO_SPTR_C(P_WHNF, (sptr_t)&_c2))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 108),Right 2],3) */
static const struct sCJhc_Prim_Prim_$x3a _c3 = {.a1 = (sptr_t)RAW_SET_UF('l'), .a2 = c2};
#define c3 (TO_SPTR_C(P_WHNF, (sptr_t)&_c3))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 108),Right 3],4) */
static const struct sCJhc_Prim_Prim_$x3a _c4 = {.a1 = (sptr_t)RAW_SET_UF('l'), .a2 = c3};
#define c4 (TO_SPTR_C(P_WHNF, (sptr_t)&_c4))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 97),Right 4],5) */
static const struct sCJhc_Prim_Prim_$x3a _c5 = {.a1 = (sptr_t)RAW_SET_UF('a'), .a2 = c4};
#define c5 (TO_SPTR_C(P_WHNF, (sptr_t)&_c5))
/* (HcNode CJhc.Prim.Prim.: [Left &("CJhc.Type.Basic.Char" 109),Right 5],6) */
static const struct sCJhc_Prim_Prim_$x3a _c6 = {.a1 = (sptr_t)RAW_SET_UF('m'), .a2 = c5};
#define c6 (TO_SPTR_C(P_WHNF, (sptr_t)&_c6))

const void * const nh_stuff[] = {
&_c1, &_c2, &_c3, &_c4, &_c5, &_c6, &_c7, &_c8, &_c9, &_c10, &_c11,
&_c12, &_c13, &_c14, &_c15, &_c16, &_c17, &_c18, &_c19, &_c20,
&_c21, &_c22, &_c23, &_c24, &_c25, &_c26, &_c27, &_c28, &_c29,
&_c30, &_c31, &_c32, &_c33, &_c34, &_c35, &_c36, &_c37, &_c38,
&_c39, &_c40, &_c41, &_c42, &_c43, &_c44, &_c45, &_c46, &_c47,
&_c48, &_c49, NULL
};


void 
jhc_hs_init(gc_t gc,arena_t arena)
{
        alloc_public_caches(arena,sizeof(struct s_caches_pub));
        find_cache(&public_caches(arena)->cCJhc_Prim_Prim_$x3a,arena,TO_BLOCKS(sizeof(struct sCJhc_Prim_Prim_$x3a)),2);
        find_cache(&public_caches(arena)->cFR$__fJhc_Basics_$pp,arena,TO_BLOCKS(sizeof(struct sFR$__fJhc_Basics_$pp)),3);
        find_cache(&public_caches(arena)->cCJhc_Type_Ptr_Ptr,arena,TO_BLOCKS(sizeof(struct sCJhc_Type_Ptr_Ptr)),0);
        find_cache(&public_caches(arena)->cCControl_Concurrent_ThreadId,arena,TO_BLOCKS(sizeof(struct sCControl_Concurrent_ThreadId)),1);
}

static wptr_t A_STD A_FALIGNED
E__fR$__fJhc_Basics_$pp(gc_t gc,arena_t arena,struct sFR$__fJhc_Basics_$pp* arg)
{
        {   wptr_t r;
            gc_frame0(gc,1,MKLAZY(arg));
            r = fR$__fJhc_Basics_$pp(gc,arena,arg->a1,arg->a2);
            update(arg,r);
            return r;
        }
}

void 
_amain(void)
{
        arena_t arena;
        gc_t gc;
        gc = NULL;
        arena = NULL;
        jhc_alloc_init(&gc,&arena);
        jhc_hs_init(gc,arena);
        b__main(gc,arena);
        jhc_alloc_fini(gc,arena);
}

static void A_STD
b__main(gc_t gc,arena_t arena)
{
        ftheMain(gc,arena);
        return;
}

static sptr_t A_STD A_MALLOC
bapply__2079(gc_t gc,arena_t arena,wptr_t v1)
{
        switch (FETCH_TAG(v1)) {
        case P1__Pneumatics_pneumaticsTask:
            {   return fPneumatics_pneumaticsTask(gc,arena);
            }
            break;
        case P1__Intake_intakeTask:
            {   return fIntake_intakeTask(gc,arena);
            }
            break;
        case P1__Arm_armTask:
            {   return fArm_armTask(gc,arena);
            }
            break;
        case P1__Drive_driveTask:
            {   return fDrive_driveTask(gc,arena);
            }
            break;
        default: jhc_case_fell_off(__LINE__);
        }
}

static sptr_t A_STD A_MALLOC
fArm_armTask(gc_t gc,arena_t arena)
{
        armTask();
        return (sptr_t)SET_RAW_TAG(CJhc_Prim_Prim_$LR);
}

static wptr_t A_STD A_MALLOC
fControl_Concurrent_forkOS(gc_t gc,arena_t arena,sptr_t v207355951)
{
        uintptr_t v3070 = ((uintptr_t)malloc((size_t)((intptr_t)((int32_t)sizeof(uint32_t)))));
        {   sptr_t v170458234;
            gc_frame0(gc,1,v207355951);
            wptr_t x6 = s_alloc(gc,arena,public_caches(arena)->cCJhc_Type_Ptr_Ptr);
            ((struct sCJhc_Type_Ptr_Ptr*)x6)->a1 = v3070;
            wptr_t v17 = x6;
            sptr_t v1859784253 = demote(v17);
            if (0 == v3070) {
                wptr_t v100014;
                v100014 = fR$__fJhc_Basics_$pp(gc,arena,c6,PROMOTE(c21));
                {   gc_frame0(gc,1,v100014);
                    fJhc_IO_putErrLn(gc,arena,v100014);
                }
                jhc_exit(255);
            } else {
                v170458234 = v1859784253;
            }
            wptr_t v100018 = promote(v170458234);
            {   sptr_t v31;
                uintptr_t v154420598;
                gc_frame0(gc,1,v100018);
                wptr_t v93301078 = eval(gc,arena,v207355951);
                wptr_t v264254028 = ((wptr_t)c_newStablePtr((wptr_t)v93301078));
                v154420598 = ((struct sCJhc_Type_Ptr_Ptr*)v100018)->a1;
                sptr_t v105553374 = ((sptr_t)forkOS_createThread((HsFunPtr)((uintptr_t)&forkOScreateThreadWrapper),(wptr_t)v264254028,(int*)v154420598));
                uint32_t v186466152 = *((uint32_t *)(v154420598));
                if (0 == v186466152) {
                    v31 = v105553374;
                } else {
                    fJhc_IO_putErrLn(gc,arena,PROMOTE(c45));
                    jhc_exit(255);
                }
                free((HsPtr)v154420598);
                {   gc_frame0(gc,1,v31);
                    wptr_t x7 = s_alloc(gc,arena,public_caches(arena)->cCControl_Concurrent_ThreadId);
                    ((struct sCControl_Concurrent_ThreadId*)x7)->a1 = v31;
                    return x7;
                }
            }
        }
}

static sptr_t A_STD A_MALLOC
fDrive_driveTask(gc_t gc,arena_t arena)
{
        driveTask();
        return (sptr_t)SET_RAW_TAG(CJhc_Prim_Prim_$LR);
}

static uintptr_t A_STD
fFE$__CCall_forkOScreateThreadWrapper(gc_t gc,arena_t arena,wptr_t v26)
{
        wptr_t v216085086 = ((wptr_t)c_derefStablePtr((wptr_t)v26));
        {   gc_frame0(gc,1,v26);
            {   gc_frame0(gc,1,v216085086);
                bapply__2079(gc,arena,v216085086);
            }
            c_freeStablePtr((wptr_t)v26);
            return 0;
        }
}

static void A_STD
fFE$__CCall_hs__vexOperator(gc_t gc,arena_t arena)
{
        sptr_t v10;
        v10 = c49;
        fJhc_Monad_72__go__12:;
        {   wptr_t v100000 = eval(gc,arena,v10);
            if (SET_RAW_TAG(CJhc_Prim_Prim_$BE) == v100000) {
                SET_RAW_TAG(CJhc_Prim_Prim_$LR);
            } else {
                sptr_t v10527816;
                sptr_t v12;
                /* ("CJhc.Prim.Prim.:" ni12 ni10527816) */
                v12 = ((struct sCJhc_Prim_Prim_$x3a*)v100000)->a1;
                v10527816 = ((struct sCJhc_Prim_Prim_$x3a*)v100000)->a2;
                {   gc_frame0(gc,1,v10527816);
                    {   gc_frame0(gc,1,v12);
                        fControl_Concurrent_forkOS(gc,arena,v12);
                    }
                    v10 = v10527816;
                    goto fJhc_Monad_72__go__12;
                }
            }
        }
        return;
}

static void A_STD
fFE$__CCall_hs__vexUserInit(gc_t gc,arena_t arena)
{
        return;
}

static void A_STD
fFE$__CCall_hs__vexUserSetup(gc_t gc,arena_t arena)
{
        vexUserSetup();
        return;
}

static sptr_t A_STD A_MALLOC
fIntake_intakeTask(gc_t gc,arena_t arena)
{
        intakeTask();
        return (sptr_t)SET_RAW_TAG(CJhc_Prim_Prim_$LR);
}

static wptr_t A_STD A_MALLOC
fJhc_IO_putErrLn(gc_t gc,arena_t arena,wptr_t v76)
{
        sptr_t v127 = demote(v76);
        {   sptr_t v40405742;
            gc_frame0(gc,1,v127);
            {   gc_frame0(gc,1,v127);
                v40405742 = v127;
                goto fR$__fJhc_IO_putErrLn__3;
            }
            /* [ni40405742] */
            fR$__fJhc_IO_putErrLn__3:;
            {   wptr_t v100028 = eval(gc,arena,v40405742);
                if (SET_RAW_TAG(CJhc_Prim_Prim_$BE) == v100028) {
                    jhc_utf8_putchar((int)10);
                    return SET_RAW_TAG(CJhc_Prim_Prim_$LR);
                } else {
                    sptr_t v78;
                    sptr_t v80;
                    /* ("CJhc.Prim.Prim.:" ni78 ni80) */
                    v78 = ((struct sCJhc_Prim_Prim_$x3a*)v100028)->a1;
                    v80 = ((struct sCJhc_Prim_Prim_$x3a*)v100028)->a2;
                    {   uint32_t v227981060;
                        gc_frame0(gc,1,v80);
                        wptr_t v100030 = eval(gc,arena,v78);
                        v227981060 = ((uint32_t)RAW_GET_UF(v100030));
                        uint32_t v105553376 = v227981060;
                        jhc_utf8_putchar((int)v105553376);
                        v40405742 = v80;
                        goto fR$__fJhc_IO_putErrLn__3;
                    }
                }
            }
        }
}

static sptr_t A_STD A_MALLOC
fPneumatics_pneumaticsTask(gc_t gc,arena_t arena)
{
        pneumaticsTask();
        return (sptr_t)SET_RAW_TAG(CJhc_Prim_Prim_$LR);
}

static wptr_t A_STD A_MALLOC
fR$__fJhc_Basics_$pp(gc_t gc,arena_t arena,sptr_t v110947982,wptr_t v29534740)
{
        {   gc_frame0(gc,1,v29534740);
            wptr_t v100012 = eval(gc,arena,v110947982);
            if (SET_RAW_TAG(CJhc_Prim_Prim_$BE) == v100012) {
                return v29534740;
            } else {
                sptr_t v136;
                sptr_t v138;
                /* ("CJhc.Prim.Prim.:" ni136 ni138) */
                v136 = ((struct sCJhc_Prim_Prim_$x3a*)v100012)->a1;
                v138 = ((struct sCJhc_Prim_Prim_$x3a*)v100012)->a2;
                {   gc_frame0(gc,2,v136,v138);
                    sptr_t x4 = s_alloc(gc,arena,public_caches(arena)->cFR$__fJhc_Basics_$pp);
                    ((struct sFR$__fJhc_Basics_$pp*)x4)->head = TO_FPTR(&E__fR$__fJhc_Basics_$pp);
                    ((struct sFR$__fJhc_Basics_$pp*)x4)->a1 = v138;
                    ((struct sFR$__fJhc_Basics_$pp*)x4)->a2 = v29534740;
                    sptr_t v36878618 = MKLAZY(x4);
                    {   gc_frame0(gc,1,v36878618);
                        wptr_t x5 = s_alloc(gc,arena,public_caches(arena)->cCJhc_Prim_Prim_$x3a);
                        ((struct sCJhc_Prim_Prim_$x3a*)x5)->a1 = v136;
                        ((struct sCJhc_Prim_Prim_$x3a*)x5)->a2 = v36878618;
                        return x5;
                    }
                }
            }
        }
}

HsPtr 
forkOScreateThreadWrapper(wptr_t x8)
{
        arena_t arena;
        gc_t gc;
        gc = NULL;
        arena = NULL;
        jhc_alloc_init(&gc,&arena);
        jhc_hs_init(gc,arena);
        HsPtr x9 = ((HsPtr)fFE$__CCall_forkOScreateThreadWrapper(gc,arena,(wptr_t)x8));
        jhc_alloc_fini(gc,arena);
        return x9;
}

static void A_STD
ftheMain(gc_t gc,arena_t arena)
{
        return;
}

void 
hs_vexOperator(void)
{
        arena_t arena;
        gc_t gc;
        gc = NULL;
        arena = NULL;
        jhc_alloc_init(&gc,&arena);
        jhc_hs_init(gc,arena);
        fFE$__CCall_hs__vexOperator(gc,arena);
        jhc_alloc_fini(gc,arena);
}

void 
hs_vexUserInit(void)
{
        arena_t arena;
        gc_t gc;
        gc = NULL;
        arena = NULL;
        jhc_alloc_init(&gc,&arena);
        jhc_hs_init(gc,arena);
        fFE$__CCall_hs__vexUserInit(gc,arena);
        jhc_alloc_fini(gc,arena);
}

void 
hs_vexUserSetup(void)
{
        arena_t arena;
        gc_t gc;
        gc = NULL;
        arena = NULL;
        jhc_alloc_init(&gc,&arena);
        jhc_hs_init(gc,arena);
        fFE$__CCall_hs__vexUserSetup(gc,arena);
        jhc_alloc_fini(gc,arena);
}
