//UNION FIND

#include <bits/stdc++.h>
using namespace std;
#define p pair<int, char>

int parent[200010];
int rango[200010];

void init() {
    for(int i = 0;  i < 20010; i++) {
        parent[i] = i;
        rango[i] = 1;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        
        return parent[x];
    }
}

int unionRango(int x,int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(xRaiz != yRaiz){
        if(rango[xRaiz] > rango[yRaiz]) {
            parent[yRaiz] = xRaiz;
            rango[xRaiz] += rango[yRaiz];
        } else {
            parent[xRaiz] = yRaiz;
            rango[yRaiz] += rango[xRaiz];
        }
        return 1;
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        string s;
        cin >> s;
        int q, x, y;
        cin >> q;
        init();
        vector<p> v;
        for(int i = 1; i <= q; i++){
            cin >> x >> y;
            if(x == 2){
            	v.push_back(p(y, s[y]));
                s[y] = '#';
            } else {
                v.push_back(p(y, '0'));
            }
        }
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == '#'){
                continue;
            }
            if(s[i] == s[i + 1]){
                unionRango(i, i + 1);
            }
        }
        vector<int> result;
        for(int i = v.size() - 1; i >= 0; i--){
            int x = v[i].first;
            char ch = v[i].second;
            if(ch == '0'){
                int y = find(x);
                result.push_back(rango[y]);
            } else {
                s[x] = ch;
                if(x + 1 < s.size() && s[x] == s[x + 1]){
                    unionRango(x, x + 1);
                }
                if(x - 1 >= 0 && s[x] == s[x - 1]){
                    unionRango(x, x - 1);
                }
            }
        }
        reverse(result.begin(), result.end());
        cout << "Case " << i << ":" << endl;
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << endl;
        }
    }
    return 0;
}