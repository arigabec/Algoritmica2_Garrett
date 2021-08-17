#include <bits/stdc++.h>
using namespace std;

int esValido(int tablero[][], int fila, int columna){
    //Comprobamos que no existan reinas en la misma fila
    for (int col = 0; col < 8; col++){
        if(tablero[fila][col] == 1){
            return false;
        }
    }
    //Comprobamos diagonales izq superior
    int row = fila, col = columna;
    while(row > 0 && col > 0){
        if(tablero[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }
    //Comprobamos diagonales izq inferior
   row = fila, col = columna;
    while(row < 8 && col > 0 ){
        if(tablero[row][col] == 1){
            return false;
        }
        row++;
        col--;
    }
    return true;
}

void printSol(int tablero[][]){
    for (int row = 0; row < 8; row++){
        for (int column = 0; column < 8; column++){
            printf("[%d]", tablero[row][column]);
        }
        printf("\n");
    }
}

void solveQueen (int columna, int tablero [][]){
    if(columna > 8){
        printSol(tablero);
    }
    for (int row = 0; row < 8; row++){
        if(esValido(tablero, row, columna)){
            tablero[row][columna] = 1;
            solveQueen(columna + 1, tablero);
            tablero[row][columna] = 0;
        }
    }
}