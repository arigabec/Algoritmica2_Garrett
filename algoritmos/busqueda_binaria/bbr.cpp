#include <bits/stdc++.h> 
using namespace std;

int bs(int arr[], int p, int r, int num) { 
   if (p <= r) { 
      int mid = (p + r)/2; 
      if (arr[mid] == num)  {
        return mid ; 
      }
      if (arr[mid] > num) {
        return bs(arr, p, mid-1, num);  
      }         
      if (arr[mid] < num){
        return bs(arr, mid+1, r, num); 
      }
    } 
   return -1; 
} 

int main(void) { 
    int arr[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40}; 
    int n = sizeof(arr)/ sizeof(arr[0]); 
    int num = 33; 
    int index = bs (arr, 0, n - 1, num); 
    if(index == -1){
        cout<< num <<" no existe";
    } else {
        cout<< num <<" está presente en la posición "<< index;
    }
    return 0; 
}