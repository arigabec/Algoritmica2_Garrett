#include <bits/stdc++.h>
using namespace std;
unsigned int a[31270], s[31270];

void reset(){
    int i;
    a[1] = 1;
    s[1] = 1;
    for(i = 2; i < 31270; i++){
        a[i] = a[i-1] + (int)log10((double)i) + 1;
        s[i] = s[i-1] + a[i];
    }
}

int work(int n){
    int i = 1;
    int length = 0;
    while (s[i] < n){
        i++;
    }
    int pos = n - s[i-1];
    for (i = 1; length < pos; i++){
        length += (int)log10((double)i) + 1;
    }
    return ((i-1) / (int)pow((double)10, length - pos)) % 10;
}

int main(){
    int t;
    unsigned int n;
    reset();
    cin >> t;
    while(t--){
        cin >> n;
        cout << work(n) << endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
#define N 32000
unsigned  a[N];
unsigned s[N];
int main(){
int i;
 a[1]=s[1]=1;
for(i=2;i<N;i++){
a[i]=a[i-1]+(int)log10((double)i)+1;
s[i]=s[i-1]+a[i];
 }
int n,m,j,len,k;
 scanf("%d",&m);
 while(m--)
 {
scanf("%d",&n);
 j=1;
   while(s[j]<n)
         j++;   //Determine which group the nth position is in
  k=n-s[j-1];//  The index value of the nth position in the jth group
     len=0;
      for(i=1;len<k;i++)
        len+=(int)log10((double)i)+1;
      int num=(i-1)/(int)pow((double)10,len-k)%10; 
      printf("%d\n",num);
     }
     return 0;
 }
*/
