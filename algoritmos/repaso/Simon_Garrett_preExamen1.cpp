#include <bits/stdc++.h> 
using namespace std;

long long a = 10000000000;
int x;

bool bs() {
    long long ini = 0;
    long long fin = a - 1;
    while(ini <= fin) {
        long long mid = (ini + fin) / 2;
        if(mid*mid == x) {
        	return true;
        } else if (mid*mid > x){
            fin = mid - 1;
        } else {
        	ini = mid + 1;
        }
    }
    return false;
}

int main(){
    while(scanf("%d", &x) == 1 && x){
    	if(bs()){
    		cout << "true" << endl;
    	} else {
    		cout << "false" << endl;
    	}
    }
}