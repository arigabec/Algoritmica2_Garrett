#include <bits/stdc++.h> 
using namespace std; 
int n = 1024;
int x;
double A[1030];

void init(){
    int cnt = -1;
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            double p = pow(2, i) * pow(3, j);
            A[cnt++] = p;
        }
    }
    sort(A, A + n);
}

bool f(double number) {
    return number >= x;
}

void bs() {
    int ini = 0;
    int fin = n - 1;
    while(ini <= fin) {
        int mid = (ini + fin) / 2;
        if(f(A[mid])) {
            fin = mid - 1;
        } else {
            ini = mid + 1;
        }
    }
    if(f(A[fin + 1])) {
        cout << A[fin + 1] << endl;
    }
}

int main(){
    while(scanf("%d", &x) == 1 && x){
    	init();
        bs();
    }
}