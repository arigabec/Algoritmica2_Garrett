#include <bits/stdc++.h> 
using namespace std; 
int n, x;
int A[1030];

void init(){
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            double p = pow(2, i) * pow(3, j);
            A[i] = p;
        }
    }
    sort(A[0], A[1024]);
}

bool f(int number){
    return number <= x;
}

void bs(){
    int ini =  0;
    int fin = n - 1;
    while(ini != fin){
        int mid = (ini + fin) / 2;
        if(f(A[mid])){
            ini = mid + 1;
        } else {
            fin = mid - 1;
        }
    }
    if(f(A[ini - 1])){
         cout << A[ini - 1] << endl;
    } else {
        return;
    }
}

int main(){
    init();
    while(scanf("%d", &x) == 1 && x){
        bs();
    }
}