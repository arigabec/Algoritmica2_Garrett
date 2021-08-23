//SEGMENT TREE

#include <bits/stdc++.h>
#define MAX_N 100010
using namespace std; 

int n, a[MAX_N];

struct node{
    int sum, mult , min, max;
}segmentTree[MAX_N*2];

void init(int inicio, int final, int nodoActual) { 
    if( inicio == final ) {
        segmentTree[nodoActual].max = a[inicio];
        segmentTree[nodoActual].min = a[inicio];
        segmentTree[nodoActual].sum = a[inicio];
    } else {
        int mid = (inicio + final) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Ir por lado izquierdo
        init(inicio, mid, nodoIzquierdo );
        // Ir por lado derecho 
        init(mid+1, final, nodoDerecho);
        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);
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
            resultado.max = max(queryIzq.max, queryDer.max);
            resultado.min = min(queryIzq.min, queryDer.min);
            return resultado;
        }
    }
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio && posicion > final ) {
        return;
    }
    if( inicio == final ) {
        segmentTree[nodoActual].max = valor;
        segmentTree[nodoActual].min = valor;
        segmentTree[nodoActual].sum = valor;
    } else { 
        int mid = (inicio + final ) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Actualizar por lado izquierdo
        update(inicio, mid, nodoIzquierdo, posicion, valor );
        // Actualizar por lado derecho 
        update(mid+1, final, nodoDerecho, posicion, valor );
        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);

    }
}

int main() {
    cin >> n; 
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    int cases;
    cin >> cases;
    while(cases--){
        string op;
        cin >> op;
        if(op == "U"){
            int pos, val;
            cin >> pos >> val;
            update(0, n - 1, 0, pos, val);
        } else{
            int ini, fin;
            cin >> ini >> fin;
            cout << query(0, n - 1, 0, ini, fin).max << endl;
        }
    }
    return 0;
}


/*#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int tamanhoVector;
int numbers[];

struct node {
    // crear una variable por query
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
    cin >> tamanhoVector; 
    for(int i = 0; i < tamanhoVector; i++) {
        int x;
        cin >> x;
        numbers[i] = x;
    }
    int cases;
    cin >> cases;
    while(cases--){
        string op;
        cin >> op;
        if(op == "U"){
            int pos, val;
            cin >> pos >> val;
            //update(pos, val);
        } else{
            int ini, fin;
            cin >> ini >> fin;
            //cout << query2(ini, fin) << endl;
        }
    }
    return 0;
}

/*#include <bits/stdc++.h> 
using namespace std;

int BIT[10001];
int tamanhoVector;

void update(int posicion, int valor ) {
    for(;posicion <= tamanhoVector ;posicion += posicion&-posicion) {
        BIT[posicion] += valor;
    }
}

int query(int posicion){ 
    int result = 0 ;
    for(;posicion > 0 ; posicion -= posicion&-posicion) {
        result += max(BIT[posicion], BIT[posicion + 1]);
    }
    return result; 
}

int query2(int inicio, int final) {
    return query(final) - query(inicio - 1);
}

int main() {
    cin >> tamanhoVector; 
    for(int i = 0; i < tamanhoVector; i++) {
        int x;
        cin >> x;
        update(i + 1, x);
    }
    int cases;
    cin >> cases;
    while(cases--){
        string op;
        cin >> op;
        if(op == "U"){
            int pos, val;
            cin >> pos >> val;
            update(pos, val);
        } else{
            int ini, fin;
            cin >> ini >> fin;
            cout << query2(ini, fin) << endl;
        }
    }
    return 0;
}*/