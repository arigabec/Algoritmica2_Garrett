#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int length[] = {1, 3, 5, 7};
int precios[] = {20, 15, 30, 50};
int dp[100000];

int solveDP(int tamanoBarra){
    if(tamanoBarra == 0){
        return 0;
    }
    if(dp[tamanoBarra] == -1){
        int gananciaMaxima = -1;
        for(int i = 0; i < 4; i++){
            if(tamanoBarra >= length[i]){
                gananciaMaxima = max(gananciaMaxima, precios[i] + solveDP(tamanoBarra - length[i]));
                
            } 
        }
        dp[tamanoBarra] = gananciaMaxima;
    }
    return dp[tamanoBarra];
}

int main(){
    memset(dp, -1, sizeof(dp));
    cout << solveDP(10) << endl;
}