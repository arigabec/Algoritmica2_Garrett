#include <bits/stdc++.h>
using namespace std;

int padre[10000];
int rango[10000];
int hijo[10000];

int n;
int m;
map<int,string> animales;
map<string,int> posicion;

void init() {
    for(int i=0;  i<= n; i++) {
        padre[i] = i;
        rango[i] = 0;
        hijo[i] = 1;
    }
}

int find(int x) {
    if(x == padre[x]) {
        return x;
    }
    else {
        padre[x] = find(padre[x]);
        return padre[x];
    }
}

void unionRango(int x,int y) { 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(xRaiz == yRaiz ){
        return;
    }
    if(rango[xRaiz] > rango[yRaiz]) {
        padre[yRaiz] = xRaiz;
        hijo[xRaiz] = hijo[xRaiz] + hijo[yRaiz];
    } else {
        padre[xRaiz] = yRaiz;
        hijo[yRaiz] = hijo[xRaiz] + hijo[yRaiz];
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

int main() {
    cin >> n; 
    while(n--) {
        for(int i = 1; i <= n;i++) {
            string nombre;
            cin >> nombre;
            animales[i] = nombre;
            posicion[nombre] = i;
        }
    } 
    init();
    while(m--) {
        string x, y;
        cin >> x >> y;
        unionRango(posicion[x],posicion[y]);
    }  
    string jugador;
    cin >> jugador;
    int pos = posicion[jugador];
    cout << hijo[padre[find(pos)]] << " compañeros" <<endl;
    return 0;
}