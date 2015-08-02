#ifndef _BUILTINS_H
#define _BUILTINS_H

#include "tm.h"
#include "interp.h"
void      tmPrint(Object v);
void      tmPrintln(Object v);
Object    tmFormatVaList(char* fmt, va_list ap, int appendln);
Object    tmFormat(char*fmt, ...);
Object    tmType(Object o);
void      tmPrintf(char* fmt, ...);
/* avoid '\0' in char array, which will be regarded as end by c lang */
/* Chars     ObjectInfo(char*,Object,int); */
Object    tmLoad(char* fname);


Object    blt_Load();
Object    blt_Save();
Object    bfInt();
Object    bfFloat();
Object    bfSystem();
Object    blt_Print();
Object    blt_AddTypeMethod();
void      regBuiltinsFunc();
Object*   getBuiltin(char* key);
#endif
