//BIT

#include <bits/stdc++.h> 
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
    for(;posicion > 0 ;posicion -= posicion&-posicion) {
        result += BIT[posicion];
    }
    return result; 
}

int query2(int inicio, int final) {
    return query(final)-query(inicio-1);
}

int main() {
    int size;
    cin >> size;
    for(int i = 0; i < size; i++) {
        int x;
        cin >> x;
        update(i + 1, x);
    }
    int cases;
    cin >> cases;
    while(cases--){
        int l, r;
        cin >> l >> r;
        cout << query2(l, r);
    }
    return 0;
}