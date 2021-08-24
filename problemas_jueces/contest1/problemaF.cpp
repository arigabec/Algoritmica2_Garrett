//SEGMENT TREE

#include <bits/stdc++.h>
using namespace std;

int arr[100005], n, xx;

struct node{
    int max1 = 0;
    int max2 = 0;
};

node segmentTree[400000], zero, c;

void update(int ind, int i, int j, int s, int val){
    if(i > s || j < s){
        return;
    }
    if(i == j && i == s){
        segmentTree[ind].max1 = val;
        return;
    }
    int medio = (i + j) / 2;
    update(2*ind, i, medio, s, val);
    update(2*ind + 1, medio + 1, j, s, val);

    int mnode = min(segmentTree[2*ind].max1, segmentTree[2*ind+1].max1);
    segmentTree[ind].max1 = max(segmentTree[2*ind].max1, segmentTree[2*ind+1].max1);
    segmentTree[ind].max2 = max(mnode, max(segmentTree[2*ind].max2, segmentTree[2*ind+1].max2));

    if(segmentTree[ind].max2 == 0){
        segmentTree[ind].max2 = mnode;
    }
}

node query(int ind, int i, int j, int s, int e){
    node a, b;
    if(i > e || j < s){
        return zero;
    }
    if(i >= s && j <= e){
        return segmentTree[ind];
    }
    int medio = (i + j) / 2;
    a = query(2*ind, i, medio, s, e);
    b = query(2*ind + 1 , medio + 1, j, s, e);

    int mnode = min(a.max1, b.max1);
    c.max1 = max(a.max1, b.max1);
    c.max2 = max(mnode, max(a.max2, b.max2));
    return c;
}

int main(){
    int i, j, k, l, s, m, e;
    char ty;
    cin >> n;
    //init()
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(1, 1, n, i, arr[i]);
    }
    cin >> m;
    getchar();
    for(int i = 0; i < m; i++){
        cin >> ty >> s >> e;
        getchar();
        if(ty == 'U'){
            update(1, 1, n, s, e);
        } else {
            c = query(1, 1, n, s, e);
            cout << c.max1 + c.max2 << endl;
        }
    }
}