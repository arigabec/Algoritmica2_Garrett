#include<bits/stdc++.h>
using namespace std;

int sum[1000000];

struct node {
  int x;
  int h;
  int dp;
  int id;
} a[100000];

bool reverseSort(node node1,node node2){
  return node1.x > node2.x;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x,h;
        cin >> x >> h;
        a[i].x = x;
        a[i].h = h;
        a[i].id = i;
    }
    sort(a, a + n, reverseSort);
    for(int i = 0; i < n; i++){
        a[i].dp = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0;j -= a[j].dp){
            if(a[j].x > a[i].x + a[i].h - 1){
                break;
            }
            a[i].dp += a[j].dp;
        }
    }
    for(int i = 0; i < n; i++){
      sum[a[i].id] = a[i].dp;
    }
    for(int i = 0; i < n; i++){
        cout << sum[i] << " ";
    }
    return 0;
}