#include <bits/stdc++.h> 
#define MAX_N 100010
using namespace std; 
int n, a[MAX_N];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct node{
    int sum, mult , min, max, gcd;
}segmentTree[MAX_N*2];

void init(int inicio, int final, int nodoActual) { 
    if( inicio == final ) {
        segmentTree[nodoActual].max = a[inicio];
        segmentTree[nodoActual].min = a[inicio];
        segmentTree[nodoActual].sum = a[inicio];
        segmentTree[nodoActual].gcd = a[inicio];
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
        segmentTree[nodoActual].gcd = gcd(segmentTree[nodoIzquierdo].gcd, segmentTree[nodoDerecho].gcd);
    } 
}


node query(int inicio, int final, int nodoActual, int izquierda, int derecha ) {
    if(inicio >= izquierda && final <= derecha ) {
        return segmentTree[nodoActual];
    }
    int mid = (inicio + final ) / 2; 
    int nodoIzquierdo = 2 * nodoActual + 1; 
    int nodoDerecho   = 2 * nodoActual + 2;
    if(derecha <= mid ) {
        return query(inicio, mid, nodoIzquierdo, izquierda, derecha); 
    } else if(izquierda > mid) {
        return query(mid+1, final, nodoDerecho, izquierda, derecha);
    } else {
        node maxIzquierdo = query(inicio, mid, nodoIzquierdo,izquierda,derecha);
        node maxDerecho   = query(mid+1, final, nodoDerecho,izquierda,derecha);
        node result; 
        result.max = max(maxIzquierdo.max, maxDerecho.max);
        result.min = min(maxIzquierdo.min, maxDerecho.min); 
        result.gcd = gcd(maxIzquierdo.gcd, maxDerecho.gcd); 
        result.sum = maxIzquierdo.sum + maxDerecho.sum;
        return result;
    }      
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio || posicion > final ) {
        return ;
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
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max, segmentTree[nodoDerecho].max); 
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);  

    }
}

int main() {
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    init(0,n -1, 0);
    int izquierda, derecha; 
    cin>> izquierda >> derecha; 
    cout << "La suma de " << izquierda << " y " << derecha << " es: "<<query(0,n-1,0,izquierda,derecha).sum << endl;
    /*update(0,n-1,0,5,8);
    cout<<"El maximo de "<<0<<" y "<< 6 << " es: "<<query(0,n-1,0,0,6).max<<endl;*/
    return 0;
}
