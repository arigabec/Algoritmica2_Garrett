#include <bits/stdc++.h> 
#define MAX_N 10000
using namespace std; 

int parent[MAX_N];
int rango[MAX_N];

//n: nro vertices, m: nro aristas
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
    double peso; 
    Arista(){}
    //sobrecarga del operador < para ordenar las asristas
    //sort
    bool operator <(const Arista &a) const {
        /*if(peso == a.peso){
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }*/
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

double distancia(double pointX1, double pointY1, double pointX2, double pointY2){
    // sqrt((x1-x2)^2 + (y1-y2)^2)
    double x = pointX2 - pointX1;
    double y = pointY2 - pointY1;
    return sqrt(x*x + y*y); 
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF) {
        for(int i = 0; i < m; i++) {
            scanf("%d %d %lf", &aristas[i].origen, &aristas[i].destino, &aristas[i].peso);
        }
        printf("%.2lf\n", kruskal(n,m));
        
        // Imprimo el arbol de expasion minimo
        for(int i = 0 ; i < numAristasArbol; i++) {
            cout << MST[i].origen << " " << MST[i].destino << " " << MST[i].peso << endl;
        }
    }
    return 0;
    
    /*int cases; 
    cin >> cases; 
    while(cases--) {
        cin >> n;
        int nroVertice = 0; 
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
            aristas[nroVertice].origen = i;
            aristas[nroVertice].destino = j;
            aristas[nroVertice].peso = distancia(points[0][i], points[1][i], points[0][j], points[1][j]); 
            nroVertice++;
            }
        }
        double total = kruskal(n, nroVertice);
        cout << total << endl;
    }*/
}