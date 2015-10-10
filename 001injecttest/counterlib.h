#ifndef COUNTERLIB_H
#define COUNTERLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILDING_COUNTERLIB
#define COUNTERLIB __declspec(dllexport)
#else
#define COUNTERLIB __declspec(dllimport)
#endif

void __stdcall COUNTERLIB hello(const char *s);
int COUNTERLIB count(int p);

#ifdef __cplusplus
}
#endif

#endif // COUNTERLIB_H
