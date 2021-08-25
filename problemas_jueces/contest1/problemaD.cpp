//SEGMENT TREE

/*#include <iostream>
using namespace std;

const int N = 300010; 
int n, m, x, y, z;
int a[N];

struct tree{
    int l, r;
    long long sum;
    bool v;
}tr[4*N];

bool vis[1000010];
int e[1000010], prim[N], cnt, d[1000010];

void get_prim(int n){
    d[1] = 1;
    for (int i = 2; i <= n; i++){
        if (!vis[i]){
            prim[cnt++] = i;
            d[i] = 2;
            e[i] = 1;
        }
        for (int j=1;j <= cnt && i*prim[j] <= n; j++){
            vis[prim[j]*i] = 1;
            if (i%prim[j] == 0){
                d[i*prim[j]] = d[i]/(e[i]+1)*(e[i]+2);
                e[i*prim[j]] = e[i]+1;
                break;
            } else{
                d[i*prim[j]] = d[i]*d[prim[j]];
                e[i*prim[j]] = 1;
            }
        }
    }
}

void update(int i){
    tr[i].sum = tr[i<<1].sum + tr[i<<1|1].sum;
    tr[i].v = (tr[i<<1].v&tr[i<<1|1].v);
}

void build(int i, int l, int r){
    tr[i].l = l,tr[i].r = r;
    if (l == r) {
        tr[i].sum = a[l];
        if(a[l] == 1 || a[l] == 2){
            tr[i].v = 1;
            return;
        }
    }
    int mid = l+r>>1;
    build(i<<1, l, mid);
    build(i<<1 | 1, mid+1,r);
    update(i);
}

void modify(int i, int l, int r){
    if (tr[i].v){
        return;
    }
    int L = tr[i].l, R = tr[i].r;
    if (l>R || L>r){
        return;
    }
    if (L == R){
        tr[i].sum  =d[tr[i].sum];
        if (tr[i].sum == 2){
            tr[i].v=1;
            return;
        }
    }
    modify(i<<1, l, r);
    modify(i<<1|1, l, r);
    update(i);
}

long long query(int i,int l,int r){
    int L = tr[i].l, R = tr[i].r;
    if (l>R || L>r){
        return 0;
    }
    if (l<=L && R<=r){
        return tr[i].sum;
    }
    long long ans = 0;
    ans += query(i<<1, l, r);
    ans += query(i<<1|1, l, r);
    return ans;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    get_prim(1000000);
    build(1, 1, n);
    for (int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        if (x == 1){
            modify(1, y, z);
        } else {
            cout << query(1,y,z) << endl;
        }
    }
}*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010

int n, a[MAX_N];

struct node{
    int sum, mult, min, max, div;
}segmentTree[MAX_N*2];

int div (int num){
    int cont = 0;
    for (int x = 1; x <= num; x++){
        if (num % x == 0){
            cont++;
        }
    }
    return cont;
}

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
        segmentTree[nodoActual].div = div(segmentTree[nodoIzquierdo].div + segmentTree[nodoDerecho].div);
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
        node result ; 
        result.max = max(maxIzquierdo.max, maxDerecho.max);
        result.min = min(maxIzquierdo.min, maxDerecho.min);
        result.div = div(segmentTree[nodoIzquierdo].div + segmentTree[nodoDerecho].div);
        return result;
    }      
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio && posicion > final ) {
        return ;
    }
    if( inicio == final ) {
        segmentTree[nodoActual].max = valor;
        segmentTree[nodoActual].min = valor;
        segmentTree[nodoActual].sum = valor;
        segmentTree[nodoActual].div = valor;
    } else { 
        int mid = (inicio + final ) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Actualizar por lado izquierdo
        update(inicio, mid, nodoIzquierdo, posicion, valor);
        // Actualizar por lado derecho 
        update(mid+1, final, nodoDerecho, posicion, valor);
        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);
        segmentTree[nodoActual].div = div(segmentTree[nodoIzquierdo].div + segmentTree[nodoDerecho].div);
    }
}

int main(){
    int size, cases;
    cin >> size >> cases;
    init(0, size, 0);
    for (int i = 0; i < size; i++){
        int n;
        cin >> n;
        update(0, size, 0, i, n);
    }
    while(cases--){
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 1){
            update(0, size, 0, a, b);
        } else {
            cout << query(0, size, 0, a, b).sum << endl;
        }
    }
}