#ifndef MODLIB_H
#define MODLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILDING_MODLIB
#define MODLIB __declspec(dllexport)
#else
#define MODLIB __declspec(dllimport)
#endif

void __stdcall MODLIB hello(const char * s);
void MODLIB makeSub();
void MODLIB makeAdd();

#ifdef __cplusplus
}
#endif

#endif // MODLIB_H
