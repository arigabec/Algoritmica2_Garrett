#include <bits/stdc++.h> 
#define MAX_N 10000
using namespace std; 

int parent[MAX_N];
int rango[MAX_N];

int n, m; 
int numAristasArbol;

void init() {
    for(int i=0;  i<= MAX_N; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA, int nodeB) {
    return find(nodeA) == find(nodeB);
}

void unionRango(int x, int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista {
    int origen;
    int destino; 
    double peso = 1; 
    Arista(){}
    //sobrecarga del operador < para ordenar las asristas
    //sort
    bool operator <(const Arista &a) const {
        return peso < a.peso;
    }
} aristas[MAX_N]; 

Arista MST[MAX_N]; // n-1 aristas 

double kruskal(int nroNodos, int nroAristas) {
    int origen, destino;
    double peso;
    double total = 0; //total del árbol de expansión mínimo
    numAristasArbol = 0; //contar nro de aristas

    init(); // Iniciar el Union Find
    
    sort(aristas, aristas + nroAristas);  // la arista con menor peso hasta la de mayor peso 

    for (int i = 0; i < nroAristas; i++){
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;
        if(!sameComponent(origen,destino)){ //estos 2 nodos forman un ciclo?
            total += peso;
            unionRango(origen,destino); //unimos los nodos
            MST[numAristasArbol] = aristas[i]; //guardamos la arista agregada
            numAristasArbol++;
        }
    }
    return total;
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF) {
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &aristas[i].origen, &aristas[i].destino);
        }
        printf("%.2lf\n", kruskal(n,m));
    }
    return 0;
}

/*
4 8
1 100 
1 102
1 103
2 100
2 105
3 200
3 203
4 103
*/