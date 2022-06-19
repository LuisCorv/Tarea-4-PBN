CC=g++
flags= -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

exe=prog
lib=libgrafo.dll

swig = C:\Users\fliac\Downloads\swig\swigwin-4.0.2\swig
ruta_python=C:\Users\fliac\anaconda3
python_version=python37

#Una vez que el codigo funcione en c++, eliminar esta parte del archivo main y hacer que corra sin el
$(exe): main.o $(lib)
	$(CC) $(flags) main.o -o $(exe) -L. -lgrafo -Wl,-rpath=.

grafo_wrap.cxx : grafo.i grafos.h
	$(swig) -python -c++ grafo.i

#Arreglar la parte del -shared, para que si logre realizarlo
_grafo.pyd:	grafo_wrap.cxx 	grafos.o
	$(CC) -fPIC -c grafo_wrap.cxx -o grafo_wrap.o -I $(ruta_python)/include
	-shared grafo_wrap.o grafos.o -o grafo.pyd -L$(ruta_python) 


$(lib): grafos.o 
	$(CC) $(flags) -shared grafos.o -o $(lib)

grafos.o: grafos.cpp grafos.h
	$(CC) $(flags) -fPIC -c grafos.cpp -o grafos.o

run_main: $(exe)
	.\$(exe)

run: _grafo.pyd

clean:
	del *.o $(exe).exe *.dll  grafo_wrap.cxx grafos_wrap.cxx grafo.py