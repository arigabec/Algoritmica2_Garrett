#include <bits/stdc++.h> 
using namespace std; 
#include <bits/stdc++.h>
using namespace std;

int *st;

int gcd ( int a , int b ) {
    if(b == 0){
        return a;
    }
    return gcd (b, a % b );
}
  
int findGcd(int ss, int se, int qs, int qe, int si){
    if (ss > qe || se < qs){
        return 0;
    }
    if (qs <= ss && qe >= se){
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    return gcd(findGcd(ss, mid, qs, qe, si * 2 + 1), findGcd(mid + 1, se, qs, qe, si * 2 + 2));
}

int findGcdRange(int ss, int se, int arr[],int n){
    //En caso de que ingresemos números mayores o menores al tamaño del arreglo
    if (ss < 0 || se > n-1 || ss > se){
        cout << "No es valido" << endl;
        return -1;
    }
    return findGcd(0, n-1, ss, se, 0);
}
  
int construirST(int arr[], int ss, int se, int si){
    //Construimos el Segment Tree
    if (ss==se){
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss + ( se - ss ) / 2;
    st[si] = gcd(construirST(arr, ss, mid, si * 2 + 1), construirST(arr, mid + 1, se, si * 2 + 2));
    return st[si];
}

int *init(int arr[], int n){
    //Inicializamos el Segment Tree
   int peso = (int)(ceil(log2(n)));
   int size = 2*(int)pow(2, peso) - 1;
   st = new int[size];
   construirST(arr, 0, n - 1, 0);
   return st;
}

int main() {
    //Arreglo con los valores
    int a[] = {2, 4, 5, 3, 6, 9};
    //Tamaño del arreglo
    int n = sizeof(a)/sizeof(a[0]);
    init(a, n);
    //Rango del intérvalo a sacar el gcd
    int l = 4;
    int r = 6;
    cout << "GCD: "<< findGcdRange(l -1, r -1, a, n) << endl;
    return 0;
}