#include <bits/stdc++.h>
using namespace std;
int size, cont = 0;
char valor;

void solveIsla (string mapa[], int fila, int columna){
    if(fila >= 0 && fila < size && columna >= 0 && columna < size && mapa[fila][columna] == '1'){
        mapa[fila][columna] = '0';
        solveIsla(mapa, fila + 1, columna);
        solveIsla(mapa, fila - 1, columna);
        solveIsla(mapa, fila, columna + 1);
        solveIsla(mapa, fila, columna - 1);
        solveIsla(mapa, fila + 1, columna + 1);
        solveIsla(mapa, fila + 1, columna - 1);
        solveIsla(mapa, fila - 1, columna + 1);
        solveIsla(mapa, fila - 1, columna - 1);
    }
    return;
}

int main(){
    while(cin >> size){
        string mapa [size];
        for (int i = 0; i < size; i++){
            cin >> mapa[i];
        }
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if(mapa[i][j] == '1'){
                    cont++;
                    solveIsla(mapa, i, j);
                }
            }
        }
        cout << cont << endl;
        cont = 0;
    }
}