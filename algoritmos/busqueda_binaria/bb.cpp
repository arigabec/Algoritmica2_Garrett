#include <bits/stdc++.h> 
using namespace std; 
int n, x;
int A[10000];

bool f(int number){
    return number <= x;
}

void bs(){
    int ini =  0;
    int fin = n - 1;
    while(ini < fin){
        int mid = (ini + fin) / 2;
        if(f(A[mid])){
            ini = mid;
        } else {
            fin = mid - 1;
        }
    }
    if(f(A[ini])){
         cout << A[ini] << endl;
    } else {
        cout << "No existe el elemento" << endl;
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    cin >> x;
    bs();
    return 0;
}

/*6
3 4 7 11 13 15
7



Primer mayor a X

#include <bits/stdc++.h> 
using namespace std; 
int n, x;
int A[10000];

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
        cout << "No existe el elemento" << endl;
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    cin >> x;
    bs();
    return 0;
}
*/