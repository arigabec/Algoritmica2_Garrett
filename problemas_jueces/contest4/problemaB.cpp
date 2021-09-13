#include <bits/stdc++.h> 
using namespace std; 
int n = 1024;
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

bool f(int number, int x) {
    return number > x;
}

void bs(int x) {
    int ini = 0;
    int fin = n - 1;
    while(ini < fin) {
        int mid = (ini + fin) / 2;
        if(f(A[mid], x)) {
            fin = mid - 1 ;
        } else {
            ini = mid;
        }
    }
    if(f(A[fin], x)) {
        cout << A[fin] << endl;
    } else {
        cout << "No hay elementos mayores" << endl;
    }
}

int main(){
    int x;
	init();
    while(scanf("%d", &x) == 1 && x){
        bs(x);
    }
    return 0;
}