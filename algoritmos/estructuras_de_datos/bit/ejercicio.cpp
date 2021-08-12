#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int BIT[10001];
int tamanhoVector;

void update(int posicion, int valor ) {
    for(;posicion <= tamanhoVector ;posicion += posicion&-posicion) {
        BIT[posicion] += valor;
    }
}

int query(int posicion){ // F(x) = 0+....+x 
    int result = 0 ;
    for(;posicion > 0 ;posicion -= posicion&-posicion) {
        result += BIT[posicion];
    }
    return result; 
}

int query2(int inicio, int final) {
    return query(final)-query(inicio-1);
}

int product (int inicio, int final){
    for(int i = inicio; i <= final; i++){
        BIT[i] *= BIT[i+1];
    }
    return BIT[final];
}

int main() {
    int K; 
    cin >> tamanhoVector>> K; 
    for(int i = 0; i < tamanhoVector; i++) {
        int x;
        cin >> x;
        update(i + 1, x);
    }
    /*for(int i = 0 ; i <= tamanhoVector; i++){
        cout<<"["<< BIT[i]<<"]"<<endl;
    }*/
    while(K--) {
        int n1, n2;
        string funcion;
        cin >> funcion >> n1 >> n2;
        if (funcion == "C"){
            update(n1, n2);
        } else {
            int result = product(n1, n2);
            if (result > 0){
                cout << "+";
            } else if (result == 0){
                cout << "0";
            } else if (result < 0){
                cout << "-";
            }
        }
    }
    cout << endl;
    return 0;
}