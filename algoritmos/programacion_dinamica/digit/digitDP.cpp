#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

string number = "307";
int dp[20][2][20][200];

// modificar el 3er parametro de acuerdo al problema

int solve_dp(int pos, int mayor,int pares, int suma) {
    if(pos > number.size()) { // cuando la posicion exceda al numero dado
        return 0;
    }
    // Modificar de acuerdo al problema
    if(pos == number.size()) {
        if(pares == 2) { // 
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[pos][mayor][pares][suma] == -1) { 
        int tope = 9;
        if(mayor == true) { 
            tope = number[pos]-'0'; 
        }
        dp[pos][mayor][pares][suma] = 0;
        for(int digito = 0; digito <= tope; digito++) {
            if(digito == tope ) {
                int total= suma +digito;
                int esPar = (total > 0) && (digito%2 == 0);
                dp[pos][mayor][pares][suma] += solve_dp(pos+1, true, pares + esPar, total );
            }
            else {
                int total = suma + digito;
                int esPar = (total > 0) && (digito%2 == 0);
                dp[pos][mayor][pares][suma] += solve_dp(pos+1, false, pares + esPar, total);
            }
        }
    }
    return dp[pos][mayor][pares][suma];
}

int main(){
    int  a = 1;
    int b = 10;
    // calculando f(a)
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(0, true, 0,0);
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    number = to_string(b);
    int pares_hasta_b = solve_dp(0, true, 0, 0);
    // total para f(a,b) = f(b) - f(a-1)
    cout<< pares_hasta_b - pares_hasta_a;
    return 0;
}