#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "tm.h"
#define GET_FUNCTION(obj) (obj.value.func)
#define IS_FUNCTION(o) TM_TYPE(o)==TYPE_FUNCTION
#define GET_FUNCTIONTION_MODULE_PTR(fnc) GET_MODULE(GET_FUNCTION(fnc)->mod)
#define GET_FUNC_CONSTANTS(fnc) GET_FUNCTIONTION_MODULE_PTR(fnc)->constants
#define GET_FUNC_MOD_NAME(fnc) GET_FUNCTIONTION_MODULE_PTR(fnc)->file
#define GET_FUNC_CONSTANTS_NODES(fnc) LIST_NODES(GET_FUNC_CONSTANTS(fnc))
#define GET_FUNCTION_NAME(fnc) GET_FUNCTION(fnc)->name

#define DB_FUNC 1

Object           newFunction(Object mod,Object self,Object (*native_func)());
Object           getFuncAttr(TmFunction* fnc, Object key);
void             functionFree(TmFunction*);
Object           methodNew(Object _fnc, Object self);
Object           moduleNew(Object file, Object name, Object code);
void             moduleFree(TmModule*);
CodeCheckResult  resolveCode(TmModule *mod,  unsigned char*s , int isFuncDef);
unsigned char*   getFunctionCode(TmFunction*);
unsigned char**  getFunctionTags(TmFunction*);
Object           getModuleCreateIfNotExist(char* modName);
void             _functionFormat(char* des, TmFunction* func);
#define          functionFormat(des, func) _functionFormat(des, GET_FUNCTION(func))
TmModule*        getFuncMod(TmFunction* func);
#if DB_FUNC
char* getFuncNameSz(Object func);
char* getFuncFileSz(Object func);
#endif
Object           classNew(Object dict);
Object           getFunctionGlobals(TmFunction*);
#define getGlobals(func) getFunctionGlobals(GET_FUNCTION(func))
#endif
