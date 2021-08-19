#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
string wordA, wordB;

int solve(int posA, int posB){
    if(posA == 0){
        return posB;
    }
    if(posB == 0){
        return posA;
    }

    int minimoEditDistance = 100000000;
    //editar el caracter
    int sonIguales = wordA[posA] != wordB[posB];
    minimoEditDistance = min(minimoEditDistance, solve(posA - 1, posB - 1) + sonIguales);
    //eliminar el caracter
    minimoEditDistance = min(minimoEditDistance, solve(posA - 1, posB) + 1);
    //aumentar el caracter
    minimoEditDistance = min(minimoEditDistance, solve(posA, posB - 1) + 1);
    return minimoEditDistance;
}

int main(){
    wordA = "ARIANE";
    wordB = "ANE";
    cout << solve(wordA.length() - 1, wordB.length() - 1);
    return 0;
}