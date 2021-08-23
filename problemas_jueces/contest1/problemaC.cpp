//SEGMENT TREE

#include <bits/stdc++.h> 
using namespace std;
int n, r, l, ans, cnt;
char s[3005];

int main() {
    
    ans = cnt = r = l = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.' && r == 0){
            cnt++;
        }
        if(s[i] == 'L') {
            cnt = 0;
            r = 0;
        }
        if(s[i] == 'R') {
            ans += cnt;
            cnt = 0;
            r = 1;
        }
    }
    if(cnt > 0){
        ans += cnt;
        cnt = 0;
    }
    r = l = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R'){
            r = 1;
        }
        if(s[i] == 'L') {
            if(cnt % 2 == 1){
                ans++;
            }
            cnt = 0;
            r = 0;
        }
    }
    cout << ans;
    return 0;
}

/*int numbers[]  = {1,2,3,4,5,6,7,8};

struct node {
    int maximo;
    int minimo;
}segmentTree[1000000];

void init(int ini, int fin, int nodoActual) {
    if(ini == fin) {
        segmentTree[nodoActual].maximo = numbers[ini];
        segmentTree[nodoActual].minimo = numbers[ini];
    }
    else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        // Ir por el hijo Izq 
        init(ini, medio, hijoIzq);
        // Ir por el hijo Der
        init(medio + 1, fin, hijoDer);
        // Actualizar el nodo actual
        segmentTree[nodoActual].maximo = max(segmentTree[hijoIzq].maximo, segmentTree[hijoDer].maximo);
        segmentTree[nodoActual].minimo = max(segmentTree[hijoIzq].minimo, segmentTree[hijoDer].minimo);
    }
}

node query(int ini, int fin, int nodoActual, int i, int j) {
    if(ini >= i && fin <= j){ 
        return segmentTree[nodoActual];
    }
    else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        if ( j <= medio ) {
            return query(ini, medio, hijoIzq, i, j);
        }else if (i > medio){
            return query(medio+1,fin,hijoDer,i,j);
        } else {
            node queryIzq = query(ini,medio,hijoIzq,i,j);
            node queryDer = query(medio+1,fin,hijoDer,i,j);

            node resultado; 
            resultado.maximo = max(queryIzq.maximo, queryDer.maximo);
            resultado.minimo = min(queryIzq.minimo, queryDer.minimo);
            return resultado;
        }
    }
}

int main() {
    int n;
    cin >> n;
    init(0, n, 0);
    for(int i = 0; i < n; i++) {
        
        
    }
    return 0;
}*/