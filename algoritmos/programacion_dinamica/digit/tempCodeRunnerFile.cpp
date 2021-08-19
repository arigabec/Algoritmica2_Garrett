int solveDP(int pos, int mayor, int pares){
    //Posicion excede al número dado
    if(pos > number.size()){
        return 0;
    }

    //El numero tiene 2 pares?
    if(pos == number.size()){
        if(pares == 2){
            return 1;
        } else {
            return 0;
        }
        /*if(pares % pares == 1 && pares % 1 == pares){
            return 1;
        } else {
            return 0;
        }*/
    }

    //Pregunto si no lo he calculado antes
    if(dp[pos][mayor][pares] == -1){
        int tope = 9;
        if(mayor == true){
            tope = number[pos] - '0';
        }
        dp[pos][mayor][pares] = 0;
        for(int digito = 0; digito <= tope; digito++){
            if(digito == tope){
                dp[pos][mayor][pares] += solveDP(pos + 1, true, pares + digito % 2 == 0); 
            } else {
                dp[pos][mayor][pares] += solveDP(pos + 1, false, pares + digito % 2 == 0);
            }
        }
        /*for(int digito = 0; digito <= tope; digito++){
            if(digito == tope){
                dp[pos][mayor][pares] += solveDP(pos + 1, true, pares + digito); 
            } else {
                dp[pos][mayor][pares] += solveDP(pos + 1, false, pares + digito);
            }
        }*/
    }
    return dp[pos][mayor][pares] ;
}

int main() {
    int  a = 20;
    int b = 30;
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solveDP(0, true, 0);
    memset(dp, -1, sizeof(dp));
    number = to_string(b);
    int pares_hasta_b = solveDP(0, true, 0);
    cout<< pares_hasta_b - pares_hasta_a;
    return 0;
    /*memset(dp, -1, sizeof(dp));
    cout << solveDP(0, true, 0);
    return 0;*/
}