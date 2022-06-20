import grafo as graf

#Funcion para construir frases dependiendo de una
#variable booleana.
#Transforma un false en "no ". Si es true, retorna un
#string vacio. 
def castellano(booleano):
    if not booleano:
        return "no "
    return ""

g=graf(3)
g.add_arco(1,2)
g.add_nodo()
g.add_arco(2,3)

print(castellano(g.hay_arco(2,1)) + "hay arco entre los nodos 2 y 1")
print(castellano(g.hay_camino(1,3)) + "hay camino entre los nodos 1 y 3")
print(castellano(g.hay_camino(0,3)) + "hay camino entre los nodos 0 y 3")
