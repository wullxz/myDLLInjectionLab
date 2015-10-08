ifeq ($(OS), Windows_NT)
	RM = del
	ENDING = .exe
else
	RM = rm
	ENDING = .bin
endif

all: counterlib.dll

counterlib.dll: counterlib.o
	gcc -shared -o counterlib.dll counterlib.o -Wl,--out-implib,libcounterlib.a

counterlib.o: counterlib.cpp
	gcc -c -DBUILDING_COUNTERLIB counterlib.cpp

clean:
	$(RM) *$(ENDING) *.o *.dll *.a
