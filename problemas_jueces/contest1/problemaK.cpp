#include <bits/stdc++.h> 
using namespace std;
int parent[105];
int rango[105];
int n;

void init() {
    for(int i = 0;  i <= n; i++) {
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

void unionRango(int x,int y) { 
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

int main() {
    int cases;
    cin >> cases;
    init();
    while(cases--) {
        cin >> n;
        while(n--){
            int x, y;
            cin >> x >> y; 
            unionRango(x,y);
        }
    }
    return 0;
}