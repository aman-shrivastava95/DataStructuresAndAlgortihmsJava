#include<bits/stdc++.h>
using namespace std ;

int binarySearch(int arr[],int start, int end,int key){
    int ans = -1 ;
    while(start <= end){
        int mid=(start+end)/2 ;
        if(arr[mid] == key){
            ans = mid ;
            break ;
        }else if(key > arr[mid]){
            start = mid+1 ;
        }else{
            start = mid-1 ;
        }
    }
    return ans ;
}
int main(int argc, char const *argv[])
{
    int arr[] = { 2, 3, 4, 10, 40,60,70,80 };
    int key = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, key);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
}
