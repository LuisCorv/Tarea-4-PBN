CC=g++
flags= 

exe=prog
lib=libgrafo.dll

swig = C:\Users\fliac\Downloads\swig\swigwin-4.0.2
ruta_python=C:\Users\fliac\anaconda3\pkgs\python-3.7.6-h60c2a47_2


#Arreglar la parte del -shared, para que si logre realizarlo
_grafo.pyd:	grafo_wrap.cxx 	grafos.o
	$(CC) -fPIC -c grafo_wrap.cxx -o grafo_wrap.o -I$(ruta_python)/include
	$(CC) -shared grafo_wrap.o grafos.o -o _grafo.pyd -L$(ruta_python) -lpython37

grafo_wrap.cxx : grafo.i grafos.h
	$(swig)/swig -python -c++ grafo.i

#Una vez que el codigo funcione en c++, eliminar esta parte del archivo main y hacer que corra sin el
$(exe): main.o $(lib)
	$(CC) $(flags) main.o -o $(exe) -L. -lgrafo -Wl,-rpath=.

$(lib): grafos.o 
	$(CC) $(flags) -shared grafos.o -o $(lib)


grafos.o: grafos.cpp grafos.h
	$(CC) $(flags) -fPIC -c grafos.cpp -o grafos.o

run_main: $(exe)
	.\$(exe)

run: _grafo.pyd

clean:
	del *.o *.dll *.pyd *.cxx  $(exe).exe