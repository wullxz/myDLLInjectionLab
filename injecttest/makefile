ifeq ($(OS), Windows_NT)
	RM = del
	ENDING = .exe
else
	RM = rm
	ENDING = .bin
endif

all: counterlib.dll counter.exe

counter.exe: counter.c counterlib.dll
	gcc -c counter.c -m32
	gcc -o counter.exe counter.o -L. -lcounterlib -m32

counterlib.dll: counterlib.o
	gcc -shared -o counterlib.dll counterlib.o -Wl,--out-implib,libcounterlib.a -m32

counterlib.o: counterlib.cpp
	gcc -c -DBUILDING_COUNTERLIB counterlib.cpp -m32

clean:
	$(RM) *$(ENDING) *.o *.dll *.a
