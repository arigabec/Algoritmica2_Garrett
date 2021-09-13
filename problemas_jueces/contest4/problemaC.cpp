#include <bits/stdc++.h>
using namespace std;

int padre[5005];
int rango[5005];

int n, m;
map<string,int> posicion;

void init() {
    for(int i = 0;  i < n; i++) {
        padre[i] = i;
        rango[i] = 1;
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
    if(xRaiz != yRaiz) {
        padre[xRaiz] = yRaiz;
        rango[yRaiz] += rango[xRaiz];
    }
}

int main() {
    while(scanf("%d %d", &n, &m) == 2 && n) {
        for(int i = 0; i < n;i++) {
            string animal;
            cin >> animal;
            posicion[animal] = i;
        }
        init();
        for (int i = 0; i < m; i++) {
            string x, y;
            cin >> x >> y;
            unionRango(posicion[x], posicion[y]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(rango[i] > ans){
                ans = rango[i];
            }
        }
        printf("%d\n", ans);
    } 
    return 0;
}