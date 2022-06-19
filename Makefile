CC=g++
flags= -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe=prog
lib=libgrafo.dll

#Una vez que el codigo funcione en c++, eliminar esta parte del archivo main y hacer que corra sin el
$(exe): main.o $(lib)
	$(CC) $(flags) main.o -o $(exe) -L. -lgrafo -Wl,-rpath=.

$(lib): grafos.o 
	$(CC) $(flags) -shared grafos.o -o $(lib)

 grafos.o: grafos.cpp grafos.h
	$(CC) $(flags) -fPIC -c grafos.cpp -o grafos.o

run: $(exe)
	.\$(exe)

clean:
	del *.o $(exe).exe *.dll