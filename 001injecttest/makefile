ifeq ($(OS), Windows_NT)
	RM = del
	ENDING = .exe
else
	RM = rm
	ENDING = .bin
endif

all: clean counter.exe injector.exe mod.dll

# 
# counter.exe build config:

counter.exe: counter.c counterlib.dll
	gcc -c counter.c -m32
	gcc -o counter.exe counter.o -L. -lcounterlib -m32

counterlib.dll: counterlib.cpp
	gcc -c -DBUILDING_COUNTERLIB counterlib.cpp -m32
	gcc -shared -o counterlib.dll counterlib.o -Wl,--out-implib,libcounterlib.a -m32

#
# injector build config:

injector.exe: injector.cpp
	gcc injector.cpp -m32 -o injector.exe

mod.dll: mod.cpp mod.h
	gcc -c -DBUILDING_MODLIB mod.cpp -m32
	gcc -shared -o mod.dll mod.o -Wl,--out-implib,libmod.a -m32

clean:
	$(RM) *$(ENDING) *.o *.dll *.a
