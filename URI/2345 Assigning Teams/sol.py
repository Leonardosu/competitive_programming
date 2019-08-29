A, B, C, D = map(int, input().split())
lista = [A, B, C, D]

lista.sort();

diferença = abs(lista[3] + lista[0] - (lista[2] + lista[1]))
print(diferença)
