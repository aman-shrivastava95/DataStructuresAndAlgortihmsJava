#include<bits/stdc++.h>
using namespace std ;


void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key = arr[i] ;//it is necessary to have this in a variable as
        //if we keep the key as index, the element at key changes while shifting right.
        int j = i-1 ;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j] ;
            j-- ;
        }
        arr[j+1] = key ;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    cout<<"insertion sort:"<<endl ;
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
    return 0;
}
