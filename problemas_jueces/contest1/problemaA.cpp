//BIT

#include <bits/stdc++.h> 
using namespace std;

const int maxn = 100000+1000;
const int inf = 0x3f3f3f3f;

int gcd ( int a , int b ) {
    if(b == 0){
        return a;
    }
    return gcd (b, a % b );
}

struct node {
    int minv;
    int num;
    int gc;
} tree[maxn<<2];

void build(int rt, int l, int r) {
    if(l == r) {
        cin >> tree[rt].minv;
        tree[rt].num = 1;
        tree[rt].gc = tree[rt].minv;
        return;
    }
    int mid = (l+r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    if(tree[rt << 1].minv < tree[rt << 1 | 1].minv){
        tree[rt].minv = tree[rt << 1].minv;
        tree[rt].num = tree[rt << 1].num;
    } else if(tree[rt << 1].minv > tree[rt << 1 | 1].minv){
        tree[rt].minv = tree[rt << 1 | 1].minv;
        tree[rt].num = tree[rt << 1 | 1].num;
    } else {
        tree[rt].minv = tree[rt << 1].minv;
        tree[rt].num = tree[rt << 1].num + tree[rt << 1 | 1].num;
    }
    tree[rt].gc = gcd(tree[rt << 1].gc,tree[rt << 1 | 1].gc);
}

int minv, min_num, mgcd;

void query(int L, int R, int rt, int l, int r){
    if(L <= l && R >= r){
        if(minv > tree[rt].minv){
           minv = tree[rt].minv;
           min_num = tree[rt].num;
        } else if(minv==tree[rt].minv){
            min_num += tree[rt].num;
        }
        mgcd = gcd(mgcd, tree[rt].gc);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid){
        query(L, R, rt << 1, l, mid);
    }
    if(R > mid){
        query(L, R, rt << 1 | 1, mid + 1, r);
    }
}

int main(){
    int n;
    cin >> n,
    build(1, 1, n);
    int m,l,r;
    cin >> m;
    while(m--){
        cin >> l >> r;
        minv = inf;
        min_num = 0;
        mgcd = 0;
        query(l, r, 1, 1, n);
        if(minv == mgcd){
            cout << r - l + 1 - min_num << endl;
        } else {
            cout << r - l + 1 << endl;
        }
    }
    return 0;
}

/*#include <bits/stdc++.h> 
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
    if (ss < 0 || se > n-1 || ss > se){
        cout << "No es valido" << endl;
        return -1;
    }
    return findGcd(0, n-1, ss, se, 0);
}
  
int construirST(int arr[], int ss, int se, int si){
    if (ss==se){
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss + ( se - ss ) / 2;
    st[si] = gcd(construirST(arr, ss, mid, si * 2 + 1), construirST(arr, mid + 1, se, si * 2 + 2));
    return st[si];
}

int *init(int arr[], int n){
   int peso = (int)(ceil(log2(n)));
   int size = 2*(int)pow(2, peso) - 1;
   st = new int[size];
   construirST(arr, 0, n - 1, 0);
   return st;
}

int main() {
    int a[] = {2, 4, 5, 3, 6, 9};
    int n = sizeof(a)/sizeof(a[0]);
    init(a, n);
    int l = 4;
    int r = 6;
    cout << "GCD: "<< findGcdRange(l -1, r -1, a, n) << endl;
    return 0;
}*/