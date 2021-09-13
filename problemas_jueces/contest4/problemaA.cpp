#include <bits/stdc++.h>
using namespace std; 

void solve(string number, int size, int ones) {
    if(number.size() == size) {
        if(!ones){
            cout << number << endl;
        }
        return;
    }
    solve(number + "0", size, ones);
    solve(number + "1", size, ones - 1);
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int N, H;
        cin >> N >> H;
        solve("", N, H);
        if(cases){
			cout << endl;
        }
    }
    return 0;
}