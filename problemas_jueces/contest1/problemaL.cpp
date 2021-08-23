//UNION FIND

#include <bits/stdc++.h>
using namespace std;

int people;
int parent[20010];
int rango[20010];

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

int enemyID(int x) {
    return x + people;
}

int main() {
    cin >> people;
    while(people == 1) {
        init();
        int c, n, m;
        cin >> c >> n >> m;
        while (c && n && m == 3){
            if(c == 0 && n == 0 && m == 0){
                break;
            } 
            //setFriend()
            if(c == 1) {
                if(find(n) == find(enemyID(m)) || find(m) == find(enemyID(n))){
                    cout << "-1" << endl;
                } else {
                    unionRango(n, m);
                    unionRango(enemyID(n), enemyID(m));
                }
            
            // setEnemy()
            } else if(c == 2) { 
                if(find(n) == find(m) || find(enemyID(n)) == find(enemyID(m))){
                    cout << "-1" << endl;
                } else {
                    unionRango(n, enemyID(m));
                    unionRango(m, enemyID(n));
                }
            
            //areFriends()
            } else if(c == 3) {
                if(find(n) == find(m) || find(enemyID(n)) == find(enemyID(m))){
                    cout << "-1" << endl;
                } else {
                    cout << "0" << endl;
                }

            //areEnemies()
            } else {
                if(find(n) == find(enemyID(m)) || find(m) == find(enemyID(n))){
                    cout << "1" << endl;
                } else {
                    cout << "0" << endl;
                }
            }
        }
    }
    return 0;
}